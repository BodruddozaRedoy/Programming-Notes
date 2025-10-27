#include <stdio.h>
#include <string.h>
#include <ctype.h>

// RAW METHOD
void remove_spaces_raw(char str[])
{
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (!isspace(str[i]))
            str[j++] = str[i];
    str[j] = '\0';
}

// BUILT-IN METHOD
void remove_spaces_builtin(char str[])
{
    remove_spaces_raw(str); // same logic with isspace()
}

int main()
{
    char str[] = "C   Language   Rocks!";
    remove_spaces_raw(str);
    printf("Raw Remove Spaces: %s\n", str);

    char s2[] = "   Hello  World  ";
    remove_spaces_builtin(s2);
    printf("Built-in Remove Spaces: %s\n", s2);
    return 0;
}
