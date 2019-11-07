void mx_printchar(char c);
void mx_printstr(const char *s);

int main(int argc, char *argv[])
{
    int i = 0;

    while (++i < argc)
    {
        mx_printstr(argv[i]);
        mx_printchar('\n');
    }
    return 0;
}
