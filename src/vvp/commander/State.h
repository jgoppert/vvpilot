#pragma once

typedef struct State* StatePtr;
typedef void (*CallbackManual)(StatePtr);
typedef void (*CallbackAuto)(StatePtr);

struct State {
    CallbackManual cbManual;
    CallbackAuto cbAuto;
    const char * name;
};


void defaultImplementation(StatePtr state);

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
