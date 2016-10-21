#ifndef PREFS_H
#define PREFS_H

typedef struct _hexchat_plugin hexchat_plugin;

// Specifies the size of a buffer that is sufficient to hold the longest plugin
// preference value (including the terminating 0 char) supported by hexchat.
// Determined from hexchat source commons/plugin.c and commons/util.c
#define STR_PREF_BUFFER_SIZE 512

int autoaway_get_pref_msg(hexchat_plugin * ph, char * dest);

int autoaway_set_pref_msg(hexchat_plugin * ph, const char * value);

#endif // PREFS_H