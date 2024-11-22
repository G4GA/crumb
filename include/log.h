#ifndef LOGGING_H
#define LOGGING_H

#include <stdbool.h>

#define BUFFER_SIZE 10
#define FILE_NAME_SIZE 128

typedef struct log_s {
    char *buffer[BUFFER_SIZE];
    char file_name[FILE_NAME_SIZE];
    int  index;
    bool enable_print;
} LOG_S;

typedef enum level {
    INFO,
    WARN,
    ERROR,
} LOG_LEVEL;

#ifdef ENABLE_LOGGING
    #define LOG(log_s, msg)       log_msg(log_s, msg)
    #define FLOG(log_s, msg, ...) format_log(log_s, msg, format __VA_OPT_(,), __VA_ARGS__ )

    #define INIT_LOG_S(file_name, enable_print) init_log_s(file_name, enable_print)
    #define FREE_LOG_S(log_s)                   free_logs(log_s)

    #define FILEPATH "./.logs/"

//Init and free functions
struct log_s init_log_s(const char *, bool);
void free_logs         (struct log_s*);

//Logging function
int log_msg   (const char *, struct log_s* );
int format_log(struct log_s*, const char *, ...);

#else 
    #define LOG(msg, log_s)       (0)
    #define FLOG(msg, log_s, ...) (0)

    #define INIT_LOG_S(filename, enable_print) ((LOG_S) {{NULL}, {0}, 0, false, false})
    #define FREE_LOG_S(log_s)                  ((void) 0)
    #endif

#endif
