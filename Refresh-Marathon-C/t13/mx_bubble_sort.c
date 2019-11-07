int mx_strcmp(const char *s1, const char *s2);

int mx_bubble_sort(char **arr, int size)
{
    int iter_count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (mx_strcmp(arr[j], arr[i]) < 0)
            {
                char *tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
                iter_count++;
            }
        }
    }
    return iter_count;
}
