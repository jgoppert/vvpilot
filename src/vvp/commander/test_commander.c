#include "Commander.h"

int main(int arc, char ** argv) {
    Commander cmdr;
    commanderCallbackAuto(&cmdr);
    /*commanderCallbackManual(&cmdr);*/
    return 0;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
