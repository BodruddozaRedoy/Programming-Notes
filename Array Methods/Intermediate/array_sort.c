#include <stdio.h>
#include <stdlib.h>

// RAW METHOD - Bubble sort
void array_sort_raw(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// BUILT-IN METHOD - Using qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void array_sort_builtin(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    array_sort_raw(arr1, size);
    printf("Raw Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    array_sort_builtin(arr2, size);
    printf("Built-in Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}
