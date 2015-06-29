#include "Commander.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <vvp/cbmc/cbmc_stub.h>
#include <vvp/common/common.h>

int main(int argc, char ** argv) {
    Commander cmdr;
    int i = 0;
    UNUSED(argc);
    UNUSED(argv);
    commanderInit(&cmdr);
    for (i=0; i<10; i++) {
        commanderEvent_t event = nondet_uint() % EVENT_NUMBER;
        __CPROVER_assume(event >= 0 && event < EVENT_NUMBER);
        printf("state: %d\tevent: %d\t", cmdr.state, event);
        commanderUpdate(&cmdr, event);
        printf("new state: %d\n", cmdr.state);
        assert(cmdr.state >= 0 && cmdr.state < STATE_NUMBER);
    }
    commanderUpdate(&cmdr, EVENT_MANUAL);
    assert(cmdr.state == STATE_MANUAL);

    commanderUpdate(&cmdr, EVENT_AUTO);
    assert(cmdr.state == STATE_AUTO);

    assert(RET_OK == 0);
    assert(RET_ERROR == -1);

    return RET_OK;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
