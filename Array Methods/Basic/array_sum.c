#include <stdio.h>

// RAW METHOD - Manual sum calculation
int array_sum_raw(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// BUILT-IN METHOD - Using pointer arithmetic
int array_sum_builtin(int *arr, int size) {
    int sum = 0;
    int *ptr = arr;
    for (int i = 0; i < size; i++) {
        sum += *ptr++;
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Raw Sum: %d\n", array_sum_raw(arr, size));
    printf("Built-in Sum: %d\n", array_sum_builtin(arr, size));
    return 0;
}
