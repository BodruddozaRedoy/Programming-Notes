#include <stdio.h>
#include <string.h>
#include <ctype.h>

// RAW METHOD
void to_upper_raw(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
}

// BUILT-IN METHOD
void to_upper_builtin(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}

int main()
{
    char s1[] = "hello world";
    char s2[] = "c programming";

    to_upper_raw(s1);
    printf("Raw Upper: %s\n", s1);

    to_upper_builtin(s2);
    printf("Built-in Upper: %s\n", s2);
    return 0;
}
