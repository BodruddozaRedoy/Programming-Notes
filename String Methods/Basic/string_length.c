#include <stdio.h>
#include <string.h>

// RAW METHOD
int string_length_raw(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// BUILT-IN METHOD
int string_length_builtin(char str[]) {
    return strlen(str);
}

int main() {
    char str[] = "Hello, World!";
    printf("Raw Length: %d\n", string_length_raw(str));
    printf("Built-in Length: %d\n", string_length_builtin(str));
    return 0;
}
