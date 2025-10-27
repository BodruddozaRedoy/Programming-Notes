#include <stdio.h>

// RAW METHOD - Manual reverse
void array_reverse_raw(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// BUILT-IN METHOD - Using pointer arithmetic
void array_reverse_builtin(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    array_reverse_raw(arr1, size);
    printf("Raw Reverse: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    array_reverse_builtin(arr2, size);
    printf("Built-in Reverse: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}
