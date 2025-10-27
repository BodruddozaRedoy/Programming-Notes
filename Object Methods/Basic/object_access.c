#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// RAW METHOD - Direct property access
int get_id_raw(Object obj) {
    return obj.id;
}

char* get_name_raw(Object obj) {
    return obj.name;
}

float get_value_raw(Object obj) {
    return obj.value;
}

// BUILT-IN METHOD - Using pointers
int get_id_builtin(Object* obj) {
    return obj->id;
}

char* get_name_builtin(Object* obj) {
    return obj->name;
}

float get_value_builtin(Object* obj) {
    return obj->value;
}

// Property modification
void set_id_raw(Object* obj, int id) {
    obj->id = id;
}

void set_name_raw(Object* obj, char name[]) {
    strcpy(obj->name, name);
}

void set_value_raw(Object* obj, float value) {
    obj->value = value;
}

int main() {
    Object obj = {1, "Test Object", 99.99};
    
    printf("Raw Access - ID: %d, Name: %s, Value: %.2f\n", 
           get_id_raw(obj), get_name_raw(obj), get_value_raw(obj));
    
    printf("Built-in Access - ID: %d, Name: %s, Value: %.2f\n", 
           get_id_builtin(&obj), get_name_builtin(&obj), get_value_builtin(&obj));
    
    set_id_raw(&obj, 100);
    set_name_raw(&obj, "Modified Object");
    set_value_raw(&obj, 199.99);
    
    printf("After Modification - ID: %d, Name: %s, Value: %.2f\n", 
           obj.id, obj.name, obj.value);
    return 0;
}
