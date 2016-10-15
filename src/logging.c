#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
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

static struct tm getTime() {
    time_t rawtime;
    time(&rawtime);
    struct tm* timeinfo = localtime(&rawtime);
    return *timeinfo;
}

static void append_msg(const char* path, const char* msg) {
    FILE* file = fopen(path, "a");
    if(file != NULL) {
        struct tm time = getTime();
        fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n", time.tm_year+1900,
                                                              time.tm_mon+1,
                                                              time.tm_mday,
                                                              time.tm_hour,
                                                              time.tm_min,
                                                              time.tm_sec,
                                                              msg);
        fclose(file);
    }
}

static const char* vsprintf_auto(const char* format, va_list args) {
    va_list a;
    va_copy(a, args);
    int needed = 1 + vsnprintf(NULL, 0, format, a);
    va_end(a);

    if(needed <= 0) { return NULL; } // return value was less than 0 -> error

    char *buffer = malloc(needed);
    if(vsnprintf(buffer, needed, format, args) < 0) {
        free(buffer);
        return NULL;
    }

    return buffer;
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

void autoaway_log(const char* format, ...) {
    va_list args;
    va_start(args, format);
    const char*  msg = vsprintf_auto(format, args);
    va_end(args);

    if(msg == NULL) {
        fputs("fatal: failed to format log message.", stderr);
        abort();
    }

    char* path = get_log_path();
    if(msg_buffer == NULL) msg_buffer = autoaway_msg_buffer_create(256);
    autoaway_msg_buffer_enqueue(msg_buffer, msg);
    free((void*)msg);
    if(path != NULL) {
        flush_buffer(path);
        free(path);
    }
}
