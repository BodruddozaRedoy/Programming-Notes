#include <stdio.h>
#include <string.h>
#include <ctype.h>

// RAW METHOD
void count_characters_raw(char str[], int *letters, int *digits, int *spaces)
{
    *letters = *digits = *spaces = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
            (*letters)++;
        else if (isdigit(str[i]))
            (*digits)++;
        else if (isspace(str[i]))
            (*spaces)++;
    }
}

// BUILT-IN METHOD
void count_characters_builtin(char str[], int *letters, int *digits, int *spaces)
{
    count_characters_raw(str, letters, digits, spaces); // same logic using ctype.h
}

int main()
{
    char str[] = "C Lang 2025!";
    int letters, digits, spaces;

    count_characters_raw(str, &letters, &digits, &spaces);
    printf("Raw Count -> Letters:%d Digits:%d Spaces:%d\n", letters, digits, spaces);

    count_characters_builtin(str, &letters, &digits, &spaces);
    printf("Built-in Count -> Letters:%d Digits:%d Spaces:%d\n", letters, digits, spaces);
    return 0;
}
