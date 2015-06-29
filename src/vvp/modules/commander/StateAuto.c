#include "StateAuto.h"

/* possible transitions */
#include "StateManual.h"
#include "StateGuided.h"

#include <assert.h>

static void callbackManual(CommanderPtr instance) {
    transitionToManual(instance);
}

static void callbackGuided(CommanderPtr instance) {
    transitionToGuided(instance);
}

void transitionToAuto(CommanderPtr instance) {
    commanderDefaultTransition(instance);
    instance->state= STATE_AUTO;
    instance->callbackManual = callbackManual;
    instance->callbackGuided = callbackGuided;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
