#include <stdio.h>

// RAW METHOD - Binary search implementation
int binary_search_raw(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] > target)
            return binary_search_raw(arr, left, mid - 1, target);
        
        return binary_search_raw(arr, mid + 1, right, target);
    }
    return -1;
}

// BUILT-IN METHOD - Using bsearch
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binary_search_builtin(int arr[], int size, int target) {
    int *result = (int*)bsearch(&target, arr, size, sizeof(int), compare);
    if (result != NULL) {
        return result - arr;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 40;
    
    int result1 = binary_search_raw(arr, 0, size - 1, target);
    printf("Raw Binary Search Index: %d\n", result1);
    
    int result2 = binary_search_builtin(arr, size, target);
    printf("Built-in Binary Search Index: %d\n", result2);
    return 0;
}
