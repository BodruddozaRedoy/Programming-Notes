#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // ✅ Required for bool type

// Define object structure
typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// Define filtered array structure
typedef struct {
    Object* objects;
    int size;
    int capacity;
} FilteredArray;

// ----------------------
// RAW METHOD - Manual filtering
// ----------------------
FilteredArray* filter_by_value_raw(Object* objects, int size, float min_value) {
    FilteredArray* result = (FilteredArray*)malloc(sizeof(FilteredArray));
    result->objects = (Object*)malloc(size * sizeof(Object));
    result->size = 0;
    result->capacity = size;
    
    for (int i = 0; i < size; i++) {
        if (objects[i].value >= min_value) {
            result->objects[result->size++] = objects[i];
        }
    }
    return result;
}

FilteredArray* filter_by_name_length_raw(Object* objects, int size, int min_length) {
    FilteredArray* result = (FilteredArray*)malloc(sizeof(FilteredArray));
    result->objects = (Object*)malloc(size * sizeof(Object));
    result->size = 0;
    result->capacity = size;
    
    for (int i = 0; i < size; i++) {
        if ((int)strlen(objects[i].name) >= min_length) {
            result->objects[result->size++] = objects[i];
        }
    }
    return result;
}

// ----------------------
// BUILT-IN METHOD - Using function pointers
// ----------------------
typedef bool (*FilterFunction)(Object* obj);

bool value_filter(Object* obj) {
    return obj->value >= 200.0f;
}

bool name_length_filter(Object* obj) {
    return strlen(obj->name) >= 4;
}

FilteredArray* filter_objects_builtin(Object* objects, int size, FilterFunction filter_func) {
    FilteredArray* result = (FilteredArray*)malloc(sizeof(FilteredArray));
    result->objects = (Object*)malloc(size * sizeof(Object));
    result->size = 0;
    result->capacity = size;
    
    for (int i = 0; i < size; i++) {
        if (filter_func(&objects[i])) {
            result->objects[result->size++] = objects[i];
        }
    }
    return result;
}

// ----------------------
// Helper Functions
// ----------------------
void print_filtered_array(FilteredArray* arr) {
    printf("Filtered Array (Size: %d):\n", arr->size);
    for (int i = 0; i < arr->size; i++) {
        printf("  [%d] ID: %d, Name: %s, Value: %.2f\n", 
               i, arr->objects[i].id, arr->objects[i].name, arr->objects[i].value);
    }
}

void free_filtered_array(FilteredArray* arr) {
    if (arr) {
        free(arr->objects);
        free(arr);
    }
}

// ----------------------
// MAIN FUNCTION
// ----------------------
int main(void) {
    Object objects[] = {
        {1, "Alice", 100.0},
        {2, "Bob", 200.0},
        {3, "Charlie", 300.0},
        {4, "David", 400.0},
        {5, "Eve", 150.0}
    };
    int size = sizeof(objects) / sizeof(objects[0]);
    
    printf("Original Objects:\n");
    for (int i = 0; i < size; i++) {
        printf("  [%d] ID: %d, Name: %s, Value: %.2f\n", 
               i, objects[i].id, objects[i].name, objects[i].value);
    }
    
    // Filter by value (raw)
    FilteredArray* filtered1 = filter_by_value_raw(objects, size, 200.0f);
    printf("\nFiltered by value >= 200.0 (Raw):\n");
    print_filtered_array(filtered1);
    
    // Filter by name length (raw)
    FilteredArray* filtered2 = filter_by_name_length_raw(objects, size, 4);
    printf("\nFiltered by name length >= 4 (Raw):\n");
    print_filtered_array(filtered2);
    
    // Filter using function pointers (built-in)
    FilteredArray* filtered3 = filter_objects_builtin(objects, size, value_filter);
    printf("\nFiltered by value >= 200.0 (Built-in):\n");
    print_filtered_array(filtered3);
    
    FilteredArray* filtered4 = filter_objects_builtin(objects, size, name_length_filter);
    printf("\nFiltered by name length >= 4 (Built-in):\n");
    print_filtered_array(filtered4);
    
    // Cleanup
    free_filtered_array(filtered1);
    free_filtered_array(filtered2);
    free_filtered_array(filtered3);
    free_filtered_array(filtered4);
    
    return 0;
}
