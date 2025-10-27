#include <stdio.h>
#include <string.h>

// RAW METHOD
void replace_substring_raw(char str[], char old[], char new[])
{
    char result[200];
    int i, j = 0, k;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (k = 0; old[k] && str[i + k] == old[k]; k++)
            ;
        if (!old[k])
        {
            strcpy(result + j, new);
            j += strlen(new);
            i += strlen(old) - 1;
        }
        else
        {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    strcpy(str, result);
}

// BUILT-IN METHOD (using strstr)
void replace_substring_builtin(char *str, const char *old, const char *new)
{
    char buffer[500];
    char *pos;
    int index = 0;
    int oldLen = strlen(old);

    while ((pos = strstr(str, old)) != NULL)
    {
        strcpy(buffer + index, str);
        int diff = pos - str;
        strncpy(buffer + index, str, diff);
        index += diff;
        strcpy(buffer + index, new);
        index += strlen(new);
        str = pos + oldLen;
    }
}

int main()
{
    char str[200] = "I like Java. Java is powerful.";
    replace_substring_raw(str, "Java", "C");
    printf("Raw Replace: %s\n", str);
    return 0;
}
