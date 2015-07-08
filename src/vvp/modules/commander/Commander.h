#pragma once

#include <inttypes.h>

/**
 * The possible events, stimulus, for the
 * finite state machine.
 */
typedef enum {
    EVENT_MANUAL, /* request for manual */
    EVENT_AUTO, /* request for auto */
    EVENT_GUIDED, /* request for guided */
    EVENT_NUMBER, /* number of events */
    EVENT_UNINIT /* unitialized */
} commanderEvent_t;

/**
 * The states within the finite state machine,
 * this should be limited to states in which
 * the vehicle should react differently to
 * outside stimulus and the number should
 * be kept as small as possible.
 */
typedef enum {
    STATE_MANUAL, /* manual mode */
    STATE_AUTO, /* auto mode */
    STATE_GUIDED, /* guided mode */
    STATE_NUMBER, /* number of states */
    STATE_UNINIT /* uninitialized */
} commanderState_t;

/**
 * Typedefs for commander data structure
 * and callbacks.
 */
typedef struct Commander_t * CommanderPtr;
typedef struct Commander_t Commander;
typedef void (*CallbackManual)(CommanderPtr);
typedef void (*CallbackAuto)(CommanderPtr);
typedef void (*CallbackGuided)(CommanderPtr);

/**
 * Commander data structure.
 *
 * This contains callbacks and an identifier
 * of the current state just for
 * use when debugging.
 *
 * Do not use the state variable
 * for switch statements, that violates
 * the purpose of the "State Pattern" approach
 * to finite state machines. Instead, use
 * the callbacks.
 */
struct Commander_t {
    CallbackManual callbackManual;
    CallbackAuto callbackAuto;
    CallbackGuided callbackGuided;
    unsigned int state;
};

/**
 * Initializes a commander data structure.
 * Does not allocate.
 */
void commanderInit(CommanderPtr instance);

/**
 * Updates a commander based on the event type.
 */
void commanderUpdate(CommanderPtr instance,
                     commanderEvent_t event);


/**
 * Serves as a default for state transitions.
 */
void commanderDefaultTransition(CommanderPtr instance);


/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
