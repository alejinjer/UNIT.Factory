#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {    
    if (!s1 && !s2) return NULL;
    if (!s1) return mx_strdup(s2);
    if (!s2) return mx_strdup(s1);
    char *result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    char *ptr = result;

    result = mx_strcpy(result, s1);
    result += mx_strlen(s1);
    result = mx_strcpy(result, s2);
    return ptr;
}
