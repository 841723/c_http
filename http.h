#ifndef HTTP_H
#define HTTP_H

#include "config.h"

struct http_request {
    char method[16];
    char path[256];
    char version[16];
};
struct http_response {
    char *status_code;
    char data[MAX_LENGTH_RESPONSE];
    char *version;
};

// Adapter para la capa TCP genérica: firma compatible con tcp_handler_t
void http_handler(int client_fd, void *userdata);

// API de alto nivel: main solo necesita http, no tcp
int http_listen(const char *port, void (*on_listen)(void));
void http_stop_listener(void);


#endif