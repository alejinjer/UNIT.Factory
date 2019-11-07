#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (!str || !sub || !replace)
        return NULL;
    int index = 0;
    int result_len = mx_strlen(str) - (mx_count_substr(str, sub) *
                                       (mx_strlen(sub) - mx_strlen(replace)));
    char *result = mx_strnew(result_len);
    char *tmp = NULL;
    int sub_len = mx_strlen(sub);

    while ((index = mx_get_substr_index(str, sub)) != -1)
    {
        tmp = mx_strndup(str, index);
        result = mx_strcat(result, tmp);
        result = mx_strcat(result, replace);
        mx_strdel(&tmp);
        str += sub_len + index;
    }
    result = mx_strcat(result, str);
    return result;
}
