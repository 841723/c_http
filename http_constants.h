#ifndef HTTP_CONSTANTS_H
#define HTTP_CONSTANTS_H

/* ============================================================
 * HTTP versions
 * ============================================================ */

#define HTTP_VERSION_1_0 "HTTP/1.0"
#define HTTP_VERSION_1_1 "HTTP/1.1"


/* ============================================================
 * HTTP methods
 * ============================================================ */

#define HTTP_METHOD_GET      "GET"
#define HTTP_METHOD_HEAD     "HEAD"
#define HTTP_METHOD_POST     "POST"
#define HTTP_METHOD_PUT      "PUT"
#define HTTP_METHOD_DELETE   "DELETE"
#define HTTP_METHOD_CONNECT  "CONNECT"
#define HTTP_METHOD_OPTIONS  "OPTIONS"
#define HTTP_METHOD_TRACE    "TRACE"
#define HTTP_METHOD_PATCH    "PATCH"


/* ============================================================
 * 2xx Success
 * ============================================================ */

#define HTTP_STATUS_200_OK                     "200 OK"
#define HTTP_STATUS_201_CREATED                "201 Created"
#define HTTP_STATUS_202_ACCEPTED               "202 Accepted"
#define HTTP_STATUS_203_NON_AUTHORITATIVE      "203 Non-Authoritative Information"
#define HTTP_STATUS_204_NO_CONTENT             "204 No Content"
#define HTTP_STATUS_205_RESET_CONTENT          "205 Reset Content"
#define HTTP_STATUS_206_PARTIAL_CONTENT        "206 Partial Content"


/* ============================================================
 * 3xx Redirection
 * ============================================================ */

#define HTTP_STATUS_300_MULTIPLE_CHOICES       "300 Multiple Choices"
#define HTTP_STATUS_301_MOVED_PERMANENTLY      "301 Moved Permanently"
#define HTTP_STATUS_302_FOUND                  "302 Found"
#define HTTP_STATUS_303_SEE_OTHER              "303 See Other"
#define HTTP_STATUS_304_NOT_MODIFIED           "304 Not Modified"
#define HTTP_STATUS_305_USE_PROXY              "305 Use Proxy"
#define HTTP_STATUS_307_TEMPORARY_REDIRECT     "307 Temporary Redirect"
#define HTTP_STATUS_308_PERMANENT_REDIRECT     "308 Permanent Redirect"


/* ============================================================
 * 4xx Client Error
 * ============================================================ */

#define HTTP_STATUS_400_BAD_REQUEST            "400 Bad Request"
#define HTTP_STATUS_401_UNAUTHORIZED           "401 Unauthorized"
#define HTTP_STATUS_402_PAYMENT_REQUIRED       "402 Payment Required"
#define HTTP_STATUS_403_FORBIDDEN              "403 Forbidden"
#define HTTP_STATUS_404_NOT_FOUND              "404 Not Found"
#define HTTP_STATUS_405_METHOD_NOT_ALLOWED     "405 Method Not Allowed"
#define HTTP_STATUS_406_NOT_ACCEPTABLE         "406 Not Acceptable"
#define HTTP_STATUS_407_PROXY_AUTH_REQUIRED    "407 Proxy Authentication Required"
#define HTTP_STATUS_408_REQUEST_TIMEOUT        "408 Request Timeout"
#define HTTP_STATUS_409_CONFLICT               "409 Conflict"
#define HTTP_STATUS_410_GONE                   "410 Gone"
#define HTTP_STATUS_411_LENGTH_REQUIRED        "411 Length Required"
#define HTTP_STATUS_412_PRECONDITION_FAILED    "412 Precondition Failed"
#define HTTP_STATUS_413_CONTENT_TOO_LARGE      "413 Content Too Large"
#define HTTP_STATUS_414_URI_TOO_LONG           "414 URI Too Long"
#define HTTP_STATUS_415_UNSUPPORTED_MEDIA_TYPE "415 Unsupported Media Type"
#define HTTP_STATUS_416_RANGE_NOT_SATISFIABLE  "416 Range Not Satisfiable"
#define HTTP_STATUS_417_EXPECTATION_FAILED     "417 Expectation Failed"
#define HTTP_STATUS_418_IM_A_TEAPOT            "418 I'm a teapot"
#define HTTP_STATUS_422_UNPROCESSABLE_CONTENT  "422 Unprocessable Content"
#define HTTP_STATUS_423_LOCKED                 "423 Locked"
#define HTTP_STATUS_424_FAILED_DEPENDENCY      "424 Failed Dependency"
#define HTTP_STATUS_426_UPGRADE_REQUIRED       "426 Upgrade Required"
#define HTTP_STATUS_428_PRECONDITION_REQUIRED  "428 Precondition Required"
#define HTTP_STATUS_429_TOO_MANY_REQUESTS      "429 Too Many Requests"
#define HTTP_STATUS_431_REQUEST_HEADER_FIELDS_TOO_LARGE \
    "431 Request Header Fields Too Large"


/* ============================================================
 * 5xx Server Error
 * ============================================================ */

#define HTTP_STATUS_500_INTERNAL_SERVER_ERROR \
    "500 Internal Server Error"

#define HTTP_STATUS_501_NOT_IMPLEMENTED \
    "501 Not Implemented"

#define HTTP_STATUS_502_BAD_GATEWAY \
    "502 Bad Gateway"

#define HTTP_STATUS_503_SERVICE_UNAVAILABLE \
    "503 Service Unavailable"

#define HTTP_STATUS_504_GATEWAY_TIMEOUT \
    "504 Gateway Timeout"

#define HTTP_STATUS_505_HTTP_VERSION_NOT_SUPPORTED \
    "505 HTTP Version Not Supported"

#define HTTP_STATUS_507_INSUFFICIENT_STORAGE \
    "507 Insufficient Storage"

#define HTTP_STATUS_511_NETWORK_AUTH_REQUIRED \
    "511 Network Authentication Required"


/* ============================================================
 * Content-Type
 * ============================================================ */

#define HTTP_CONTENT_TYPE_TEXT_PLAIN       "text/plain"
#define HTTP_CONTENT_TYPE_TEXT_HTML        "text/html"
#define HTTP_CONTENT_TYPE_TEXT_CSS         "text/css"
#define HTTP_CONTENT_TYPE_TEXT_JAVASCRIPT  "text/javascript"

#define HTTP_CONTENT_TYPE_APPLICATION_JSON "application/json"
#define HTTP_CONTENT_TYPE_APPLICATION_XML  "application/xml"
#define HTTP_CONTENT_TYPE_APPLICATION_PDF  "application/pdf"

#define HTTP_CONTENT_TYPE_IMAGE_JPEG       "image/jpeg"
#define HTTP_CONTENT_TYPE_IMAGE_PNG        "image/png"
#define HTTP_CONTENT_TYPE_IMAGE_GIF        "image/gif"
#define HTTP_CONTENT_TYPE_IMAGE_SVG        "image/svg+xml"

#define HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA "multipart/form-data"

#define HTTP_CONTENT_TYPE_OCTET_STREAM     "application/octet-stream"


/* ============================================================
 * HTTP Headers
 * ============================================================ */

#define HTTP_HEADER_HOST              "Host"
#define HTTP_HEADER_CONTENT_TYPE      "Content-Type"
#define HTTP_HEADER_CONTENT_LENGTH    "Content-Length"
#define HTTP_HEADER_CONNECTION        "Connection"
#define HTTP_HEADER_ACCEPT            "Accept"
#define HTTP_HEADER_ACCEPT_ENCODING   "Accept-Encoding"
#define HTTP_HEADER_USER_AGENT        "User-Agent"
#define HTTP_HEADER_SERVER            "Server"
#define HTTP_HEADER_DATE              "Date"
#define HTTP_HEADER_LOCATION          "Location"
#define HTTP_HEADER_AUTHORIZATION     "Authorization"
#define HTTP_HEADER_COOKIE            "Cookie"
#define HTTP_HEADER_SET_COOKIE        "Set-Cookie"
#define HTTP_HEADER_CACHE_CONTROL     "Cache-Control"
#define HTTP_HEADER_CONTENT_ENCODING  "Content-Encoding"
#define HTTP_HEADER_TRANSFER_ENCODING "Transfer-Encoding"
#define HTTP_HEADER_UPGRADE           "Upgrade"


/* ============================================================
 * Connection values
 * ============================================================ */

#define HTTP_CONNECTION_KEEP_ALIVE "keep-alive"
#define HTTP_CONNECTION_CLOSE      "close"


/* ============================================================
 * Transfer-Encoding values
 * ============================================================ */

#define HTTP_TRANSFER_ENCODING_CHUNKED "chunked"


/* ============================================================
 * Content-Encoding values
 * ============================================================ */

#define HTTP_CONTENT_ENCODING_GZIP    "gzip"
#define HTTP_CONTENT_ENCODING_DEFLATE "deflate"
#define HTTP_CONTENT_ENCODING_BR      "br"


/* ============================================================
 * Common HTTP header values
 * ============================================================ */

#define HTTP_CACHE_NO_CACHE "no-cache"
#define HTTP_CACHE_NO_STORE "no-store"


/* ============================================================
 * Separators / protocol syntax
 * ============================================================ */

#define HTTP_CRLF "\r\n"
#define HTTP_HEADER_SEPARATOR ": "
#define HTTP_REQUEST_LINE_SEPARATOR " "
#define HTTP_EMPTY_LINE "\r\n\r\n"

#endif