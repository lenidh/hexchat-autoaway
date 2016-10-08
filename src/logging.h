#ifndef LOGGING_H
#define LOGGING_H

typedef struct _hexchat_plugin hexchat_plugin;

void autoaway_init_log(hexchat_plugin *plugin_handle);
void autoaway_log(const char* msg);

#endif // LOGGING_H