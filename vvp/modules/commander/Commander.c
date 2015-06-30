#include "Commander.h"
#include "StateManual.h"

#include <assert.h>

#include <vvp/common/common.h>

void commanderInit(CommanderPtr instance) {
    transitionToManual(instance);
}

void commanderUpdate(CommanderPtr instance,
                     commanderEvent_t event) {
    switch (event) {
    case EVENT_MANUAL:
        instance->callbackManual(instance);
        break;
    case EVENT_AUTO:
        instance->callbackAuto(instance);
        break;
    case EVENT_GUIDED:
        instance->callbackGuided(instance);
        break;
    default:
        break;
    }
}

static void callbackManualDefault(CommanderPtr instance) {
    UNUSED(instance);
}

static void callbackAutoDefault(CommanderPtr instance) {
    UNUSED(instance);
}

static void callbackGuidedDefault(CommanderPtr instance) {
    UNUSED(instance);
}

void commanderDefaultTransition(CommanderPtr instance) {
    instance->state= STATE_UNINIT;
    instance->callbackManual = callbackManualDefault;
    instance->callbackAuto = callbackAutoDefault;
    instance->callbackGuided = callbackGuidedDefault;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
