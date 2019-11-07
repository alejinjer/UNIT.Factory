#include "libmx.h"

char **mx_strsplit(const char *s, char c)
{
    if (!s || mx_get_char_index(s, c) == -1)
        return NULL;
    int size_arr = mx_count_words(s, c);
    char **arr = malloc((sizeof(char *) * (size_arr + 1)));
    int s_len = mx_strlen(s);
    int index = 0;
    int j = 0;

    for (int i = 0; i < s_len; i++)
    {
        index = mx_get_char_index(s, c);
        index = index == -1 ? mx_strlen(s) : index;
        if (index)
        {
            arr[j] = mx_strndup(s, index);

            s += mx_strlen(arr[j]) - 1;
            i += mx_strlen(arr[j]) - 1;
            j++;
        }
        s++;
    }
    arr[size_arr] = NULL;
    return arr;
}
