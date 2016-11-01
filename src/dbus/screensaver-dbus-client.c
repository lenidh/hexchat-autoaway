#include "screensaver-dbus.h"
#include "../session-tracking.h"
#include "../logging.h"

GThread * glib_thread;
GMainLoop * message_loop;

static void default_event_handler(int event) {}
static void (*session_event_handler)(int) = &default_event_handler;

static void on_active_changed(GDBusObjectProxy * proxy, gboolean active,
                              gpointer data) {
    autoaway_log("Received ActiveChanged signal from dbus. New state is %b",
                 active);
    int event = active ? EVENT_SESSION_LOCK : EVENT_SESSION_UNLOCK;
    (*session_event_handler)(event);
}

static AADBusGnomeScreenSaver * init_gnome_proxy() {
    GError * error = NULL;

    AADBusGnomeScreenSaver * proxy =
        aa_dbus_gnome_screen_saver_proxy_new_for_bus_sync(
            G_BUS_TYPE_SESSION, G_DBUS_PROXY_FLAGS_NONE,
            "org.gnome.ScreenSaver", "/org/gnome/ScreenSaver", NULL, &error);
    g_assert_no_error(error);

    g_signal_connect(proxy, "active-changed", G_CALLBACK(on_active_changed),
                     NULL);

    return proxy;
}

static AADBusFreedesktopScreenSaver * init_freedesktop_proxy() {
    GError * error = NULL;

    AADBusFreedesktopScreenSaver * proxy =
        aa_dbus_freedesktop_screen_saver_proxy_new_for_bus_sync(
            G_BUS_TYPE_SESSION, G_DBUS_PROXY_FLAGS_NONE,
            "org.freedesktop.ScreenSaver", "/org/freedesktop/ScreenSaver", NULL,
            &error);
    g_assert_no_error(error);

    g_signal_connect(proxy, "active-changed", G_CALLBACK(on_active_changed),
                     NULL);

    return proxy;
}

static gboolean on_thread_started(gpointer data) {
    autoaway_log("Message loop started. Notify main thread.");
    GMutex * m = (GMutex *)data;
    g_mutex_unlock(m);
    return FALSE; // do not call again
}

static gpointer thread_proc(gpointer data) {
    autoaway_log("Message loop thread started.");

    gpointer gnome_proxy = init_gnome_proxy();
    gpointer freedesktop_proxy = init_freedesktop_proxy();

    // To ensure our callback works as expected we have to use a custom context.
    GMainContext * ctx = g_main_context_new();

    // Add a callback that is called after the message loop started.
    GSource * src = g_idle_source_new();
    g_source_attach(src, ctx);
    g_source_set_callback(src, &on_thread_started, data, NULL);

    autoaway_log("Start message loop.");
    message_loop = g_main_loop_new(ctx, FALSE);
    g_main_loop_run(message_loop);

    g_main_loop_unref(message_loop);
    message_loop = NULL;
    g_source_destroy(src);
    g_source_unref(src);
    g_main_context_unref(ctx);
    g_object_unref(freedesktop_proxy);
    g_object_unref(gnome_proxy);

    autoaway_log("Message loop quitted. Stop message loop thread.");
    return NULL;
}

void start_tracking_session(void (*event_handler)(int)) {
    if(glib_thread == NULL) {
        autoaway_log("Start session tracking.");
        // A mutex is used to wait until the message loop started. The mutex is
        // locked before the message loop thread is created. The mutex is locked
        // again after the message loop thread was created. That will cause this
        // function to be blocked until the mutex is unlocked by the message
        // loop thread.
        GMutex m;
        g_mutex_init(&m);
        g_mutex_lock(&m);
        autoaway_log("Start message loop thread.");
        glib_thread = g_thread_new(NULL, &thread_proc, &m);
        if(glib_thread == NULL) {
            autoaway_log("Error: Unable to start message loop thread");
        } else {
            session_event_handler = event_handler;
            autoaway_log("Wait for message loop...");
            g_mutex_lock(&m);
            autoaway_log("Received notification from message loop. Continue "
                         "main thread.");
        }
        g_mutex_unlock(&m);
        g_mutex_clear(&m);
    }
}

void stop_tracking_session() {
    if(glib_thread != NULL) {
        autoaway_log("Stop session tracking.");
        session_event_handler = &default_event_handler;
        if(message_loop != NULL) {
            autoaway_log("Shutdown message loop.");
            g_main_loop_quit(message_loop);
        }
        autoaway_log("Wait for message loop thread to join...");
        g_thread_join(glib_thread); // will unref glib_thread
        autoaway_log("Message loop joined. Continue main thread.");
        glib_thread = NULL;
    }
}
