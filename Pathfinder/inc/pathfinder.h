#ifndef PATHFINDER_HEADER
#define PATHFINDER_HEADER

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

void mx_printerr_pf(t_error err, const char *s);
bool mx_isnumber(char *s);
int mx_arrlen(char **arr);
int mx_atoi(const char *str);

#endif
