#include <string.h>
#include "prefs.h"
#include "logging.h"
#include "hexchat-plugin.h"

static int get_str_pref(hexchat_plugin * ph, const char * key,
                        const char * default_value, char * dest) {
    int success = hexchat_pluginpref_get_str(ph, key, dest);
    if(!success) { strncpy(dest, default_value, STR_PREF_BUFFER_SIZE - 1); }
    return success;
}

static int set_str_pref(hexchat_plugin * ph, const char * key,
                        const char * value) {

    int success = hexchat_pluginpref_set_str(ph, key, value);
    if(!success) {
        autoaway_log("Error: Failed to save setting: %s = %s", key, value);
    }
    return success;
}

int autoaway_get_pref_msg(hexchat_plugin * ph, char * dest) {
    return get_str_pref(ph, "msg", "", dest);
}

int autoaway_set_pref_msg(hexchat_plugin * ph, const char * value) {
    return set_str_pref(ph, "msg", value);
}