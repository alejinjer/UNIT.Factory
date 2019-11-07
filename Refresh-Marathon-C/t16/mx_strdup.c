#include <stdlib.h>

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *str)
{
    char *duplicate = mx_strnew(mx_strlen(str));
    if (duplicate == NULL)
        return NULL;
    return mx_strcpy(duplicate, str);
}
