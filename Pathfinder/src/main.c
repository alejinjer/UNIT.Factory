#include "pathfinder.h"

static bool check_line(char *line)
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

static int check_lines_format(char **splited_file)
{
    for (int i = 1; i < mx_arrlen(splited_file); i++)
    {
        if (!check_line(splited_file[i]))
            return i + 1;
    }
    return 0;
}

static char **validate_file(const char *filename)
{
    char *file_txt;
    char **splited_file;
    int fd = open(filename, O_RDONLY);

    if (read(fd, 0, 0) < 0)
        mx_printerr_pf(FILE_DEXIST, filename);
    else if (read(fd, 0, 1) == 0)
        mx_printerr_pf(FILE_EMPTY, filename);
    close(fd);
    file_txt = mx_file_to_str(filename);
    splited_file = mx_strsplit(file_txt, '\n');
    if (!mx_isnumber(splited_file[0]))
        mx_printerr_pf(INVLD_FRST_LINE, NULL);
    if (check_lines_format(splited_file))
        mx_printerr_pf(INVLD_LINE, mx_itoa(check_lines_format(splited_file)));

    mx_strdel(file_txt);
    return splited_file;
}

int main(int argc, char *argv[])
{
    char **splited_file;
    int islands_count;

    if (argc != 2)
        mx_printerr_pf(INVLD_CMD_ARGS, NULL);
    splited_file = validate_file(argv[1]);
    islands_count = mx_atoi(splited_file[0]);
    
    return 0;
}
