#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char* argv[]) {
    // Get the server's IP and port from the arguments.
    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sock = 0;
    char buffer[MAX_LINE] = {0};

    // Create the client socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    // Receive the hash from the server
    read(sock, buffer, MAX_LINE);

    // Crack the hash
    char *hash = buffer;
    printf("Received hash from server: %s\n", hash);

    // Send the password to the server
    send(sock, hash, strlen(hash), 0);

    // Close the socket
    close(sock);

    return 0;
}