#include "mavlink_transceiver.h"

#include <vvp/cbmc/cbmc_stub.h>
#include <vvp/common/common.h>

#include <time.h>
#include <stdlib.h>
/*#include <err.h>*/

int main(int argc, char ** argv) {
    UNUSED(argc);
    UNUSED(argv);

    mavlink_transceiver_t comm;
    mavlink_transceiver_init(&comm);

    clock_t start = clock();

    float tf = 1.0f;
    float t = 0;

    do {
        mavlink_transceiver_receive(&comm);
        clock_t now = clock();
        t = (float)(now - start) / CLOCKS_PER_SEC;
    } while(t < tf);

    return 0;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */

