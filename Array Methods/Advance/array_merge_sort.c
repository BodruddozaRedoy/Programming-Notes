#include <stdio.h>
#include <stdlib.h>

// RAW METHOD - Merge Sort implementation
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_raw(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_raw(arr, left, mid);
        merge_sort_raw(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// BUILT-IN METHOD - Using qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void merge_sort_builtin(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    merge_sort_raw(arr1, 0, size - 1);
    printf("Raw Merge Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    merge_sort_builtin(arr2, size);
    printf("Built-in Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}
