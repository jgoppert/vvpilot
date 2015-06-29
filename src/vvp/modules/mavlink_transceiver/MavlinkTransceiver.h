#pragma once

#define MALVINK_USE_CONVENIENCE_FUNCTIONS

#include <mavlink/common/mavlink.h>

typedef struct MavlinkTranceiver MavlinkTranceiver;
typedef struct MavlinkTranceiver * MavlinkTranceiverPtr;

struct MavlinkTransceiver_t {
    mavlink_system_t system;
    void (*callbackHeartbeat)(MavlinkTranceiverPtr,
                              mavlink_message_t msg);
};

int mavlink_tranciever_init(MavlinkTranceiverPtr instance);

int mavlink_tranciever_receive(MavlinkTranceiverPtr instance);

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
