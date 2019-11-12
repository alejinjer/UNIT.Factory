#include "pathfinder.h"

char **mx_get_islands_arr(char **splited_file)
{
    int arr_len = mx_atoi(splited_file[0]);
    char **islands = mx_create_strarr(arr_len);
    char **ptr = splited_file + 1;
    char *tmp = NULL;
    int j = 0;

    while (*ptr)
    {
        if ((tmp = mx_get_island1(*ptr)))
            *ptr += mx_strlen(tmp) + 1;
        else if ((tmp = mx_get_island2(*ptr)))
            *ptr += mx_strlen(tmp) + 1;
        if (tmp && mx_get_str_index(islands, tmp) == -1)
        {
            if (j == arr_len)
            {
                mx_strdel(&tmp);
                mx_printerr_pf(INVLD_NUM_ISLDS, NULL);
            }
            islands[j++] = mx_strdup(tmp);
        }
        if (!tmp)
            ptr++;
        mx_strdel(&tmp);
    }
    return islands;
}
