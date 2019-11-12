#include "pathfinder.h"

int mx_get_weight_between(char *line) {
    return mx_get_char_index(line, ',') + 1;
}
