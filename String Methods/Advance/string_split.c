#include <stdio.h>
#include <string.h>

// RAW METHOD
void split_raw(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            printf("\n");
        else
            printf("%c", str[i]);
}

// BUILT-IN METHOD
void split_builtin(char str[])
{
    char *token = strtok(str, " ");
    while (token)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}

int main()
{
    char s1[] = "C makes programming fun";
    char s2[] = "Split this string easily";

    printf("Raw Split:\n");
    split_raw(s1);

    printf("\nBuilt-in Split:\n");
    split_builtin(s2);
    return 0;
}
