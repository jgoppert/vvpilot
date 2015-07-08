#pragma once

typedef long wint_t;

#define MALVINK_USE_CONVENIENCE_FUNCTIONS

#include <mavlink/common/mavlink.h>

typedef struct mavlink_transceiver_s {
    mavlink_system_t system;
    int fd;
} mavlink_transceiver_t;

int mavlink_transceiver_init(mavlink_transceiver_t * this);

int mavlink_transceiver_receive(mavlink_transceiver_t * this);

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
