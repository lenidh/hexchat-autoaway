#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "logging.h"
#include "hexchat-plugin.h"

#define PNAME "AutoAway"
#define PDESC "Automatically set away status depending on session state."
#define PVERSION "0.2"

// hexchat plugin handle
static hexchat_plugin *ph;

void autoaway_set_away() {
    char message[256];
    hexchat_pluginpref_get_str(ph, "msg", message);
    hexchat_commandf(ph, "AWAY %s", message);
}

void autoaway_unset_away() {
    hexchat_command(ph, "BACK");
}

static int on_config_command(char *word[], char *word_eol[], void *userdate) {
    autoaway_log("configuration command");
    char *option = word[2];
    if(strcasecmp(option, "MSG") == 0) {
        char *message = word_eol[3];
        if(message[0] == 0) { // if empty
            char current[256];
            hexchat_pluginpref_get_str(ph, "msg", current);
            hexchat_printf(ph, "AutoAway: current away message is '%s'", current);
        } else {
            hexchat_pluginpref_set_str(ph, "msg", message);
            hexchat_printf(ph, "AutoAway: new away message is '%s'", message);
        }
    }
    return HEXCHAT_EAT_ALL;
}

void hexchat_plugin_get_info (char **name, char **desc, char **version, void **reserved) {
    *name = PNAME;
    *desc = PDESC;
    *version = PVERSION;
}


int hexchat_plugin_init(hexchat_plugin *plugin_handle, char **plugin_name, char **plugin_desc, char **plugin_version, char *arg) {
    autoaway_log("Initialize HexChat plugin...");

    // we need to save this for use with any hexchat_* functions
    ph = plugin_handle;
    autoaway_init_log(ph);

    // tell HexChat our info
    *plugin_name = PNAME;
    *plugin_desc = PDESC;
    *plugin_version = PVERSION;

    // define configuration command
    hexchat_hook_command(ph, "AUTOAWAY", HEXCHAT_PRI_NORM, on_config_command, "Usage: AUTOAWAY MSG <message>, sets the message automatically send in reply to PRIVMSG", NULL);

    return 1; // success
}