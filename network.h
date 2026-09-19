#ifndef NETWORK_H
#define NETWORK_H

#include <netinet/in.h>

char* get_client_ip(struct sockaddr_in *client);

#endif