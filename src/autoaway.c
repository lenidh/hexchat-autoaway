#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "autoaway_config.h"
#include "session-tracking.h"
#include "logging.h"
#include "hexchat-plugin.h"

#define PNAME "AutoAway"
#define PDESC "Automatically set away status depending on session state."

// hexchat plugin handle
static hexchat_plugin *ph;

static void on_session_event(int event) {
    switch(event) {
        case EVENT_SESSION_LOCK:;
            char message[256];
            hexchat_pluginpref_get_str(ph, "msg", message);
            hexchat_commandf(ph, "AWAY %s", message);
            break;
        case EVENT_SESSION_UNLOCK:
            hexchat_command(ph, "BACK");
            break;
    }
}

static int on_config_command(char *word[], char *word_eol[], void *userdate) {
    autoaway_log("Command: %s", word_eol[1]);
    char *option = word[2];
    if(strcasecmp(option, "MSG") == 0) {
        char *message = word_eol[3];
        if(message[0] == 0) { // if empty
            char current[256];
            hexchat_pluginpref_get_str(ph, "msg", current);
            hexchat_printf(ph, "AutoAway: current away message is '%s'", current);
        } else {
            hexchat_pluginpref_set_str(ph, "msg", message);
            autoaway_log("Away message changed to: %s", message);
            hexchat_printf(ph, "AutoAway: new away message is '%s'", message);
        }
    }
    return HEXCHAT_EAT_ALL;
}

void hexchat_plugin_get_info (char **name, char **desc, char **version, void **reserved) {
    *name = PNAME;
    *desc = PDESC;
    *version = AUTOAWAY_VERSION;
}


int hexchat_plugin_init(hexchat_plugin *plugin_handle, char **plugin_name, char **plugin_desc, char **plugin_version, char *arg) {
    autoaway_log("Load plugin");

    // we need to save this for use with any hexchat_* functions
    ph = plugin_handle;
    autoaway_init_log(ph);

    // tell HexChat our info
    *plugin_name = PNAME;
    *plugin_desc = PDESC;
    *plugin_version = AUTOAWAY_VERSION;

    // define configuration command
    hexchat_hook_command(ph, "AUTOAWAY", HEXCHAT_PRI_NORM, on_config_command, "Usage: AUTOAWAY MSG <message>, sets the message automatically send in reply to PRIVMSG", NULL);

    start_tracking_session(&on_session_event);

    return 1; // success
}

int hexchat_plugin_deinit() {
    autoaway_log("Unload plugin");
    stop_tracking_session();
    return 1; // success
}
