#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// RAW METHOD - Linear search
int search_by_id_raw(Object* objects, int size, int target_id) {
    for (int i = 0; i < size; i++) {
        if (objects[i].id == target_id) {
            return i;
        }
    }
    return -1;
}

int search_by_name_raw(Object* objects, int size, char* target_name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(objects[i].name, target_name) == 0) {
            return i;
        }
    }
    return -1;
}

Object* search_by_value_raw(Object* objects, int size, float target_value) {
    for (int i = 0; i < size; i++) {
        if (objects[i].value == target_value) {
            return &objects[i];
        }
    }
    return NULL;
}

// BUILT-IN METHOD - Using bsearch (requires sorted array)
int compare_by_id(const void* a, const void* b) {
    Object* obj1 = (Object*)a;
    Object* obj2 = (Object*)b;
    return obj1->id - obj2->id;
}

int search_by_id_builtin(Object* objects, int size, int target_id) {
    Object* result = (Object*)bsearch(&target_id, objects, size, sizeof(Object), compare_by_id);
    if (result != NULL) {
        return result - objects;
    }
    return -1;
}

// Binary search for sorted array
int binary_search_by_id(Object* objects, int left, int right, int target_id) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (objects[mid].id == target_id) return mid;
        if (objects[mid].id > target_id) 
            return binary_search_by_id(objects, left, mid - 1, target_id);
        return binary_search_by_id(objects, mid + 1, right, target_id);
    }
    return -1;
}

void print_object(Object* obj) {
    printf("ID: %d, Name: %s, Value: %.2f\n", obj->id, obj->name, obj->value);
}

int main() {
    Object objects[] = {
        {1, "Alice", 100.0},
        {2, "Bob", 200.0},
        {3, "Charlie", 300.0},
        {4, "David", 400.0}
    };
    int size = sizeof(objects) / sizeof(objects[0]);
    
    // Search by ID
    int target_id = 3;
    int index1 = search_by_id_raw(objects, size, target_id);
    printf("Raw search for ID %d: Index %d\n", target_id, index1);
    if (index1 != -1) print_object(&objects[index1]);
    
    // Search by name
    char* target_name = "Bob";
    int index2 = search_by_name_raw(objects, size, target_name);
    printf("Raw search for name '%s': Index %d\n", target_name, index2);
    if (index2 != -1) print_object(&objects[index2]);
    
    // Search by value
    float target_value = 200.0;
    Object* result = search_by_value_raw(objects, size, target_value);
    printf("Raw search for value %.2f: ", target_value);
    if (result != NULL) print_object(result);
    else printf("Not found\n");
    
    // Built-in search (requires sorted array)
    qsort(objects, size, sizeof(Object), compare_by_id);
    int index3 = search_by_id_builtin(objects, size, target_id);
    printf("Built-in search for ID %d: Index %d\n", target_id, index3);
    if (index3 != -1) print_object(&objects[index3]);
    
    return 0;
}
