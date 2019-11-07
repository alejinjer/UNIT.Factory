void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

int main(int argc, char *argv[])
{
    int k = 0;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 1; j < argc; j++)
            {
                if (mx_strcmp(argv[j], argv[i]) > 0)
                {
                    char *tmp = argv[j];
                    argv[j] = argv[i];
                    argv[i] = tmp;
                }
            }
        }
        while (argv[++k])
        {
            mx_printstr(argv[k]);
            mx_printchar('\n');
        }
    }
    return 0;
}
