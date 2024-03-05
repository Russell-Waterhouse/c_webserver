#include <stdio.h>
#include <sys/_types/_socklen_t.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>

#define LISTEN_BACKLOG 50

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

    // Creates a socket for IPv4, TCP protocol
    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_file_descriptor == -1) {
        printf("Error creating the socket");
        fflush(stdout);
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET; // IPv4
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // 127.0.0.1
    addr.sin_port = htons(9999); //port 9999

    int bind_result = bind(socket_file_descriptor, (struct sockaddr *) &addr, sizeof(addr));
    if(bind_result == -1) {
        printf("Error binding socket\n");
        printf("Errno: %d\n", errno);
        fflush(stdout);
        return -1;
    }

    int listen_result = listen(socket_file_descriptor, LISTEN_BACKLOG);
    if (listen_result == -1) {
        printf("Error listening to socket\n");
        printf("Errno: %d\n", errno);
        fflush(stdout);
        return -1;
    }

    struct sockaddr peer_addr;
    socklen_t peer_addr_size = sizeof(peer_addr);

    while (1) {
        int cfd = accept(
            socket_file_descriptor,
            (struct sockaddr *) &peer_addr,
            &peer_addr_size
        );

        if (cfd == -1) {
            printf("Error accepting a connection");
            fflush(stdout);
            return -1;
        }

        printf("got connection %d\n", cfd);
    }

    if(close(socket_file_descriptor) == -1) {
        printf("Error closing socket");
        fflush(stdout);
        return -1;
    }

    return 0;
}

