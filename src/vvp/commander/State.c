#include "State.h"

#include <assert.h>

static void defaultCallbackManual(StatePtr state) {
    assert(state != 0);
}

static void defaultCallbackAuto(StatePtr state) {
    assert(state != 0);
}

void defaultImplementation(StatePtr state) {
    state->name = "UNNAMED";
    state->cbManual = defaultCallbackManual;
    state->cbAuto = defaultCallbackAuto;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
