#include "hashlib.h"

char* guess_hash_type(char* hash) {
    if (strlen(hash) == 32) {
        return "md5";
    } else if (strlen(hash) == 40) {
        return "sha1";
    } else if (strlen(hash) == 64) {
        return "sha256";
    } else if (strlen(hash) == 128) {
        return "sha512";
    } else {
        printf("Invalid hash\n");
        printf("Valid hash types: md5, sha1, sha256, sha512\n");
        return NULL;
    }
}

char* calculate_hash(char* str, const char* hash_type) {
    EVP_MD_CTX *tmp_mdctx;
    const EVP_MD *md_type;

    if (strcmp(hash_type, "md5") == 0) {
        md_type = EVP_md5();
    } else if (strcmp(hash_type, "sha1") == 0) {
        md_type = EVP_sha1();
    } else if (strcmp(hash_type, "sha256") == 0) {
        md_type = EVP_sha256();
    } else if (strcmp(hash_type, "sha512") == 0) {
        md_type = EVP_sha512();
    } else {
        printf("Invalid hash type\n");
        return NULL;
    }

    tmp_mdctx = EVP_MD_CTX_new();
    if (tmp_mdctx == NULL) {
        ERR_print_errors_fp(stderr);
        return NULL;
    }

    if (EVP_DigestInit(tmp_mdctx, md_type) != 1) {
        ERR_print_errors_fp(stderr);
        EVP_MD_CTX_free(tmp_mdctx);
        return NULL;
    }

    if (EVP_DigestUpdate(tmp_mdctx, str, strlen(str)) != 1) {
        ERR_print_errors_fp(stderr);
        EVP_MD_CTX_free(tmp_mdctx);
        return NULL;
    }
    unsigned char md[EVP_MAX_MD_SIZE];
    unsigned int md_len;

    if (EVP_DigestFinal(tmp_mdctx, md, &md_len) != 1) {
        ERR_print_errors_fp(stderr);
        EVP_MD_CTX_free(tmp_mdctx);
        return NULL;
    }

    EVP_MD_CTX_free(tmp_mdctx);

    char* hash = malloc(sizeof(char) * (md_len * 2 + 1));
    if (hash == NULL) {
        perror("malloc failed");
        return NULL;
    }
    for (int i = 0; i < md_len; i++) {
        sprintf(hash + i * 2, "%02x", md[i]);
    }
    hash[md_len * 2] = '\0';
    return hash;
}

char* crack_hash(struct string* str, char* hash_to_find, int index, int max_size, const char* hash_type) {
    if (index > 0) {
        char* hash = calculate_hash(str->str, hash_type);
        if (strcmp(hash, hash_to_find) == 0) {
            free(hash);
            return str->str;
        }
        free(hash);
    }
    if (index == max_size) {
        return NULL;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        str->str[index] = c;
        char* result = crack_hash(str, hash_to_find, index + 1, max_size, hash_type);
        if (result != NULL) {
            return result;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        str->str[index] = c;
        char* result = crack_hash(str, hash_to_find, index + 1, max_size, hash_type);
        if (result != NULL) {
            return result;
        }
    }
    for (char c = '0'; c <= '9'; c++) {
        str->str[index] = c;
        char* result = crack_hash(str, hash_to_find, index + 1, max_size, hash_type);
        if (result != NULL) {
            return result;
        }
    }
    return NULL;
}
