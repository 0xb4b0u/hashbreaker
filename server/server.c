#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "./../lib/comlib.h"

#define MAX_LINE 1024

int main(int argc, char* argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the server's IP and port from the arguments.
    char *ip = argv[1];
    int port = atoi(argv[2]);

    // Define the buffers and initialize them to 0
    char *buffer = malloc(MAX_LINE * sizeof(char));
    if (buffer == NULL) {
        perror("malloc error");
        return EXIT_FAILURE;
    }
    memset(buffer, 0, MAX_LINE);

    char *file_buffer = malloc(MAX_LINE * sizeof(char));
    if (file_buffer == NULL) {
        perror("malloc error");
        return EXIT_FAILURE;
    }
    memset(file_buffer, 0, MAX_LINE);

    // Create the server socket
    int server_fd = create_socket();
    if (server_fd == -1) {
        return EXIT_FAILURE;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons(port);

    // Bind the socket to the server's address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind error");
        return EXIT_FAILURE;
    }

    // Put the server in listening mode
    if (listen(server_fd, 3) < 0) {
        perror("listen error");
        return EXIT_FAILURE;
    } else {
        printf("Server listening on %s:%d\n", ip, port);
    }

    // Open the "hash_list" and "result" files
    FILE *hash_file = open_file("hash_list", "r");

    FILE *result_file = open_file("result", "a");

    // Loop to read each line from the "hash_list" file
    while (fgets(file_buffer, MAX_LINE, hash_file) != NULL) {

        // Remove the newline character from the string
        file_buffer[strcspn(file_buffer, "\n")] = 0;

        // Accept a new connection for each line
        int new_socket;
        int addrlen = sizeof(address);
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept error");
            continue;
        }
        printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Send the line to the client and store it in the "result" file
        if (send_data(new_socket, file_buffer) == -1) {
            return EXIT_FAILURE;
        }
        fprintf(result_file, "%s : ", file_buffer);

        // Receive the line sent back by the client
        if (receive_data(new_socket, buffer, MAX_LINE) == -1) {
            return EXIT_FAILURE;
        }

        printf("Received the password : %s\n", buffer);

        // Store the password in the "result" file
        fprintf(result_file, "%s\n", buffer);

        // Close the socket
        close(new_socket);
    }
    printf("No more hashes to crack\n"
           "exiting...\n");

    // Close the files
    close_files(2, hash_file, result_file);
    free(buffer);
    return 0;
}