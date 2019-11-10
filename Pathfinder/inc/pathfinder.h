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

typedef struct s_edge
{
    char *island1;
    char *island2;
    int weight;
} t_edge;

void mx_printerr_pf(t_error err, const char *s);
bool mx_isnumber(char *s);
int mx_arrlen(char **arr);
int mx_atoi(const char *str);
char **mx_validate_file(const char *filename);

#endif
