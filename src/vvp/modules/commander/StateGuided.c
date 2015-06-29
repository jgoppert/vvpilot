#include "StateGuided.h"

/* possible transitions */
#include "StateManual.h"
#include "StateAuto.h"

#include <assert.h>

static void callbackManual(CommanderPtr instance) {
    transitionToManual(instance);
}

static void callbackAuto(CommanderPtr instance) {
    transitionToAuto(instance);
}

void transitionToGuided(CommanderPtr instance) {
    commanderDefaultTransition(instance);
    instance->state= STATE_GUIDED;
    instance->callbackManual = callbackManual;
    instance->callbackAuto = callbackAuto;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
