#include "comlib.h"

FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        perror("fopen error");
        return NULL;
    }
    return file;
}

int close_files(int num_files, ...)
{
    va_list files;
    va_start(files, num_files);

    for (int i = 0; i < num_files; i++)
    {
        FILE *file = va_arg(files, FILE *);
        if (fclose(file) == EOF)
        {
            perror("fclose error");
            va_end(files);
            return EXIT_FAILURE;
        }
    }
    va_end(files);
    return EXIT_SUCCESS;
}

int create_socket()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket creation failed");
    }
    return sock;
}

int connect_to_server(int sock, struct sockaddr_in *serv_addr)
{
    int res = connect(sock, (struct sockaddr *)serv_addr, sizeof(*serv_addr));
    if (res == -1)
    {
        perror("connection to server failed");
    }
    return res;
}

ssize_t send_data(int sock, char *data)
{
    ssize_t bytes_sent = send(sock, data, strlen(data), 0);
    if (bytes_sent == -1)
    {
        perror("data sending failed");
    }
    return bytes_sent;
}

ssize_t receive_data(int sock, char *buffer, size_t size)
{
    ssize_t bytes_received = recv(sock, buffer, size, 0);
    if (bytes_received == -1)
    {
        perror("data receiving failed");
    }
    return bytes_received;
}
