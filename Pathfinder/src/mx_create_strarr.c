#include "pathfinder.h"

char **mx_create_strarr(const int size)
{
    char **arr = malloc(sizeof(char *) * (size + 1));

    if (!arr)
        return NULL;
    for (int i = 0; i < size; i++)
    {
        arr[i] = "";
    }
    arr[size] = NULL;
    return arr;
}
