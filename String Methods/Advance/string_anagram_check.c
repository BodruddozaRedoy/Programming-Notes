#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// RAW METHOD
bool is_anagram_raw(char s1[], char s2[])
{
    int count[256] = {0};
    if (strlen(s1) != strlen(s2))
        return false;

    for (int i = 0; s1[i]; i++)
        count[(unsigned char)s1[i]]++;
    for (int i = 0; s2[i]; i++)
        count[(unsigned char)s2[i]]--;
    for (int i = 0; i < 256; i++)
        if (count[i] != 0)
            return false;
    return true;
}

// BUILT-IN METHOD
bool is_anagram_builtin(char s1[], char s2[])
{
    char a[100], b[100];
    strcpy(a, s1);
    strcpy(b, s2);
    qsort(a, strlen(a), sizeof(char), (int (*)(const void *, const void *))strcmp);
    qsort(b, strlen(b), sizeof(char), (int (*)(const void *, const void *))strcmp);
    return strcmp(a, b) == 0;
}

int main()
{
    char s1[] = "listen", s2[] = "silent";
    printf("Raw Anagram: %s\n", is_anagram_raw(s1, s2) ? "Yes" : "No");
    printf("Built-in Anagram: %s\n", is_anagram_builtin(s1, s2) ? "Yes" : "No");
    return 0;
}
