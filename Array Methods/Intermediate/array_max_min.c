#include <stdio.h>
#include <limits.h>

// RAW METHOD - Manual max/min finding
int array_max_raw(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int array_min_raw(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// BUILT-IN METHOD - Using qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int array_max_builtin(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
    return arr[size - 1];
}

int array_min_builtin(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
    return arr[0];
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Raw Max: %d\n", array_max_raw(arr, size));
    printf("Raw Min: %d\n", array_min_raw(arr, size));
    
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    printf("Built-in Max: %d\n", array_max_builtin(arr2, size));
    printf("Built-in Min: %d\n", array_min_builtin(arr2, size));
    return 0;
}
