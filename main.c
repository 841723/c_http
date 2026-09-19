#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "http.h"


#define MYPORT "8888"  // the port users will be connecting to

void handler_sigint(int sig) {
    printf("\n");
    
    http_stop_listener();

    exit(0);
}

void on_listen(void) {
    printf("Server started listening on port %s...\n", MYPORT);
}

int main() {
    signal(SIGINT, handler_sigint);

    http_listen("8888", on_listen);

    printf("Server stopping successfully...\n");

    return 0;
}
