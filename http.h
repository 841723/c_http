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

int http_handle_request(
    char raw_req[MAX_LENGTH_REQUEST], 
    int raw_req_len, 
    char raw_res[MAX_LENGTH_RESPONSE], 
    int *raw_res_len
);


#endif