#ifndef TCP_H
#define TCP_H

#include "config.h"

#include <netinet/in.h>

int tcp_start_listener(
    char *port, 
    void (*on_listen)(
        void
    ), 
    int (*on_request)(
        char [MAX_LENGTH_REQUEST], 
        int, 
        char [MAX_LENGTH_RESPONSE], 
        int*
    )
);
void tcp_stop_listener();

#endif