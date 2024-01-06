#include "stringslib.h"

struct string *string_init(int buffer_size)
{
    struct string *str = (struct string *)malloc(sizeof(struct string));
    if (str == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    str->str = (char *)malloc(buffer_size * sizeof(char));
    if (str->str == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    str->buffer_size = buffer_size;
    str->str_size = 0;
    return str;
}

void string_free(struct string *str)
{
    free(str->str);
    free(str);
}
