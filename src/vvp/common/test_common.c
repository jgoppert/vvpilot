#include <assert.h>

#include "common.h"

int main(int argc, char ** argv) {
    UNUSED(argc);
    UNUSED(argv);
    assert(RET_OK == 0);
    assert(RET_ERROR == -1);
    return 0;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
