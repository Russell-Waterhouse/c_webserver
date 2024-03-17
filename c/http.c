#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "fatchar.h"
#include "http.h"
#include "result.h"


RequestResult* request_from_bytes(char* bytes, unsigned int bytes_len){
    RequestResult* rr = calloc(1, sizeof(RequestResult));
    if (rr == NULL) {
        printf("malloc failed in request_from_bytes\n");
        fflush(stdout);
        return NULL;
    }

    Request* req = malloc(sizeof(Request));
    if (req == NULL) {
        printf("malloc failed in request_from_bytes\n");
        fflush(stdout);
        rr->result = FAILURE;
        return rr;
    }

    if (bytes == NULL) {
        rr->result = FAILURE;
        return rr;
    }

    if (bytes_len < 1) {
        rr->result = FAILURE;
        return rr;
    }



    return NULL;
}
