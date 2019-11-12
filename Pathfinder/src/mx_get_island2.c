#include "pathfinder.h"

char *mx_get_island2(char *line)
{
    int first_index = mx_get_char_index(line, '-');
    int second_index = mx_get_char_index(line, ',');

    if (!line)
        return NULL;
    if (second_index >= 0)
        return mx_strndup(line + first_index + 1, second_index - first_index - 1);
    return NULL;
}
