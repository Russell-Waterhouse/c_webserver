#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "http.h"
#include "result.h"

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

enum Result assert(bool condition, char* test_name) {
    if (condition) {
        printf("%s %s succeeded %s\n", COLOR_GREEN, test_name, COLOR_RESET);
        return SUCCESS;
    } else {
        printf("%s %s failed %s\n", COLOR_RED, test_name, COLOR_RESET);
        return FAILURE;
    }
}

enum Result test_request_from_bytes(void) {
    char* request =
        "GET / HTTP/1.1\r\n"
        "Host: localhost:9999\r\n"
        "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:123.0) Gecko/20100101 Firefox/123.0\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8\r\n"
        "Accept-Language: en-CA,en-US;q=0.7,en;q=0.3\r\n"
        "Accept-Encoding: gzip, deflate, br\r\n"
        "Connection: keep-alive\r\n"
        "Upgrade-Insecure-Requests: 1\r\n"
        "Sec-Fetch-Dest: document\r\n"
        "Sec-Fetch-Mode: navigate\r\n"
        "Sec-Fetch-Site: none\r\n"
        "Sec-Fetch-User: ?1\r\n";

    RequestResult* rr = request_from_bytes(request, strlen(request));
    if (
            assert(rr != NULL, "#request_from_bytes result not null") == FAILURE ||
            assert(rr->request != NULL, "#request_from_bytes result's request not null") == FAILURE ||
            assert(rr->result == SUCCESS, "#request_from_bytes result's result is success") == FAILURE ||
            assert(rr->request->method == GET, "#request_from_bytes result's method is GET") == FAILURE ||
            assert(rr->request->num_headers == 11, "#num_headers is correct") == FAILURE
            // assert(rr->request->headers[0]->key->len == 5, "#first header key length is correct") == FAILURE
        ) {
        printf("rr->request->num_headers is: %d\n", rr->request->num_headers);
        delete_request_result(rr);
        return FAILURE;
    }



    if (delete_request_result(rr) == FAILURE) {
        printf("%s delete_request_result failed %s\n", COLOR_RED, COLOR_RESET);
    }
    return SUCCESS;
}

int main(void) {
    enum Result result1 = test_request_from_bytes();
    if (result1 == FAILURE) {
        return -1;
    }
    return 0;
}
