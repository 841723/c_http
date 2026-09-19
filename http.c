#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "config.h"
#include "http_constants.h"
#include "tcp.h"

#include "http.h"

/**********************************************
 Global Variables
**********************************************/



/**********************************************
  Structs
**********************************************/



/**********************************************
 Helper functions
**********************************************/

int parse_request(char raw_req[MAX_LENGTH_REQUEST], struct http_request *request)  {
    // TODO
    sscanf(raw_req, "%s %s %s", request->method, request->path, request->version);
    return 0;
}

int route_request(struct http_request *request, struct http_response *response) {
    // TODO - se deja tal cual, sin integrar router
    response->status_code = HTTP_STATUS_200_OK;
    snprintf(
        response->data,
        MAX_LENGTH_RESPONSE,
        "{"
        "\"method_used\": \"%s\","
        "\"path\": \"%s\","
        "\"version\": \"%s\""
        "}",
        request->method,
        request->path,
        request->version
    );
    response->version = HTTP_VERSION_1_1;

    return 0;
}

int build_response(
    struct http_response *http_response, 
    char res[MAX_LENGTH_RESPONSE], 
    int *res_len
) {
    int len = snprintf(
        res,
        MAX_LENGTH_RESPONSE,
        "%s %s"
        HTTP_CRLF
        HTTP_HEADER_CONTENT_TYPE
        HTTP_HEADER_SEPARATOR
        HTTP_CONTENT_TYPE_APPLICATION_JSON
        HTTP_CRLF 
        HTTP_CRLF
        "%s"
        HTTP_CRLF,
        http_response->version,
        http_response->status_code,
        http_response->data
    );
    if (len < 0) {
        return -1;
    }
    if (len > MAX_LENGTH_RESPONSE) {
        return -2;
    }

    (*res_len) = len;

    return 0;
}

// Helpers de I/O ahora pertenecen a la capa HTTP, no a TCP
static int http_read_request(int client_fd, char buff[MAX_LENGTH_REQUEST]) {
    int bytes_read = recv(client_fd, buff, MAX_LENGTH_REQUEST-1, 0);
    if (bytes_read < 0) {
        return bytes_read;
    }
    if (!bytes_read) {
        return 0;
    }

    buff[bytes_read] = '\0';

    printf("%s\n", buff);
    return 0;
}

static int http_send_response(int client_fd, char buff[MAX_LENGTH_RESPONSE], int buff_len) {
    int bytes_sent;

    bytes_sent = send(client_fd, buff, buff_len, 0);
    if (bytes_sent < 0) {
        return -1;
    }
    return 0;
}


/**********************************************
   Exported functions
**********************************************/

int http_handle_request(
    char raw_req[MAX_LENGTH_REQUEST], 
    int raw_req_len, 
    char raw_res[MAX_LENGTH_RESPONSE], 
    int *raw_res_len
) {
    struct http_request http_request;
    struct http_response http_response;

    // Inicializar buffers para evitar basura
    memset(&http_request, 0, sizeof(http_request));
    memset(&http_response, 0, sizeof(http_response));
    
    if (parse_request(raw_req, &http_request) < 0) {
        return -1;
    }

    if (route_request(&http_request, &http_response) < 0) {
        return -1;
    }
    
    if (build_response(&http_response, raw_res, raw_res_len) < 0) {
        return -1;
    }
    
    return 0;
}

void http_handler(int client_fd, void *userdata) {
    (void)userdata; // reservado para futuro router/contexto sin romper firma
    char req[MAX_LENGTH_REQUEST], res[MAX_LENGTH_RESPONSE];
    int res_len;
    int status;

    if ((status = http_read_request(client_fd, req)) < 0) {
        perror("http_read_request() Error\n");
        return;
    }

    if (http_handle_request(req, (int)strlen(req), res, &res_len) < 0) {
        perror("http_handle_request() Error\n");
        return;
    }

    if ((status = http_send_response(client_fd, res, res_len)) < 0) {
        perror("http_send_response() Error\n");
        return;
    }
}

int http_listen(const char *port, void (*on_listen)(void)) {
    // HTTP usa TCP como transporte
    return tcp_listen(port, http_handler, NULL, on_listen);
}

void http_stop_listener(void) {
    tcp_stop_listener();
}
