#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "./../lib/hashlib.h"
#include "./../lib/loglib.h"

#define MAX_LINE 1024

int main(int argc, char* argv[]) {
    // Get the server's IP and port from the arguments.
    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sock;
    char buffer[MAX_LINE] = {0};

    // Create the client socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect error");
        return EXIT_FAILURE;
    }

    // Receive the hash from the server
    read(sock, buffer, MAX_LINE);
    char *hash = buffer;
    printf("Received hash from server: %s\n", hash);

    // Crack the hash
    // Change this to the desired maximum size
    int max_size = 5;
    struct string* str = string_init(max_size + 1);
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (int size = 1; size <= max_size; size++) {
        char* result = crack_hash(str, hash, 0, size);
        if (result != NULL) {
            printf("Found password: %s\n", result);
            // Send the password to the server
            send(sock, result, strlen(result), 0);
            break;
        }
    }
    // Free the memory allocated and close the socket
    string_free(str);
    close(sock);

    return 0;
}