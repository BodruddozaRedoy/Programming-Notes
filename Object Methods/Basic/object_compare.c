#include <stdio.h>
#include <string.h>
#include <stdbool.h>  // ✅ required for bool

typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// RAW METHOD - Manual comparison
int compare_objects_raw(Object obj1, Object obj2) {
    if (obj1.id != obj2.id) return obj1.id - obj2.id;
    int name_cmp = strcmp(obj1.name, obj2.name);
    if (name_cmp != 0) return name_cmp;
    if (obj1.value != obj2.value) return (obj1.value > obj2.value) ? 1 : -1;
    return 0;
}

// BUILT-IN METHOD - Using function pointers (qsort-compatible)
int compare_objects_builtin(const void *a, const void *b) {
    const Object *obj1 = (const Object *)a;
    const Object *obj2 = (const Object *)b;
    
    if (obj1->id != obj2->id) return obj1->id - obj2->id;
    int name_cmp = strcmp(obj1->name, obj2->name);
    if (name_cmp != 0) return name_cmp;
    if (obj1->value != obj2->value) return (obj1->value > obj2->value) ? 1 : -1;
    return 0;
}

// RAW equality check
bool objects_equal_raw(Object obj1, Object obj2) {
    return (obj1.id == obj2.id && 
            strcmp(obj1.name, obj2.name) == 0 && 
            obj1.value == obj2.value);
}

// BUILT-IN equality check (pointer-based)
bool objects_equal_builtin(const Object *obj1, const Object *obj2) {
    return (obj1->id == obj2->id && 
            strcmp(obj1->name, obj2->name) == 0 && 
            obj1->value == obj2->value);
}

int main(void) {
    Object obj1 = {1, "Object A", 100.0};
    Object obj2 = {2, "Object B", 200.0};
    Object obj3 = {1, "Object A", 100.0};

    printf("Raw Compare (obj1 vs obj2): %d\n", compare_objects_raw(obj1, obj2));
    printf("Raw Compare (obj1 vs obj3): %d\n", compare_objects_raw(obj1, obj3));

    printf("Built-in Compare (obj1 vs obj2): %d\n", compare_objects_builtin(&obj1, &obj2));
    printf("Built-in Compare (obj1 vs obj3): %d\n", compare_objects_builtin(&obj1, &obj3));

    printf("Raw Equal (obj1 vs obj3): %s\n", objects_equal_raw(obj1, obj3) ? "Yes" : "No");
    printf("Built-in Equal (obj1 vs obj3): %s\n", objects_equal_builtin(&obj1, &obj3) ? "Yes" : "No");

    return 0;
}
