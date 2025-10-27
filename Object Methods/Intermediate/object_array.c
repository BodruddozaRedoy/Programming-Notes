#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// RAW METHOD - Manual array operations
typedef struct {
    Object* objects;
    int size;
    int capacity;
} ObjectArray;

ObjectArray* create_object_array_raw(int capacity) {
    ObjectArray* arr = (ObjectArray*)malloc(sizeof(ObjectArray));
    if (arr != NULL) {
        arr->objects = (Object*)malloc(capacity * sizeof(Object));
        arr->size = 0;
        arr->capacity = capacity;
    }
    return arr;
}

void add_object_raw(ObjectArray* arr, Object obj) {
    if (arr->size < arr->capacity) {
        arr->objects[arr->size] = obj;
        arr->size++;
    }
}

Object get_object_raw(ObjectArray* arr, int index) {
    if (index >= 0 && index < arr->size) {
        return arr->objects[index];
    }
    Object empty = {0, "", 0.0};
    return empty;
}

// BUILT-IN METHOD - Using dynamic arrays
void add_object_builtin(Object** objects, int* size, int* capacity, Object obj) {
    if (*size >= *capacity) {
        *capacity *= 2;
        *objects = (Object*)realloc(*objects, *capacity * sizeof(Object));
    }
    (*objects)[*size] = obj;
    (*size)++;
}

void print_object_array(ObjectArray* arr) {
    printf("Object Array (Size: %d, Capacity: %d):\n", arr->size, arr->capacity);
    for (int i = 0; i < arr->size; i++) {
        printf("  [%d] ID: %d, Name: %s, Value: %.2f\n", 
               i, arr->objects[i].id, arr->objects[i].name, arr->objects[i].value);
    }
}

int main() {
    // Raw method
    ObjectArray* arr1 = create_object_array_raw(5);
    Object obj1 = {1, "Object 1", 100.0};
    Object obj2 = {2, "Object 2", 200.0};
    add_object_raw(arr1, obj1);
    add_object_raw(arr1, obj2);
    print_object_array(arr1);
    
    // Built-in method
    Object* objects = (Object*)malloc(2 * sizeof(Object));
    int size = 0;
    int capacity = 2;
    add_object_builtin(&objects, &size, &capacity, obj1);
    add_object_builtin(&objects, &size, &capacity, obj2);
    
    printf("Built-in Array (Size: %d, Capacity: %d):\n", size, capacity);
    for (int i = 0; i < size; i++) {
        printf("  [%d] ID: %d, Name: %s, Value: %.2f\n", 
               i, objects[i].id, objects[i].name, objects[i].value);
    }
    
    free(arr1->objects);
    free(arr1);
    free(objects);
    return 0;
}
