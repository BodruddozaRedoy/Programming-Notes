#include <stdio.h>
#include <string.h>
#include <ctype.h>

// RAW METHOD
int count_vowels_raw(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}

// BUILT-IN METHOD (uses strchr)
int count_vowels_builtin(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (strchr("AEIOUaeiou", str[i]))
            count++;
    return count;
}

int main()
{
    char s[] = "Education";
    printf("Raw Count: %d\n", count_vowels_raw(s));
    printf("Built-in Count: %d\n", count_vowels_builtin(s));
    return 0;
}
