#include <stdio.h>
#include <string.h>
#include <ctype.h>

// RAW METHOD
void to_lower_raw(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
}

// BUILT-IN METHOD
void to_lower_builtin(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

int main()
{
    char s1[] = "HELLO WORLD";
    char s2[] = "C LANGUAGE";

    to_lower_raw(s1);
    printf("Raw Lower: %s\n", s1);

    to_lower_builtin(s2);
    printf("Built-in Lower: %s\n", s2);
    return 0;
}
