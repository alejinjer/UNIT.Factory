#ifndef PATHFINDER_HEADER
#define PATHFINDER_HEADER

#define BUF_SIZE 128
#define DELIM '\n'

#include "libmx.h"

typedef enum e_error
{
    INVLD_CMD_ARGS,
    FILE_DEXIST,
    FILE_EMPTY,
    INVLD_FRST_LINE,
    INVLD_LINE,
    INVLD_NUM_ISLDS
} t_error;

typedef struct s_island t_island;
typedef struct s_link t_link;
typedef struct s_main t_main;

struct s_island
{
    char *name;
    t_link *links; // linked islands list
    t_island *next;
};

struct s_link
{
    int weight; // weight between parent and linked islands
    t_island *linked_island;
    t_link *next;
};

struct s_main
{
    int fd;         // for read_line
    char *filename; // for read_line
    char *lineptr;  // for read_line
    int V;          // islands count
    t_island *islands;
};

//util.c
void mx_printerr_pf(t_error err, const char *s);
bool mx_isnumber(char *s);
int mx_arrlen(char **arr);
int mx_atoi(const char *str);
//main.c
t_main *mx_create_main();
void mx_parse_file(t_main *m);
//islands.c
t_island *mx_create_island(char *name);
void mx_add_island(t_island **islands, t_island *i);
t_island *mx_get_island(t_island **islands, char *name);
//links.c
t_link *mx_create_link(t_island *linded_island);
void mx_add_link(t_link **links, t_link *l);
void mx_set_link(t_link **links, t_island *linked_island, int weight);

#endif
