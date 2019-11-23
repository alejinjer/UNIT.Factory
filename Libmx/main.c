#include "libmx.h"

int main() {

    printf("%lu\n", mx_hex_to_nbr("C 4"));
    printf("%lu\n", mx_hex_to_nbr("FADE"));
    printf("%lu\n", mx_hex_to_nbr("ffffffffffff"));
    printf("%lu\n", mx_hex_to_nbr(NULL));
}
