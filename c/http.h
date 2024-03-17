#ifndef HTTP_H
#define HTTP_H

#include "fatchar.h"
#include "result.h"

typedef struct Header {
    fat_char* key;
    fat_char* value;
} Header;

typedef struct Request {
    fat_char* headers;
    fat_char* numHeaders;
    fat_char* url;
    fat_char* destination;
    fat_char* integrity;
    fat_char* method;
    fat_char* mode;
    fat_char* body;
} Request;

typedef struct Response {
    fat_char* type;
    fat_char* url;
    fat_char* headers;
    int numHeaders;
    fat_char* body;
    int status;
    fat_char* statusText;
} Response;

typedef struct request_result {
    enum Result result;
    Request* request;
} RequestResult;

RequestResult* request_from_bytes(RequestResult* request, char* bytes, unsigned int bytes_len);

#endif

