#include "hashlib.h"

char* calculate_hash(char* str) {
    EVP_MD_CTX *tmp_mdctx;
    tmp_mdctx = EVP_MD_CTX_new();
    EVP_DigestInit(tmp_mdctx, EVP_md5());
    EVP_DigestUpdate(tmp_mdctx, str, strlen(str));
    unsigned char md[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    EVP_DigestFinal(tmp_mdctx, md, &md_len);
    EVP_MD_CTX_free(tmp_mdctx);
    char* hash = malloc(sizeof(char) * (md_len * 2 + 1));
    for (int i = 0; i < md_len; i++) {
        sprintf(hash + i * 2, "%02x", md[i]);
    }
    hash[md_len * 2] = '\0';
    return hash;
}

char* crack_hash(struct string* str, char* hash_to_find, int index, int max_size) {
    if (index > 0) {
        str->str[index] = '\0';
        char* hash = calculate_hash(str->str);
        if (strcmp(hash, hash_to_find) == 0) {
            return str->str;
        }
        free(hash);
    }
    if (index == max_size) {
        return NULL;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        str->str[index] = c;
        char* result = crack_hash(str, hash_to_find, index + 1, max_size);
        if (result != NULL) {
            return result;
        }
    }
    return NULL;
}
