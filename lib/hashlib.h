#ifndef HASH_BREAKER_HASHLIB_H
#define HASH_BREAKER_HASHLIB_H

// Including libraries
#include <openssl/evp.h>
#include <openssl/err.h>
#include "stringslib.h"

char* calculate_hash(char* str);
char* crack_hash(struct string* str, char* hash_to_find, int index, int max_size);
#endif //HASH_BREAKER_HASHLIB_H
