#include "pathfinder.h"

char *mx_get_island1(char *line)
{
    int first_index = mx_get_char_index(line, '-');

    if (!line)
        return NULL;
    if (first_index >= 0)
        return mx_strndup(line, first_index);
    return NULL;
}
