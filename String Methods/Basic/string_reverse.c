#include <stdio.h>
#include <string.h>

// RAW METHOD
void string_reverse_raw(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// BUILT-IN METHOD (Non-standard)
void string_reverse_builtin(char str[]) {
    strrev(str); // Works on some compilers (not standard)
}

int main() {
    char s1[] = "Hello";
    char s2[] = "World";

    string_reverse_raw(s1);
    printf("Raw Reverse: %s\n", s1);

    string_reverse_builtin(s2);
    printf("Built-in Reverse: %s\n", s2);
    return 0;
}
