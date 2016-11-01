/*
 * Generated by gdbus-codegen 2.50.1. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __SCREENSAVER_DBUS_H__
#define __SCREENSAVER_DBUS_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.gnome.ScreenSaver */

#define AA_DBUS_TYPE_GNOME_SCREEN_SAVER (aa_dbus_gnome_screen_saver_get_type ())
#define AA_DBUS_GNOME_SCREEN_SAVER(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_GNOME_SCREEN_SAVER, AADBusGnomeScreenSaver))
#define AA_DBUS_IS_GNOME_SCREEN_SAVER(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_GNOME_SCREEN_SAVER))
#define AA_DBUS_GNOME_SCREEN_SAVER_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), AA_DBUS_TYPE_GNOME_SCREEN_SAVER, AADBusGnomeScreenSaverIface))

struct _AADBusGnomeScreenSaver;
typedef struct _AADBusGnomeScreenSaver AADBusGnomeScreenSaver;
typedef struct _AADBusGnomeScreenSaverIface AADBusGnomeScreenSaverIface;

struct _AADBusGnomeScreenSaverIface
{
  GTypeInterface parent_iface;

  void (*active_changed) (
    AADBusGnomeScreenSaver *object,
    gboolean arg_active);

};

GType aa_dbus_gnome_screen_saver_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *aa_dbus_gnome_screen_saver_interface_info (void);
guint aa_dbus_gnome_screen_saver_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus signal emissions functions: */
void aa_dbus_gnome_screen_saver_emit_active_changed (
    AADBusGnomeScreenSaver *object,
    gboolean arg_active);



/* ---- */

#define AA_DBUS_TYPE_GNOME_SCREEN_SAVER_PROXY (aa_dbus_gnome_screen_saver_proxy_get_type ())
#define AA_DBUS_GNOME_SCREEN_SAVER_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_PROXY, AADBusGnomeScreenSaverProxy))
#define AA_DBUS_GNOME_SCREEN_SAVER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_PROXY, AADBusGnomeScreenSaverProxyClass))
#define AA_DBUS_GNOME_SCREEN_SAVER_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_PROXY, AADBusGnomeScreenSaverProxyClass))
#define AA_DBUS_IS_GNOME_SCREEN_SAVER_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_PROXY))
#define AA_DBUS_IS_GNOME_SCREEN_SAVER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_PROXY))

typedef struct _AADBusGnomeScreenSaverProxy AADBusGnomeScreenSaverProxy;
typedef struct _AADBusGnomeScreenSaverProxyClass AADBusGnomeScreenSaverProxyClass;
typedef struct _AADBusGnomeScreenSaverProxyPrivate AADBusGnomeScreenSaverProxyPrivate;

struct _AADBusGnomeScreenSaverProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  AADBusGnomeScreenSaverProxyPrivate *priv;
};

struct _AADBusGnomeScreenSaverProxyClass
{
  GDBusProxyClass parent_class;
};

GType aa_dbus_gnome_screen_saver_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (AADBusGnomeScreenSaverProxy, g_object_unref)
#endif

void aa_dbus_gnome_screen_saver_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
AADBusGnomeScreenSaver *aa_dbus_gnome_screen_saver_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
AADBusGnomeScreenSaver *aa_dbus_gnome_screen_saver_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void aa_dbus_gnome_screen_saver_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
AADBusGnomeScreenSaver *aa_dbus_gnome_screen_saver_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
AADBusGnomeScreenSaver *aa_dbus_gnome_screen_saver_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define AA_DBUS_TYPE_GNOME_SCREEN_SAVER_SKELETON (aa_dbus_gnome_screen_saver_skeleton_get_type ())
#define AA_DBUS_GNOME_SCREEN_SAVER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_SKELETON, AADBusGnomeScreenSaverSkeleton))
#define AA_DBUS_GNOME_SCREEN_SAVER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_SKELETON, AADBusGnomeScreenSaverSkeletonClass))
#define AA_DBUS_GNOME_SCREEN_SAVER_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_SKELETON, AADBusGnomeScreenSaverSkeletonClass))
#define AA_DBUS_IS_GNOME_SCREEN_SAVER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_SKELETON))
#define AA_DBUS_IS_GNOME_SCREEN_SAVER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), AA_DBUS_TYPE_GNOME_SCREEN_SAVER_SKELETON))

typedef struct _AADBusGnomeScreenSaverSkeleton AADBusGnomeScreenSaverSkeleton;
typedef struct _AADBusGnomeScreenSaverSkeletonClass AADBusGnomeScreenSaverSkeletonClass;
typedef struct _AADBusGnomeScreenSaverSkeletonPrivate AADBusGnomeScreenSaverSkeletonPrivate;

struct _AADBusGnomeScreenSaverSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  AADBusGnomeScreenSaverSkeletonPrivate *priv;
};

struct _AADBusGnomeScreenSaverSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType aa_dbus_gnome_screen_saver_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (AADBusGnomeScreenSaverSkeleton, g_object_unref)
#endif

AADBusGnomeScreenSaver *aa_dbus_gnome_screen_saver_skeleton_new (void);


/* ------------------------------------------------------------------------ */
/* Declarations for org.freedesktop.ScreenSaver */

#define AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER (aa_dbus_freedesktop_screen_saver_get_type ())
#define AA_DBUS_FREEDESKTOP_SCREEN_SAVER(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER, AADBusFreedesktopScreenSaver))
#define AA_DBUS_IS_FREEDESKTOP_SCREEN_SAVER(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER))
#define AA_DBUS_FREEDESKTOP_SCREEN_SAVER_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER, AADBusFreedesktopScreenSaverIface))

struct _AADBusFreedesktopScreenSaver;
typedef struct _AADBusFreedesktopScreenSaver AADBusFreedesktopScreenSaver;
typedef struct _AADBusFreedesktopScreenSaverIface AADBusFreedesktopScreenSaverIface;

struct _AADBusFreedesktopScreenSaverIface
{
  GTypeInterface parent_iface;

  void (*active_changed) (
    AADBusFreedesktopScreenSaver *object,
    gboolean arg_active);

};

GType aa_dbus_freedesktop_screen_saver_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *aa_dbus_freedesktop_screen_saver_interface_info (void);
guint aa_dbus_freedesktop_screen_saver_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus signal emissions functions: */
void aa_dbus_freedesktop_screen_saver_emit_active_changed (
    AADBusFreedesktopScreenSaver *object,
    gboolean arg_active);



/* ---- */

#define AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_PROXY (aa_dbus_freedesktop_screen_saver_proxy_get_type ())
#define AA_DBUS_FREEDESKTOP_SCREEN_SAVER_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_PROXY, AADBusFreedesktopScreenSaverProxy))
#define AA_DBUS_FREEDESKTOP_SCREEN_SAVER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_PROXY, AADBusFreedesktopScreenSaverProxyClass))
#define AA_DBUS_FREEDESKTOP_SCREEN_SAVER_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_PROXY, AADBusFreedesktopScreenSaverProxyClass))
#define AA_DBUS_IS_FREEDESKTOP_SCREEN_SAVER_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_PROXY))
#define AA_DBUS_IS_FREEDESKTOP_SCREEN_SAVER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_PROXY))

typedef struct _AADBusFreedesktopScreenSaverProxy AADBusFreedesktopScreenSaverProxy;
typedef struct _AADBusFreedesktopScreenSaverProxyClass AADBusFreedesktopScreenSaverProxyClass;
typedef struct _AADBusFreedesktopScreenSaverProxyPrivate AADBusFreedesktopScreenSaverProxyPrivate;

struct _AADBusFreedesktopScreenSaverProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  AADBusFreedesktopScreenSaverProxyPrivate *priv;
};

struct _AADBusFreedesktopScreenSaverProxyClass
{
  GDBusProxyClass parent_class;
};

GType aa_dbus_freedesktop_screen_saver_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (AADBusFreedesktopScreenSaverProxy, g_object_unref)
#endif

void aa_dbus_freedesktop_screen_saver_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
AADBusFreedesktopScreenSaver *aa_dbus_freedesktop_screen_saver_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
AADBusFreedesktopScreenSaver *aa_dbus_freedesktop_screen_saver_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void aa_dbus_freedesktop_screen_saver_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
AADBusFreedesktopScreenSaver *aa_dbus_freedesktop_screen_saver_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
AADBusFreedesktopScreenSaver *aa_dbus_freedesktop_screen_saver_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_SKELETON (aa_dbus_freedesktop_screen_saver_skeleton_get_type ())
#define AA_DBUS_FREEDESKTOP_SCREEN_SAVER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_SKELETON, AADBusFreedesktopScreenSaverSkeleton))
#define AA_DBUS_FREEDESKTOP_SCREEN_SAVER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_SKELETON, AADBusFreedesktopScreenSaverSkeletonClass))
#define AA_DBUS_FREEDESKTOP_SCREEN_SAVER_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_SKELETON, AADBusFreedesktopScreenSaverSkeletonClass))
#define AA_DBUS_IS_FREEDESKTOP_SCREEN_SAVER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_SKELETON))
#define AA_DBUS_IS_FREEDESKTOP_SCREEN_SAVER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), AA_DBUS_TYPE_FREEDESKTOP_SCREEN_SAVER_SKELETON))

typedef struct _AADBusFreedesktopScreenSaverSkeleton AADBusFreedesktopScreenSaverSkeleton;
typedef struct _AADBusFreedesktopScreenSaverSkeletonClass AADBusFreedesktopScreenSaverSkeletonClass;
typedef struct _AADBusFreedesktopScreenSaverSkeletonPrivate AADBusFreedesktopScreenSaverSkeletonPrivate;

struct _AADBusFreedesktopScreenSaverSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  AADBusFreedesktopScreenSaverSkeletonPrivate *priv;
};

struct _AADBusFreedesktopScreenSaverSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType aa_dbus_freedesktop_screen_saver_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (AADBusFreedesktopScreenSaverSkeleton, g_object_unref)
#endif

AADBusFreedesktopScreenSaver *aa_dbus_freedesktop_screen_saver_skeleton_new (void);


/* ---- */

#define AA_DBUS_TYPE_OBJECT (aa_dbus_object_get_type ())
#define AA_DBUS_OBJECT(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_OBJECT, AADBusObject))
#define AA_DBUS_IS_OBJECT(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_OBJECT))
#define AA_DBUS_OBJECT_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), AA_DBUS_TYPE_OBJECT, AADBusObject))

struct _AADBusObject;
typedef struct _AADBusObject AADBusObject;
typedef struct _AADBusObjectIface AADBusObjectIface;

struct _AADBusObjectIface
{
  GTypeInterface parent_iface;
};

GType aa_dbus_object_get_type (void) G_GNUC_CONST;

AADBusGnomeScreenSaver *aa_dbus_object_get_gnome_screen_saver (AADBusObject *object);
AADBusFreedesktopScreenSaver *aa_dbus_object_get_freedesktop_screen_saver (AADBusObject *object);
AADBusGnomeScreenSaver *aa_dbus_object_peek_gnome_screen_saver (AADBusObject *object);
AADBusFreedesktopScreenSaver *aa_dbus_object_peek_freedesktop_screen_saver (AADBusObject *object);

#define AA_DBUS_TYPE_OBJECT_PROXY (aa_dbus_object_proxy_get_type ())
#define AA_DBUS_OBJECT_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_OBJECT_PROXY, AADBusObjectProxy))
#define AA_DBUS_OBJECT_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), AA_DBUS_TYPE_OBJECT_PROXY, AADBusObjectProxyClass))
#define AA_DBUS_OBJECT_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), AA_DBUS_TYPE_OBJECT_PROXY, AADBusObjectProxyClass))
#define AA_DBUS_IS_OBJECT_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_OBJECT_PROXY))
#define AA_DBUS_IS_OBJECT_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), AA_DBUS_TYPE_OBJECT_PROXY))

typedef struct _AADBusObjectProxy AADBusObjectProxy;
typedef struct _AADBusObjectProxyClass AADBusObjectProxyClass;
typedef struct _AADBusObjectProxyPrivate AADBusObjectProxyPrivate;

struct _AADBusObjectProxy
{
  /*< private >*/
  GDBusObjectProxy parent_instance;
  AADBusObjectProxyPrivate *priv;
};

struct _AADBusObjectProxyClass
{
  GDBusObjectProxyClass parent_class;
};

GType aa_dbus_object_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (AADBusObjectProxy, g_object_unref)
#endif

AADBusObjectProxy *aa_dbus_object_proxy_new (GDBusConnection *connection, const gchar *object_path);

#define AA_DBUS_TYPE_OBJECT_SKELETON (aa_dbus_object_skeleton_get_type ())
#define AA_DBUS_OBJECT_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_OBJECT_SKELETON, AADBusObjectSkeleton))
#define AA_DBUS_OBJECT_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), AA_DBUS_TYPE_OBJECT_SKELETON, AADBusObjectSkeletonClass))
#define AA_DBUS_OBJECT_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), AA_DBUS_TYPE_OBJECT_SKELETON, AADBusObjectSkeletonClass))
#define AA_DBUS_IS_OBJECT_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_OBJECT_SKELETON))
#define AA_DBUS_IS_OBJECT_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), AA_DBUS_TYPE_OBJECT_SKELETON))

typedef struct _AADBusObjectSkeleton AADBusObjectSkeleton;
typedef struct _AADBusObjectSkeletonClass AADBusObjectSkeletonClass;
typedef struct _AADBusObjectSkeletonPrivate AADBusObjectSkeletonPrivate;

struct _AADBusObjectSkeleton
{
  /*< private >*/
  GDBusObjectSkeleton parent_instance;
  AADBusObjectSkeletonPrivate *priv;
};

struct _AADBusObjectSkeletonClass
{
  GDBusObjectSkeletonClass parent_class;
};

GType aa_dbus_object_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (AADBusObjectSkeleton, g_object_unref)
#endif

AADBusObjectSkeleton *aa_dbus_object_skeleton_new (const gchar *object_path);
void aa_dbus_object_skeleton_set_gnome_screen_saver (AADBusObjectSkeleton *object, AADBusGnomeScreenSaver *interface_);
void aa_dbus_object_skeleton_set_freedesktop_screen_saver (AADBusObjectSkeleton *object, AADBusFreedesktopScreenSaver *interface_);

/* ---- */

#define AA_DBUS_TYPE_OBJECT_MANAGER_CLIENT (aa_dbus_object_manager_client_get_type ())
#define AA_DBUS_OBJECT_MANAGER_CLIENT(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), AA_DBUS_TYPE_OBJECT_MANAGER_CLIENT, AADBusObjectManagerClient))
#define AA_DBUS_OBJECT_MANAGER_CLIENT_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), AA_DBUS_TYPE_OBJECT_MANAGER_CLIENT, AADBusObjectManagerClientClass))
#define AA_DBUS_OBJECT_MANAGER_CLIENT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), AA_DBUS_TYPE_OBJECT_MANAGER_CLIENT, AADBusObjectManagerClientClass))
#define AA_DBUS_IS_OBJECT_MANAGER_CLIENT(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), AA_DBUS_TYPE_OBJECT_MANAGER_CLIENT))
#define AA_DBUS_IS_OBJECT_MANAGER_CLIENT_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), AA_DBUS_TYPE_OBJECT_MANAGER_CLIENT))

typedef struct _AADBusObjectManagerClient AADBusObjectManagerClient;
typedef struct _AADBusObjectManagerClientClass AADBusObjectManagerClientClass;
typedef struct _AADBusObjectManagerClientPrivate AADBusObjectManagerClientPrivate;

struct _AADBusObjectManagerClient
{
  /*< private >*/
  GDBusObjectManagerClient parent_instance;
  AADBusObjectManagerClientPrivate *priv;
};

struct _AADBusObjectManagerClientClass
{
  GDBusObjectManagerClientClass parent_class;
};

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (AADBusObjectManagerClient, g_object_unref)
#endif

GType aa_dbus_object_manager_client_get_type (void) G_GNUC_CONST;

GType aa_dbus_object_manager_client_get_proxy_type (GDBusObjectManagerClient *manager, const gchar *object_path, const gchar *interface_name, gpointer user_data);

void aa_dbus_object_manager_client_new (
    GDBusConnection        *connection,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GAsyncReadyCallback     callback,
    gpointer                user_data);
GDBusObjectManager *aa_dbus_object_manager_client_new_finish (
    GAsyncResult        *res,
    GError             **error);
GDBusObjectManager *aa_dbus_object_manager_client_new_sync (
    GDBusConnection        *connection,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GError                **error);

void aa_dbus_object_manager_client_new_for_bus (
    GBusType                bus_type,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GAsyncReadyCallback     callback,
    gpointer                user_data);
GDBusObjectManager *aa_dbus_object_manager_client_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
GDBusObjectManager *aa_dbus_object_manager_client_new_for_bus_sync (
    GBusType                bus_type,
    GDBusObjectManagerClientFlags  flags,
    const gchar            *name,
    const gchar            *object_path,
    GCancellable           *cancellable,
    GError                **error);


G_END_DECLS

#endif /* __SCREENSAVER_DBUS_H__ */
