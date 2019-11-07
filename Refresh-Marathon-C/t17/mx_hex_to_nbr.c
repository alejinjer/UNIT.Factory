#include <stdbool.h>

static bool isalpha(int c);
static bool isdigit(int c);

unsigned long mx_hex_to_nbr(const char *hex)
{
    unsigned long result = 0;
    int length = 0;
    int i = -1;
    unsigned long base = 1;

    while (hex[++i])
        length++;
    for (int i = length - 1; i >= 0; i--)
    {
        if (isalpha(hex[i]))
        {
            if (hex[i] >= 'a' && hex[i] <= 'f')
            {
                result += (hex[i] - 87) * base;
                base *= 16;
            }
            if (hex[i] >= 'A' && hex[i] <= 'F')
            {
                result += (hex[i] - 55) * base;
                base *= 16;
            }
        }
        if (isdigit(hex[i]))
        {
            result += (hex[i] - 48) * base;
            base *= 16;
        }
    }
    return result;
}

static bool isalpha(int c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    {
        return true;
    }
    else
        return false;
}

static bool isdigit(int c)
{
    if (c >= 48 && c <= 57)
        return true;
    return false;
}
