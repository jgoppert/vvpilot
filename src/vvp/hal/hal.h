#pragma once

#include <inttypes.h>

int hal_print_stdout(const char * fmt, ...);

uint16_t uart0_char_available();
uint8_t uart0_get_char();

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
