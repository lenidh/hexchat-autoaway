#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "logging.h"
#include "msg_buffer.h"
#include "hexchat-plugin.h"

#define LOGFILE "/logs/AutoAway.log"

// hexchat plugin handle
static hexchat_plugin *ph = NULL;

static autoaway_msg_buffer msg_buffer = NULL;

static char* get_log_path() {
    if(ph == NULL) return NULL;
    const char* config_path = hexchat_get_info(ph, "configdir");
    size_t pathlen = strlen(config_path) + strlen(LOGFILE) + 1;
    char* path = malloc(pathlen * sizeof(char));
    strcat(strcpy(path, config_path), LOGFILE);
    return path;
}

static void append_msg(const char* path, const char* msg) {
    FILE* file = fopen(path, "a");
    if(file != NULL) {
        fprintf(file, "%s\n", msg);
        fclose(file);
    }
}

static void flush_buffer(const char* path) {
    const char* msg;
    while((msg = autoaway_msg_buffer_dequeue(msg_buffer)) != NULL) {
        append_msg(path, msg);
    }
}

void autoaway_init_log(hexchat_plugin *plugin_handle) {
    ph = plugin_handle;

    char* path = get_log_path();

    // create/clear logfile
    FILE* file = fopen(path, "w");
    if(file != NULL) fclose(file);

    free(path);
}

void autoaway_log(const char* msg) {
    char* path = get_log_path();
    if(msg_buffer == NULL) msg_buffer = autoaway_msg_buffer_create(256);
    autoaway_msg_buffer_enqueue(msg_buffer, msg);
    if(path != NULL) {
        flush_buffer(path);
        free(path);
    }
}
