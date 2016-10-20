#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "logging.h"
#include "hexchat-plugin.h"

static const char* get_log_path() {
    return getenv("AUTOAWAY_LOGFILE");
}

static struct tm get_time() {
    time_t rawtime;
    time(&rawtime);
    struct tm* timeinfo = localtime(&rawtime);
    return *timeinfo;
}

static void append_msg(const char* path, const char* msg) {
    FILE* file = fopen(path, "a");
    if(file == NULL) return;

    struct tm time = get_time();
    fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n", time.tm_year+1900,
                                                            time.tm_mon+1,
                                                            time.tm_mday,
                                                            time.tm_hour,
                                                            time.tm_min,
                                                            time.tm_sec,
                                                            msg);

    fclose(file);
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

void autoaway_log(const char* format, ...) {
    const char* path = get_log_path();
    if(path == NULL) return;

    va_list args;
    va_start(args, format);
    const char*  msg = vsprintf_auto(format, args);
    va_end(args);

    if(msg == NULL) {
        append_msg(path, "Fatal: failed to format log message");
        abort();
    }

    append_msg(path, msg);
    free((void*)msg);
}
