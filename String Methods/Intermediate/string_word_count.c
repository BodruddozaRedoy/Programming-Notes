#include <stdio.h>
#include <string.h>
#include <ctype.h>

// RAW METHOD
int word_count_raw(char str[])
{
    int count = 0, inWord = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]) && inWord == 0)
        {
            inWord = 1;
            count++;
        }
        else if (isspace(str[i]))
        {
            inWord = 0;
        }
    }
    return count;
}

// BUILT-IN METHOD
int word_count_builtin(char str[])
{
    int count = 0;
    char temp[200];
    strcpy(temp, str);
    char *token = strtok(temp, " \t\n");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " \t\n");
    }
    return count;
}

int main()
{
    char str[] = "C is a powerful programming language";
    printf("Raw Word Count: %d\n", word_count_raw(str));
    printf("Built-in Word Count: %d\n", word_count_builtin(str));
    return 0;
}
