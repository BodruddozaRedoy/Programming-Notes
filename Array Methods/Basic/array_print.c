#include <stdio.h>

// RAW METHOD - Manual printing
void array_print_raw(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// BUILT-IN METHOD - Using printf with loop
void array_print_builtin(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    array_print_raw(arr, size);
    array_print_builtin(arr, size);
    return 0;
}
