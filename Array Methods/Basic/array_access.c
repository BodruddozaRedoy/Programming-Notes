#include <stdio.h>

// RAW METHOD - Direct access
int array_access_raw(int arr[], int index, int size) {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    return -1; // Error indicator
}

// BUILT-IN METHOD - Using pointer arithmetic
int array_access_builtin(int *arr, int index, int size) {
    if (index >= 0 && index < size) {
        return *(arr + index);
    }
    return -1; // Error indicator
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = 2;
    
    printf("Raw Access: %d\n", array_access_raw(arr, index, size));
    printf("Built-in Access: %d\n", array_access_builtin(arr, index, size));
    return 0;
}
