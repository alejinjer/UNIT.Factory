#include "pathfinder.h"

static t_edge *parse_line(char *line)
{
    t_edge *edge = malloc(sizeof(t_edge));

    edge->island1 = mx_strndup(line, mx_get_char_index(line, '-'));
    line += mx_get_char_index(line, '-') + 1;
    edge->island2 = mx_strndup(line, mx_get_char_index(line, ','));
    line += mx_get_char_index(line, ',') + 1;
    edge->weight = mx_atoi(line);
    return edge;
}

int main(int argc, char *argv[])
{
    char **splited_file;
    int islands_count;

    if (argc != 2)
        mx_printerr_pf(INVLD_CMD_ARGS, NULL);
    splited_file = mx_validate_file(argv[1]);
    islands_count = mx_atoi(splited_file[0]);

    return 0;
}
