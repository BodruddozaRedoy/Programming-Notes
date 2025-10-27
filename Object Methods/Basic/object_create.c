#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RAW METHOD - Manual object creation
typedef struct {
    int id;
    char name[50];
    float value;
} Object;

Object create_object_raw(int id, char name[], float value) {
    Object obj;
    obj.id = id;
    strcpy(obj.name, name);
    obj.value = value;
    return obj;
}

// BUILT-IN METHOD - Using malloc and initialization
Object* create_object_builtin(int id, char name[], float value) {
    Object* obj = (Object*)malloc(sizeof(Object));
    if (obj != NULL) {
        obj->id = id;
        strcpy(obj->name, name);
        obj->value = value;
    }
    return obj;
}

void print_object(Object obj) {
    printf("ID: %d, Name: %s, Value: %.2f\n", obj.id, obj.name, obj.value);
}

void print_object_ptr(Object* obj) {
    printf("ID: %d, Name: %s, Value: %.2f\n", obj->id, obj->name, obj->value);
}

int main() {
    // Raw method
    Object obj1 = create_object_raw(1, "Test Object", 99.99);
    printf("Raw Object: ");
    print_object(obj1);
    
    // Built-in method
    Object* obj2 = create_object_builtin(2, "Dynamic Object", 149.99);
    printf("Built-in Object: ");
    print_object_ptr(obj2);
    
    free(obj2);
    return 0;
}
