#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    char *d = dst;
    const char *s = src;
    
    while (n--)
        if ((*d++ = *s++) == c)
            return d;
    return dst;
}
