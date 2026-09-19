#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "network.h"


#define MYPORT "8888"  // the port users will be connecting to
#define BACKLOG 10     // how many pending connections queue holds

int main() {
    int status, len_res, client_fd, bytes_send, sockfd;
    char *response;
    struct addrinfo hints, *res;
    
    struct sockaddr_in client;
    socklen_t addr_size;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = 0;
    hints.ai_flags = AI_PASSIVE;
    
    if ((status = getaddrinfo(NULL, MYPORT, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(status));
        exit(-1);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket() Error\n");
        exit(-2);
    }

    if ((status = bind(sockfd, res->ai_addr, res->ai_addrlen)) < 0) {
        perror("bind() Error\n");
        exit(-3);
    }

    freeaddrinfo(res);

    if (listen(sockfd, BACKLOG) != 0) {
        perror("listen Error\n");
        exit(-4);
    }

    printf("Server started listening on port %s...\n", MYPORT);
    

    while (1) {
        addr_size = sizeof client;

        client_fd = accept(sockfd, (struct sockaddr *)&client, &addr_size);
        if (client_fd < 0) {
            perror("accept() Error\n");
            exit(-5);
        }

        char *client_ip = get_client_ip(&client);
        printf("Connection accepted from %s:%d\n", client_ip, client.sin_port);

        status = fork();
        if (status < 0) {
            perror("fork() Error\n");
            exit(-6);
        }
        if (status == 0) {
            // child
            close(sockfd);

            response = malloc(strlen(client_ip) + 10);
            snprintf(response, strlen(client_ip) + 10, "You are %s\n", client_ip);
            len_res = strlen(response);

            bytes_send = send(client_fd, response, len_res, 0);

            if (bytes_send < 0) {
                perror("send() Error");
                exit(-7);
            }
            close(client_fd);
            exit(0);
        } 
        else {
            // parent
            close(client_fd);
        }
    }

    close(sockfd);

    printf("Server stopping successfully...\n");

    return 0;
}