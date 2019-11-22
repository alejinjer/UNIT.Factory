#include "pathfinder.h"

t_main *mx_create_main()
{
    t_main *m = malloc(sizeof(t_main));

    m->filename = NULL;
    m->islands = NULL;
    m->lineptr = NULL;
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
        i++;
        iter = iter->next;
    }
}

int main(int argc, char *argv[])
{
    int fd;
    t_main *m;

    if (argc != 2)
        mx_printerr_pf(INVLD_CMD_ARGS, NULL);
    fd = open(argv[1], O_RDONLY);
    if (read(fd, 0, 0) < 0)
        mx_printerr_pf(FILE_DEXIST, argv[1]);
    m = mx_create_main();
    m->filename = argv[1];
    m->fd = fd;
    mx_parse_file(m);
    mx_prepare_for_algorithm(m);
    mx_find_all_paths(m);

    
    // print paths

    system("leaks -q pathfinder");
    return 0;
}
