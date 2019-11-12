#ifndef PATHFINDER_HEADER
#define PATHFINDER_HEADER

#define INF 999999999

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

typedef struct s_adj_list_node
{
    int dest;
    struct s_adj_list_node *next;
} t_adj_list_node;

typedef struct s_adj_list
{
    struct s_adj_list_node *head;
} t_adj_list;

typedef struct s_graph
{
    int V;
    struct s_adj_list *array;
} t_graph;

void mx_printerr_pf(t_error err, const char *s);
bool mx_isnumber(char *s);
int mx_arrlen(char **arr);
int mx_atoi(const char *str);
char **mx_validate_file(const char *filename);
int mx_get_str_index(char **arr, char *str);
char **mx_get_islands_arr(char **splited_file);
char **mx_create_strarr(const int size);
char *mx_get_island1(char *line);
char *mx_get_island2(char *line);
int mx_get_weight_between(char *line);
int **mx_get_weight_matrix(char **splited_file, char **islands);
t_graph *mx_create_graph(int V);
t_adj_list_node *mx_new_adj_list_node(int dest);
void mx_add_edge(t_graph *graph, int src, int dst);

#endif
