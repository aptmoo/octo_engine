#include "strutils.h"
#include <stdlib.h>
#include <string.h>

size_t STR_GetLength(char* str)
{
    /* Check if \0 is in str */
    char* end = (char*)memchr(str, '\0', MAX_STRLEN);

    if(end == NULL)
        return MAX_STRLEN;
    else
        return (size_t)(end - str);
}

char* STR_CopyString(char* str)
{
    char* out;
    size_t size = STR_GetLength(str);
    out = malloc(size + 1);
    strncpy(out, str, size);
    return out;
}