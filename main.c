#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "tcp.h"
#include "http.h"


#define MYPORT "8888"  // the port users will be connecting to

void handler_sigint(int sig) {
    printf("\n");
    
    tcp_stop_listener();

    exit(0);
}

void callback(void) {
    printf("Server started listening on port %s...\n", MYPORT);
}

int main() {
    signal(SIGINT, handler_sigint);

    
    tcp_start_listener("8888", callback, http_handle_request);

    printf("Server stopping successfully...\n");

    return 0;
}