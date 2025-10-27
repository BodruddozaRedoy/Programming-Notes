#include <stdio.h>

// RAW METHOD - Quick Sort implementation
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort_raw(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_raw(arr, low, pi - 1);
        quick_sort_raw(arr, pi + 1, high);
    }
}

// BUILT-IN METHOD - Using qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void quick_sort_builtin(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    quick_sort_raw(arr1, 0, size - 1);
    printf("Raw Quick Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    quick_sort_builtin(arr2, size);
    printf("Built-in Quick Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}
