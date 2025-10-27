#include <stdio.h>

// RAW METHOD - Array rotation
void rotate_left_raw(int arr[], int size, int positions) {
    for (int i = 0; i < positions; i++) {
        int temp = arr[0];
        for (int j = 0; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}

void rotate_right_raw(int arr[], int size, int positions) {
    for (int i = 0; i < positions; i++) {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

// BUILT-IN METHOD - Using reverse technique
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate_left_builtin(int arr[], int size, int positions) {
    positions = positions % size;
    reverse(arr, 0, positions - 1);
    reverse(arr, positions, size - 1);
    reverse(arr, 0, size - 1);
}

void rotate_right_builtin(int arr[], int size, int positions) {
    positions = positions % size;
    reverse(arr, 0, size - 1);
    reverse(arr, 0, positions - 1);
    reverse(arr, positions, size - 1);
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int positions = 2;
    
    rotate_left_raw(arr1, size, positions);
    printf("Raw Left Rotate: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    rotate_right_builtin(arr2, size, positions);
    printf("Built-in Right Rotate: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}
