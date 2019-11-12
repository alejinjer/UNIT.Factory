#include "pathfinder.h"

int **mx_get_weight_matrix(char **splited_file, char **islands)
{
    int size = mx_atoi(splited_file[0]);
    int **matrix = malloc(sizeof(int *) * size);
    char **ptr = splited_file;
    int i1;
    int i2;

    for (int i = 0; i < size; i++)
    {
        matrix[i] = malloc(sizeof(int) * size);
        i1 = mx_get_str_index(islands, mx_get_island1(*ptr));
        i2 = mx_get_str_index(islands, mx_get_island2(*ptr));
        matrix[i1][i2] = mx_get_weight_between(*ptr);
        matrix[i2][i1] = mx_get_weight_between(*ptr);
        ptr++;
    }
    return matrix;
}
