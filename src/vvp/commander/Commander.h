#pragma once

#include "State.h"

typedef struct {
    struct State state;
} Commander;

typedef Commander * CommanderPtr;

void commanderInit(CommanderPtr instance);
void commanderCallbackManual(CommanderPtr instance);
void commanderCallbackAuto(CommanderPtr instance);

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
