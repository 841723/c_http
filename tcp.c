#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#include "config.h"
#include "lib.h"

#include "tcp.h"

#define BACKLOG 10     // how many pending connections queue holds

/**********************************************
 Global Variables
**********************************************/

int sockfd = -1, http_server = 1;


/**********************************************
  Structs
**********************************************/



/**********************************************
 Helper functions
**********************************************/

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

int read_request(int client_fd, char buff[MAX_LENGTH_REQUEST]) {
    int bytes_read = recv(client_fd, buff, MAX_LENGTH_REQUEST-1, 0);
    if (bytes_read < 0) {
        return bytes_read;
    }
    if (!bytes_read) {
        return -0;
    }

    buff[bytes_read] = '\0';

    printf("%s\n", buff);
    return 0;
}

int send_response(int client_fd, char buff[MAX_LENGTH_REQUEST], int buff_len) {
    int bytes_sent;

    bytes_sent = send(client_fd, buff, buff_len, 0);
    if (bytes_sent < 0) {
        return -1;
    }
    return 0;
}

/**********************************************
   Exported functions
***********************************************/

 /**
  * Creates a tcp listener on port and executes callback 
  */
 int tcp_start_listener(char *port, void (*on_listen)(void), int (*on_request)(char buff[MAX_LENGTH_REQUEST], int, char buff2[MAX_LENGTH_RESPONSE], int*)) {
    int status, client_fd, bytes_sent, bytes_to_send, res_len, yes = 1;
    char *response, req[MAX_LENGTH_REQUEST], res[MAX_LENGTH_RESPONSE];
    
    struct sockaddr_in client;
    socklen_t addr_size;

    struct addrinfo hints, *res_addr;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = 0;
    hints.ai_flags = AI_PASSIVE;
    
    if ((status = getaddrinfo(NULL, port, &hints, &res_addr)) != 0) {
        fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(status));
        exit(-1);
    }

    sockfd = socket(res_addr->ai_family, res_addr->ai_socktype, res_addr->ai_protocol);
    if (sockfd < 0) {
        perror("socket() Error\n");
        exit(-2);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
        perror("setsockopt() Error\n");
        exit(-2);
    }

    if ((status = bind(sockfd, res_addr->ai_addr, res_addr->ai_addrlen)) < 0) {
        perror("bind() Error\n");
        exit(-3);
    }

    freeaddrinfo(res_addr);

    if (listen(sockfd, BACKLOG) != 0) {
        perror("listen Error\n");
        exit(-4);
    }

    on_listen();

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

        if (!status) {
            // child
            close(sockfd);

            if ((status = read_request(client_fd, req)) < 0) {
                perror("read_request() Error\n");
                exit(-7);
            }
            
            if (on_request(req, (int)strlen(req), res, &res_len) < 0) {
                perror("on_request() Error\n");
                exit(-8);
            }

            if ((status = send_response(client_fd, res, res_len)) < 0) {
                perror("read_request() Error\n");
                exit(-9);
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
}

/**
 * If started, stops tcp listener
 */
void tcp_stop_listener() {
    printf("Closing fd %d...\n", sockfd);
    if (sockfd >= 0) {
        close(sockfd);
    }
}
