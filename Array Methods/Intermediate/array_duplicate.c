#include <stdio.h>
#include <stdbool.h>

// RAW METHOD - Manual duplicate check
bool has_duplicates_raw(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

// BUILT-IN METHOD - Using qsort first
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool has_duplicates_builtin(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Raw - No duplicates: %s\n", has_duplicates_raw(arr1, size1) ? "Yes" : "No");
    printf("Raw - Has duplicates: %s\n", has_duplicates_raw(arr2, size2) ? "Yes" : "No");
    
    printf("Built-in - No duplicates: %s\n", has_duplicates_builtin(arr1, size1) ? "Yes" : "No");
    printf("Built-in - Has duplicates: %s\n", has_duplicates_builtin(arr2, size2) ? "Yes" : "No");
    return 0;
}
