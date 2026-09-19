#ifndef ROUTES_H
#define ROUTES_H

#include "http.h" 

/**********************************************
  Structs
**********************************************/

struct http_route {
    char *method;
    char *path;

    void (*handler)(
        struct http_request *,
        struct http_response *
    );
};

struct http_router {
    struct http_route *routes;
    int route_count;
};


/**********************************************
   Exported functions
***********************************************/

int router_get(
    struct http_router *router, 
    char *path, 
    void (*handler)(
        struct http_request *,
        struct http_response *
    )
);

struct http_route *router_find(
    struct http_router *router,
    char *method,
    char *path
);

#endif