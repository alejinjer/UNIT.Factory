#include "pathfinder.h"

int main(int argc, char *argv[])
{
    char **splited_file;
    int islands_count;
    char **islands;
    // int **weight_matrix;

    if (argc != 2)
        mx_printerr_pf(INVLD_CMD_ARGS, NULL);
    splited_file = mx_validate_file(argv[1]);
    islands_count = mx_atoi(splited_file[0]);
    islands = mx_get_islands_arr(splited_file);
    // weight_matrix = mx_get_weight_matrix(splited_file, islands);

    // for (int i = 0; i < islands_count; i++) {
    //     for (int j = 0; j < islands_count; j++) {
    //         mx_printint(weight_matrix[i][j]);
    //     }
    // }
    mx_print_strarr(islands, "\n");
    printf("%s\n", splited_file[1]);


    // system("leaks -q pathfinder");
    return 0;
}
