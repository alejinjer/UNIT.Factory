#include "pathfinder.h"

int mx_get_str_index(char **arr, char *str) {
    int i = -1;

    if (!arr) return -2;
    while(arr[++i])
        if (mx_strcmp(arr[i], str) == 0)
            return i;
    return -1;
}
