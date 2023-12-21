//
// Created by Baptiste Oger on 20/12/2023.
//

#ifndef HASH_BREAKER_STRINGSLIB_H
#define HASH_BREAKER_STRINGSLIB_H

// Including libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the string's structure
struct string {
    char* str;
    int buffer_size;
    int str_size;
};

// Declaring functions
struct string* string_init(int buffer_size);
void string_free(struct string* str);

#endif //HASH_BREAKER_STRINGSLIB_H
