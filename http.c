#include <stdio.h>
#include <string.h>

#include "config.h"
#include "http_constants.h"

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
    // TODO
    response->status_code = HTTP_STATUS_401_UNAUTHORIZED;
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