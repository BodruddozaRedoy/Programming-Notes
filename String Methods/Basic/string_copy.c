#include <stdio.h>
#include <string.h>

// RAW METHOD
void string_copy_raw(char dest[], char src[]) {
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

// BUILT-IN METHOD
void string_copy_builtin(char dest[], char src[]) {
    strcpy(dest, src);
}

int main() {
    char src[] = "C Programming";
    char dest1[50], dest2[50];

    string_copy_raw(dest1, src);
    string_copy_builtin(dest2, src);

    printf("Raw Copy: %s\n", dest1);
    printf("Built-in Copy: %s\n", dest2);
    return 0;
}
