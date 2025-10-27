#include <stdio.h>

// RAW METHOD - Linear search
int array_search_raw(int arr[], int target, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Not found
}

// BUILT-IN METHOD - Using bsearch (requires sorted array)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int array_search_builtin(int arr[], int target, int size) {
    int *result = (int*)bsearch(&target, arr, size, sizeof(int), compare);
    if (result != NULL) {
        return result - arr; // Calculate index
    }
    return -1; // Not found
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;
    
    printf("Raw Search Index: %d\n", array_search_raw(arr, target, size));
    
    // Sort array for built-in search
    qsort(arr, size, sizeof(int), compare);
    printf("Built-in Search Index: %d\n", array_search_builtin(arr, target, size));
    return 0;
}
