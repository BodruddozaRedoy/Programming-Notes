#include <stdio.h>

// RAW METHOD
int array_length_raw(int arr[], int size) {
    return size; // In C, we need to pass size as parameter
}

// BUILT-IN METHOD (using sizeof)
int array_length_builtin(int arr[]) {
    return sizeof(arr) / sizeof(arr[0]); // Only works for local arrays
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Raw Length: %d\n", array_length_raw(arr, size));
    printf("Built-in Length: %d\n", array_length_builtin(arr));
    return 0;
}
