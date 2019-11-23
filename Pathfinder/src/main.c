#include "pathfinder.h"

t_main *mx_create_main()
{
    t_main *m = malloc(sizeof(t_main));

    m->filename = NULL;
    m->islands = NULL;
    m->lineptr = NULL;
    m->start = NULL;
    m->end = NULL;
    m->start_remainder = NULL;
    return m;
}

void mx_prepare_for_algorithm(t_main *m)
{
    t_island *iter = m->islands;
    int i = 0;

    while (iter)
    {
        iter->index = i;
        iter->paths = malloc(sizeof(t_path *) * m->V);
        for (int i = 0; i < m->V; i++)
            iter->paths[i] = NULL;
        i++;
        iter = iter->next;
    }
}

int main(int argc, char *argv[])
{
    int fd;
    t_main *m;

    if (argc != 2)
        mx_terminate("usage: ./pathfinder [filename]");
    fd = open(argv[1], O_RDONLY);
    if (read(fd, 0, 0) < 0)
        mx_printerr_pf(FILE_DEXIST, argv[1]);
    m = mx_create_main();
    m->filename = argv[1];
    m->fd = fd;
    mx_parse_file(m);
    mx_prepare_for_algorithm(m);
    mx_find_all_paths(m);
    mx_print_all_paths(m);

    system("leaks -q pathfinder"); // не забудь убрать
    return 0;
}
