#include "mavlink_transceiver.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <err.h>
#include <termios.h>

#include <mavlink/mavlink_helpers.h>
#include <vvp/common/common.h>
#include <vvp/hal/hal.h>

int mavlink_transceiver_init(mavlink_transceiver_t * this) {
    this->system.sysid = 100;
    this->system.sysid = 50;
    const char * device = "/dev/ttyS0";
    int fd = open(device, O_RDWR | O_NOCTTY| O_NDELAY);
    // NO_CTTY : doesn't want to be controlling terminal
    // NDELAY : doesn't want for characters
    if (fd == -1) {
        err(1, "unable to open %s\n", device);
    } else {
        fcntl(fd, F_SETFL, 0);
    }
    this->fd = fd;
    return RET_OK;
}

int mavlink_transceiver_receive(mavlink_transceiver_t * this) {

    mavlink_message_t msg;
    mavlink_status_t status;

    uint8_t c;
    while(read(this->fd, &c, 1) > 0) {
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
