#ifndef HASH_BREAKER_COMLIB_H
#define HASH_BREAKER_COMLIB_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

FILE *open_file(char *filename, char *mode);
int close_files(int num_files, ...);
int create_socket();
int connect_to_server(int sock, struct sockaddr_in *serv_addr);
ssize_t send_data(int sock, char *data);
ssize_t receive_data(int sock, char *buffer, size_t size);

#endif // HASH_BREAKER_COMLIB_H
