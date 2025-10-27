#include <stdio.h>
#include <string.h>

// RAW METHOD (Bubble Sort)
void sort_string_raw(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// BUILT-IN METHOD (qsort)
int cmpfunc(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}
void sort_string_builtin(char str[])
{
    qsort(str, strlen(str), sizeof(char), cmpfunc);
}

int main()
{
    char s1[] = "programming";
    char s2[] = "language";

    sort_string_raw(s1);
    printf("Raw Sort: %s\n", s1);

    sort_string_builtin(s2);
    printf("Built-in Sort: %s\n", s2);
    return 0;
}
