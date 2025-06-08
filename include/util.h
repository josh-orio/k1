#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>

void *memcpy(void *dest, const void *src, size_t n);
int strcmp(const char *str1, const char *str2);
int strlength(const char *str);
char *strcpy(char *dest, const char *src);
extern size_t strlen(const char *str);
extern void *memset(void *s, int c, size_t n);

#endif // VSTRING_H