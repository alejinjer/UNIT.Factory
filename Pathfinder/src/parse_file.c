#include "pathfinder.h"

static void check_first_line(t_main *m)
{
    if (m->lineptr == NULL)
        mx_printerr_pf(FILE_EMPTY, m->filename);
    else if (mx_isnumber(m->lineptr))
    {
        m->V = mx_atoi(m->lineptr);
        mx_strdel(&m->lineptr);
    }
    else
        mx_printerr_pf(INVLD_FRST_LINE, NULL);
}

static bool check_line(char *line) // переделать + добавить проверку i1 и i2 != 0
{
    int i = -1;
    int island1 = 0;
    int island2 = 0;

    while (line[++i])
    {
        if (mx_isalpha(line[i]))
            island1++;
        else
            break;
    }
    if (line[i] != '-')
        return false;
    while (line[++i])
    {
        if (mx_isalpha(line[i]))
            island2++;
        else
            break;
    }
    if (line[i++] != ',')
        return false;
    if (!mx_isnumber(line + i))
        return false;
    return true;
}

static void mx_parse_line(t_main *m)
{
    char **ptr;
    char *ptr1;
    t_island *island1;
    t_island *island2;
    int weight;

    ptr = mx_strsplit(m->lineptr, '-');
    island1 = mx_get_island(&m->islands, mx_strdup(ptr[0]));
    ptr1 = mx_strdup(ptr[1]);
    mx_del_strarr(&ptr);
    ptr = mx_strsplit(ptr1, ',');
    mx_strdel(&ptr1);
    island2 = mx_get_island(&m->islands, mx_strdup(ptr[0]));
    weight = mx_atoi(ptr[1]);
    mx_del_strarr(&ptr);
    mx_set_link(&island1->links, island2, weight);
    mx_set_link(&island2->links, island1, weight);
}

void mx_parse_file(t_main *m)
{
    int line = 2;

    mx_read_line(&m->lineptr, BUF_SIZE, DELIM, m->fd);
    check_first_line(m);
    while (mx_read_line(&m->lineptr, BUF_SIZE, DELIM, m->fd) > 0)
    {
        if (check_line(m->lineptr))
            mx_parse_line(m);
        else
            mx_printerr_pf(INVLD_LINE, mx_itoa(line));
        mx_strdel(&m->lineptr);
        line++;
    }
}
