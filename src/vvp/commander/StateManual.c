#include "StateManual.h"

// possible transitions
#include "StateAuto.h"

#include <assert.h>

static void  callbackAuto(StatePtr state) {
    assert(state != 0);
    transitionToAuto(state);
}

void transitionToManual(StatePtr state) {
    assert(state != 0);
    defaultImplementation(state);
    state->cbAuto = callbackAuto;
    state->name = "Manual";
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
