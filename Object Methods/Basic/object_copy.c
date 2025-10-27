#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// RAW METHOD - Manual copy
Object copy_object_raw(Object source) {
    Object dest;
    dest.id = source.id;
    strcpy(dest.name, source.name);
    dest.value = source.value;
    return dest;
}

// BUILT-IN METHOD - Using memcpy
Object* copy_object_builtin(Object* source) {
    Object* dest = (Object*)malloc(sizeof(Object));
    if (dest != NULL) {
        memcpy(dest, source, sizeof(Object));
    }
    return dest;
}

// Deep copy with dynamic memory
Object* deep_copy_raw(Object* source) {
    Object* dest = (Object*)malloc(sizeof(Object));
    if (dest != NULL) {
        dest->id = source->id;
        strcpy(dest->name, source->name);
        dest->value = source->value;
    }
    return dest;
}

void print_object(Object* obj) {
    printf("ID: %d, Name: %s, Value: %.2f\n", obj->id, obj->name, obj->value);
}

int main() {
    Object source = {1, "Source Object", 99.99};
    
    // Raw copy
    Object dest1 = copy_object_raw(source);
    printf("Raw Copy: ");
    print_object(&dest1);
    
    // Built-in copy
    Object* dest2 = copy_object_builtin(&source);
    printf("Built-in Copy: ");
    print_object(dest2);
    
    // Deep copy
    Object* dest3 = deep_copy_raw(&source);
    printf("Deep Copy: ");
    print_object(dest3);
    
    // Modify source to verify independence
    source.id = 999;
    strcpy(source.name, "Modified Source");
    source.value = 199.99;
    
    printf("After source modification:\n");
    printf("Source: ");
    print_object(&source);
    printf("Raw Copy: ");
    print_object(&dest1);
    printf("Built-in Copy: ");
    print_object(dest2);
    printf("Deep Copy: ");
    print_object(dest3);
    
    free(dest2);
    free(dest3);
    return 0;
}
