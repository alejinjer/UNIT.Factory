#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
    unsigned long result = 0;
    int length = 0;
    int i = -1;
    unsigned long base = 1;

    if (hex == NULL) return 0;
    while (hex[++i]) length++;
    for (int i = length - 1; i >= 0; i--)
    {
        if (mx_isalpha(hex[i]))
        {
            if (hex[i] >= 'a' && hex[i] <= 'f') result += (hex[i] - 87) * base;
            if (hex[i] >= 'A' && hex[i] <= 'F') result += (hex[i] - 55) * base;
            base *= 16;
        }
        if (mx_isdigit(hex[i]))
        {
            result += (hex[i] - 48) * base;
            base *= 16;
        }
    }
    return result;
}
