#include "../hal.h"

#include <vvp/common/common.h>

#include <stdio.h>
#include <stdarg.h>

int hal_print_stdout(const char * format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    return RET_OK;
}

uint16_t uart0_char_available() {
    return 0;
}

uint8_t uart0_get_char() {
    return 0;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
