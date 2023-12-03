#ifndef STRUTILS_H
#define STRUTILS_H
#include <stdlib.h>

#define MAX_STRLEN ((size_t)512)

/**
 * @brief Sanitized strlen.
 * 
 * @param str 
 * @return size_t 
 */
size_t STR_GetLength(char* str);

/**
 * @brief Copy a string into the free store.
 * 
 * @param str 
 * @return char* 
 */
char* STR_CopyString(char* str);

#endif