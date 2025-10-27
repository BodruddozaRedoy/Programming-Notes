#include <stdio.h>
#include <string.h>

// RAW METHOD
void string_concat_raw(char dest[], char src[]) {
    int i = 0, j = 0;
    while (dest[i] != '\0') i++;
    while (src[j] != '\0') dest[i++] = src[j++];
    dest[i] = '\0';
}

// BUILT-IN METHOD
void string_concat_builtin(char dest[], char src[]) {
    strcat(dest, src);
}

int main() {
    char a[100] = "Hello ";
    char b[] = "World";

    string_concat_raw(a, b);
    printf("Raw: %s\n", a);

    char c[100] = "Hello ";
    string_concat_builtin(c, b);
    printf("Built-in: %s\n", c);

    return 0;
}
