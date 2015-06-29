#include "StateAuto.h"

// possible transitions
#include "StateManual.h"

#include <assert.h>

static void callbackManual(StatePtr state) {
    assert(state != 0);
    transitionToManual(state);
}

void transitionToAuto(StatePtr state) {
    assert(state != 0);
    defaultImplementation(state);
    state->name = "Auto";
    state->cbManual = callbackManual;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
