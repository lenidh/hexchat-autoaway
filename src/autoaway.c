#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "autoaway_config.h"
#include "session-tracking.h"
#include "logging.h"
#include "prefs.h"
#include "hexchat-plugin.h"

#define PNAME "AutoAway"
#define PDESC "Automatically set away status depending on session state."

// hexchat plugin handle
static hexchat_plugin * ph;

static void on_session_event(int event) {
    switch(event) {
        case EVENT_SESSION_LOCK:;
            char message[STR_PREF_BUFFER_SIZE];
            autoaway_get_pref_msg(ph, message);
            if(strlen(message) == 0) {
                // TODO: get default away message
                strcpy(message, "I'm busy'");
            }
            hexchat_commandf(ph, "AWAY %s", message);
            break;
        case EVENT_SESSION_UNLOCK:
            hexchat_command(ph, "BACK");
            break;
    }
}

static int on_config_command(char * word[], char * word_eol[],
                             void * userdate) {
    autoaway_log("Command: %s", word_eol[1]);
    char * option = word[2];
    if(strcasecmp(option, "MSG") == 0) {
        char * message = word_eol[3];
        if(message[0] == 0) { // if empty
            char current[STR_PREF_BUFFER_SIZE];
            autoaway_get_pref_msg(ph, current);
            if(strlen(current) == 0) {
                hexchat_printf(ph,
                               "AutoAway: No custom away message set. Default "
                               "away message will be used.");
            } else {
                hexchat_printf(ph, "AutoAway: Current away message is '%s'",
                               current);
            }
        } else {
            autoaway_set_pref_msg(ph, message);
            autoaway_log("Away message changed to: %s", message);
            hexchat_printf(ph, "AutoAway: New away message is '%s'", message);
        }
    }
    return HEXCHAT_EAT_ALL;
}

void hexchat_plugin_get_info(char ** name, char ** desc, char ** version,
                             void ** reserved) {
    *name = PNAME;
    *desc = PDESC;
    *version = AUTOAWAY_VERSION;
}

int hexchat_plugin_init(hexchat_plugin * plugin_handle, char ** plugin_name,
                        char ** plugin_desc, char ** plugin_version,
                        char * arg) {
    autoaway_log("Load plugin");

    // we need to save this for use with any hexchat_* functions
    ph = plugin_handle;

    // tell HexChat our info
    *plugin_name = PNAME;
    *plugin_desc = PDESC;
    *plugin_version = AUTOAWAY_VERSION;

    // define configuration command
    hexchat_hook_command(ph, "AUTOAWAY", HEXCHAT_PRI_NORM, on_config_command,
                         "Usage: AUTOAWAY MSG <message>, sets the message "
                         "automatically send in reply to PRIVMSG",
                         NULL);

    start_tracking_session(&on_session_event);

    hexchat_print(ph, "AutoAway plugin loaded\n");
    return 1; // success
}

int hexchat_plugin_deinit() {
    autoaway_log("Unload plugin");
    stop_tracking_session();
    return 1; // success
}
