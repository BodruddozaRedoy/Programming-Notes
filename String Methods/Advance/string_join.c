#include <stdio.h>
#include <string.h>

// RAW METHOD
void join_raw(char s1[], char s2[], char result[])
{
    int i = 0, j = 0;
    while (s1[i] != '\0')
        result[i++] = s1[i];
    result[i++] = ' ';
    while (s2[j] != '\0')
        result[i++] = s2[j++];
    result[i] = '\0';
}

// BUILT-IN METHOD
void join_builtin(char s1[], char s2[], char result[])
{
    strcpy(result, s1);
    strcat(result, " ");
    strcat(result, s2);
}

int main()
{
    char s1[] = "Hello", s2[] = "World", result[100];
    join_raw(s1, s2, result);
    printf("Raw Join: %s\n", result);

    join_builtin(s1, s2, result);
    printf("Built-in Join: %s\n", result);
    return 0;
}
