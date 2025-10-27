#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// RAW METHOD - Manual sorting by different fields
void sort_by_id_raw(Object* objects, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (objects[j].id > objects[j + 1].id) {
                Object temp = objects[j];
                objects[j] = objects[j + 1];
                objects[j + 1] = temp;
            }
        }
    }
}

void sort_by_name_raw(Object* objects, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(objects[j].name, objects[j + 1].name) > 0) {
                Object temp = objects[j];
                objects[j] = objects[j + 1];
                objects[j + 1] = temp;
            }
        }
    }
}

void sort_by_value_raw(Object* objects, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (objects[j].value > objects[j + 1].value) {
                Object temp = objects[j];
                objects[j] = objects[j + 1];
                objects[j + 1] = temp;
            }
        }
    }
}

// BUILT-IN METHOD - Using qsort with comparison functions
int compare_by_id(const void* a, const void* b) {
    Object* obj1 = (Object*)a;
    Object* obj2 = (Object*)b;
    return obj1->id - obj2->id;
}

int compare_by_name(const void* a, const void* b) {
    Object* obj1 = (Object*)a;
    Object* obj2 = (Object*)b;
    return strcmp(obj1->name, obj2->name);
}

int compare_by_value(const void* a, const void* b) {
    Object* obj1 = (Object*)a;
    Object* obj2 = (Object*)b;
    if (obj1->value > obj2->value) return 1;
    if (obj1->value < obj2->value) return -1;
    return 0;
}

void sort_by_id_builtin(Object* objects, int size) {
    qsort(objects, size, sizeof(Object), compare_by_id);
}

void sort_by_name_builtin(Object* objects, int size) {
    qsort(objects, size, sizeof(Object), compare_by_name);
}

void sort_by_value_builtin(Object* objects, int size) {
    qsort(objects, size, sizeof(Object), compare_by_value);
}

void print_objects(Object* objects, int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Value: %.2f\n", 
               objects[i].id, objects[i].name, objects[i].value);
    }
}

int main() {
    Object objects[] = {
        {3, "Charlie", 300.0},
        {1, "Alice", 100.0},
        {2, "Bob", 200.0}
    };
    int size = sizeof(objects) / sizeof(objects[0]);
    
    printf("Original:\n");
    print_objects(objects, size);
    
    printf("\nSorted by ID (Raw):\n");
    sort_by_id_raw(objects, size);
    print_objects(objects, size);
    
    printf("\nSorted by Name (Built-in):\n");
    sort_by_name_builtin(objects, size);
    print_objects(objects, size);
    
    printf("\nSorted by Value (Built-in):\n");
    sort_by_value_builtin(objects, size);
    print_objects(objects, size);
    
    return 0;
}
