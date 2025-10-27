#include <stdio.h>
#include <string.h>

// RAW METHOD
int string_compare_raw(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') return 0;
        i++;
    }
    return s1[i] - s2[i];
}

// BUILT-IN METHOD
int string_compare_builtin(char s1[], char s2[]) {
    return strcmp(s1, s2);
}

int main() {
    char s1[] = "Hello", s2[] = "World";
    printf("Raw Compare: %d\n", string_compare_raw(s1, s2));
    printf("Built-in Compare: %d\n", string_compare_builtin(s1, s2));
    return 0;
}
