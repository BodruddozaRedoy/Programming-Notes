#include <stdio.h>
#include <string.h>

// RAW METHOD
void remove_duplicates_raw(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len;) {
            if (str[i] == str[j]) {
                for (int k = j; k < len; k++)
                    str[k] = str[k + 1];
                len--;
            } else {
                j++;
            }
        }
    }
}

// BUILT-IN METHOD (Using array marker)
void remove_duplicates_builtin(char str[]) {
    int seen[256] = {0}, j = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (!seen[(unsigned char)str[i]]) {
            seen[(unsigned char)str[i]] = 1;
            str[j++] = str[i];
        }
    str[j] = '\0';
}

int main() {
    char s1[] = "programming";
    char s2[] = "language";

    remove_duplicates_raw(s1);
    printf("Raw: %s\n", s1);

    remove_duplicates_builtin(s2);
    printf("Built-in: %s\n", s2);
    return 0;
}
