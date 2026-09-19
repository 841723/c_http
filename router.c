#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "http_constants.h"

#include "routes.h"

/**********************************************
 Global Variables
**********************************************/


/**********************************************
  Structs
**********************************************/



/**********************************************
 Helper functions
**********************************************/

int routes_add(
    struct http_router *router, 
    char *method,
    char *path, 
    void (*handler)(
        struct http_request *,
        struct http_response *
    )
) {
    struct http_route *route = router_find(router, method, path);
    if (route != NULL) {
        return -1;
    }

    memset(route, 0, sizeof &route);
    route->method = method;
    route->path = path;
    route->handler = handler;

    router->routes[router->route_count++] = *route;
    return 0;
}


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
) {
    return routes_add(
        router,
        HTTP_METHOD_GET,
        path,
        handler
    );
}

struct http_route *router_find(
    struct http_router *router,
    char *method,
    char *path
) {
    unsigned int i = 0;
    for (i ; i < router->route_count ; i++) {
        if (strcmp(method, router->routes[i].method) && strcmp(path, router->routes[i].path)) {
            return &(router->routes[i]);
        }
    }
    return NULL;
}


