#include "../hal.h"

#include <vvp/common/common.h>

#include <errno.h>

int main(int argc, char ** argv) {
    (void)argc; /* unused */
    (void)argv; /* unused */
    hal_print_stdout("hello\n");
    return RET_OK;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
