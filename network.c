#include <arpa/inet.h>
#include "network.h"

char *get_client_ip(struct sockaddr_in *client) {
    static char client_ip[INET_ADDRSTRLEN];

    inet_ntop(
        AF_INET,
        &client->sin_addr,
        client_ip,
        sizeof client_ip
    );

    return client_ip;
}