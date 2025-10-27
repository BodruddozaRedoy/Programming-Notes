#include <stdio.h>
#include <ctype.h>

// RAW METHOD
void toggle_case_raw(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

// BUILT-IN METHOD
void toggle_case_builtin(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (islower(str[i]))
            str[i] = toupper(str[i]);
        else if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
}

int main()
{
    char s1[] = "HeLLo WoRLd";
    char s2[] = "C Lang Rocks";

    toggle_case_raw(s1);
    printf("Raw Toggle: %s\n", s1);

    toggle_case_builtin(s2);
    printf("Built-in Toggle: %s\n", s2);
    return 0;
}
