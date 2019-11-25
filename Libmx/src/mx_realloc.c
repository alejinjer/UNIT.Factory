#include "libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    void *result = NULL;

    if (!ptr && size)
        return malloc(size);
    if (!size && ptr)
    {
        free(ptr);
        return malloc(1);
    }
    result = malloc(size);
    mx_memcpy(result, ptr, malloc_size(ptr));
    free(ptr);
    return result;
}
