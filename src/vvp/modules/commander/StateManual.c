#include "StateManual.h"

/* possible transitions */
#include "StateAuto.h"
#include "StateGuided.h"

#include <assert.h>

static void callbackAuto(CommanderPtr instance) {
    transitionToAuto(instance);
}

static void callbackGuided(CommanderPtr instance) {
    transitionToGuided(instance);
}

void transitionToManual(CommanderPtr instance) {
    commanderDefaultTransition(instance);
    instance->state= STATE_MANUAL;
    instance->callbackAuto = callbackAuto;
    instance->callbackGuided = callbackGuided;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */

