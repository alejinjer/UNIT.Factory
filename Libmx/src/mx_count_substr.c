#include "libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    int count = -2;
    size_t sub_len = mx_strlen(sub);
    size_t str_len = mx_strlen(str);

    if (!str || !sub) return count;
    if (str_len < sub_len) return count;    
    count++;
    if (mx_strcmp(sub, "") == 0) return 0;
    while (*str)
    {
        if (mx_strncmp(str, sub, sub_len) == 0) count++;
        str += 1;
    }
    if (count >= 0) count++;   
    return count;
}
