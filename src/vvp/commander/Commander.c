#include "Commander.h"

#include "StateManual.h"
#include "StateAuto.h"

#include <assert.h>

void commanderInit(CommanderPtr instance) {
    assert(instance != 0);
    transitionToManual(&instance->state);
}

void commanderCallbackManual(CommanderPtr instance) {
    assert(instance != 0);
    instance->state.cbManual(&instance->state);
}

void commanderCallbackAuto(CommanderPtr instance) {
    assert(instance != 0);
    instance->state.cbAuto(&instance->state);
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
