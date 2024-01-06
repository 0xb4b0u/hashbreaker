#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "./../lib/hashlib.h"
#include "./../lib/comlib.h"

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    // Check the number of arguments
    if (argc != 3)
    {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the server's IP and port from the arguments.
    char *ip = argv[1];
    int port = atoi(argv[2]);

    char *buffer = calloc(MAX_LINE, sizeof(char));
    if (buffer == NULL)
    {
        perror("calloc error");
        return EXIT_FAILURE;
    }

    // Create the client socket
    int sock = create_socket();
    if (sock == -1)
    {
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect_to_server(sock, &serv_addr) == -1)
    {
        return EXIT_FAILURE;
    }

    // Receive the hash from the server
    if (receive_data(sock, buffer, MAX_LINE) == -1)
    {
        return EXIT_FAILURE;
    }
    char *hash = buffer;
    printf("Received hash from server: %s\n", hash);

    // Check the hash's type
    char *hash_type = guess_hash_type(hash);

    // Crack the hash
    // Change this to the desired maximum size
    int max_size = 5;
    struct string *str = string_init(max_size + 1);
    if (str == NULL)
    {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (int size = 1; size <= max_size; size++)
    {
        char *result = crack_hash(str, hash, 0, size, hash_type);
        if (result != NULL)
        {
            printf("Found password: %s\n", result);
            // Send the password to the server
            if (send_data(sock, result) == -1)
            {
                return EXIT_FAILURE;
            }
            break;
        }
    }
    // Free the memory allocated and close the socket
    string_free(str);
    free(buffer);
    close(sock);
    return 0;
}