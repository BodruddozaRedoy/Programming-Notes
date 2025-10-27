#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// RAW METHOD
bool is_palindrome_raw(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - i - 1]) return false;
    return true;
}

// BUILT-IN METHOD
bool is_palindrome_builtin(char str[]) {
    char rev[100];
    strcpy(rev, str);
    strrev(rev);
    return strcmp(str, rev) == 0;
}

int main() {
    char str[] = "madam";
    printf("Raw Palindrome: %s\n", is_palindrome_raw(str) ? "Yes" : "No");
    printf("Built-in Palindrome: %s\n", is_palindrome_builtin(str) ? "Yes" : "No");
    return 0;
}
