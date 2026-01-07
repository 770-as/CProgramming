#include <stdio.h>
#include <string.h>
#include "httpserver.h"

void handle_request(struct http_request *request) {
    const char *path= http_request_path(request);
    if (strcmp(path, "/")==0) {
        http_response_status(request, 200);
        http_response_header(request, "Content-Type", "text/html");
        http_response_body(request, "<h1>Hello World from C!</h1><p>You requested the root path.</p>", strlen("<h1>Hello World from C!</p>"));

    } else if (strcmp(path, "/api")==0) {
        const char *json_body="{\"status\": \"ok\", \"language\": \"C\"}";
        http_response_status(request, 200);
        http_response_header(request, "Content-Type", "application/json");
        http_response_body(request, json_body, strlen(json_body));

    } else {
        http_response_status(request, 404);
        http_response_header(request, "Content-Type", "text/plain");
        http_response_body(request, "404 Not Found", 13);
    }
}
int main() {
    printf("Starting C http Server on port 8080...\n");
    printf("Access at: http://127.0.0.1:8080/\n");
    struct http_server *server=http_server_init(8080, handle_request);/*initializes the server structure and 
prepares it to accept connections. It creates the socket(), bind() and setup the handler (function pointer)
that will be called for incoming request. It returns a pointer to a newly allocated struct*/
    if (server==NULL) {
        fprintf(stderr, "Error initializing the server\n");
        return 1;
    }
    int ret= http_server_listen(server);
    http_server_destroy(server);
    if(ret!=0) {
        fprintf(stderr, "Server listening failed with error code: %d\n", ret);
        return 1;
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
typedef enum {
    METHOD_UNKNOWN, METHOD_GET, METHOD_POST, METHOD_PUT, METHOD_DELETE, 
} HttpMethod;
typedef enum {
    PROTOCOL_UNKNOWN, PROTOCOL_HTTP_1_1
} HttpProtocol;
typedef struct {
    char *name;
    char *value;
} HttpHeader:
typedef struct {
    HttpMethod method;
    HttpProtocol protocol;
    char *uri_path;
    HttpHeader *headers;
    int header_count;
    int header_capacity;
    char *body;
    size_t content_length;
} HttpRequest;
