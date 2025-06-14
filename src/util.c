#include "util.h"

size_t strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void *memset(void *s, int c, size_t n) {
    unsigned char *p = (unsigned char *) s;
    while (n--) {
        *p++ = (unsigned char)c;
    }
    return s;
}

int strlength(const char *str) {
    int length = 0;
    while (*str++) {
        length++;
    }
    return length;
}


// Minimal implementation of strcpy
char *strcpy(char *dest, const char *src) {
    char *ret = (char *) dest;
    while ((*dest++ = *src++)) {}
    return ret;
}

// Minimal implementation of memcpy
void *memcpy(void *dest, const void *src, size_t n) {
    char *d = (char *) dest;
    const char *s = (char *) src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

// Custom strcmp implementation
int strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
