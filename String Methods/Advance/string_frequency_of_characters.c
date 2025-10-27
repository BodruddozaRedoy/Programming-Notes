#include <stdio.h>
#include <string.h>

// RAW METHOD
void frequency_raw(char str[]) {
    int freq[256] = {0};
    for (int i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    for (int i = 0; i < 256; i++)
        if (freq[i] > 0 && str[i] != ' ')
            printf("%c : %d\n", i, freq[i]);
}

// BUILT-IN METHOD
void frequency_builtin(char str[]) {
    frequency_raw(str); // same logic using array count
}

int main() {
    char str[] = "success";
    printf("Character Frequency:\n");
    frequency_raw(str);
    return 0;
}
