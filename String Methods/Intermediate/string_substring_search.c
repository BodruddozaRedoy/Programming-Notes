#include <stdio.h>
#include <string.h>

// RAW METHOD
int substring_search_raw(char str[], char sub[])
{
    int i, j;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = 0; sub[j] != '\0'; j++)
        {
            if (str[i + j] != sub[j])
                break;
        }
        if (sub[j] == '\0')
            return i; // Found
    }
    return -1; // Not found
}

// BUILT-IN METHOD
int substring_search_builtin(char str[], char sub[])
{
    char *pos = strstr(str, sub);
    if (pos)
        return pos - str;
    return -1;
}

int main()
{
    char str[] = "programming in C";
    char sub[] = "in";
    printf("Raw Substring Index: %d\n", substring_search_raw(str, sub));
    printf("Built-in Substring Index: %d\n", substring_search_builtin(str, sub));
    return 0;
}
