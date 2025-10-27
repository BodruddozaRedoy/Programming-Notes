#include <stdio.h>
#include <string.h>

// RAW METHOD - Manual copy
void array_copy_raw(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

// BUILT-IN METHOD - Using memcpy
void array_copy_builtin(int source[], int dest[], int size) {
    memcpy(dest, source, size * sizeof(int));
}

int main() {
    int source[] = {1, 2, 3, 4, 5};
    int dest1[5], dest2[5];
    int size = sizeof(source) / sizeof(source[0]);
    
    array_copy_raw(source, dest1, size);
    printf("Raw Copy: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dest1[i]);
    }
    printf("\n");
    
    array_copy_builtin(source, dest2, size);
    printf("Built-in Copy: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dest2[i]);
    }
    printf("\n");
    return 0;
}
