#include <stdio.h>

typedef struct Header {
    char* key;
    char* value;
} Header;


typedef struct Request {
    char* headers;
    char* numHeaders;
    char* url;
    char* credentials;
    char* destination;
    char* integrity;
    char* method;
    char* mode;
    char* body;
} Request;

typedef struct Response {
    char* type;
    char* url;
    char* headers;
    int numHeaders;
    char* body;
    int status;
    char* statusText;
} Response;

int main(int argc, char** argv) {
    printf("Hello, world!\n");
    return 0;
}

