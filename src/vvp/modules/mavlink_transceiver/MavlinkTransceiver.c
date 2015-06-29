#include "MavlinkTransceiver.h"

#include <mavlink/mavlink_helpers.h>
#include <vvp/common/common.h>
#include <vvp/hal/hal.h>

int mavlink_tranciever_init(MavlinkTranceiverPtr instance) {
    UNUSED(instance);
    return RET_OK;
}

int mavlink_receive(MavlinkTranceiverPtr instance) {

    UNUSED(instance);

    mavlink_message_t msg;
    mavlink_status_t status;

    while(uart0_char_available()) {
        uint8_t c = uart0_get_char();
        if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
            switch(msg.msgid) {
            case MAVLINK_MSG_ID_HEARTBEAT:
                break;
            default:
                break;
            }
        }
    }
    return RET_OK;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
