#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float value;
    int* dynamic_data;
    int data_size;
} Object;

// RAW METHOD - Manual memory management
Object* create_object_raw(int id, char name[], float value, int data_size) {
    Object* obj = (Object*)malloc(sizeof(Object));
    if (obj != NULL) {
        obj->id = id;
        strcpy(obj->name, name);
        obj->value = value;
        obj->data_size = data_size;
        obj->dynamic_data = (int*)malloc(data_size * sizeof(int));
        
        if (obj->dynamic_data != NULL) {
            for (int i = 0; i < data_size; i++) {
                obj->dynamic_data[i] = i * 10;
            }
        }
    }
    return obj;
}

void destroy_object_raw(Object* obj) {
    if (obj != NULL) {
        if (obj->dynamic_data != NULL) {
            free(obj->dynamic_data);
        }
        free(obj);
    }
}

// BUILT-IN METHOD - Using memory pools
typedef struct {
    Object* objects;
    int* data_pool;
    int object_count;
    int data_count;
    int max_objects;
    int max_data;
} MemoryPool;

MemoryPool* create_memory_pool(int max_objects, int max_data) {
    MemoryPool* pool = (MemoryPool*)malloc(sizeof(MemoryPool));
    if (pool != NULL) {
        pool->objects = (Object*)calloc(max_objects, sizeof(Object));
        pool->data_pool = (int*)calloc(max_data, sizeof(int));
        pool->object_count = 0;
        pool->data_count = 0;
        pool->max_objects = max_objects;
        pool->max_data = max_data;
    }
    return pool;
}

Object* allocate_object_builtin(MemoryPool* pool, int id, char name[], float value, int data_size) {
    if (pool->object_count >= pool->max_objects || 
        pool->data_count + data_size > pool->max_data) {
        return NULL;
    }
    
    Object* obj = &pool->objects[pool->object_count];
    obj->id = id;
    strcpy(obj->name, name);
    obj->value = value;
    obj->data_size = data_size;
    obj->dynamic_data = &pool->data_pool[pool->data_count];
    
    for (int i = 0; i < data_size; i++) {
        obj->dynamic_data[i] = i * 10;
    }
    
    pool->object_count++;
    pool->data_count += data_size;
    return obj;
}

void destroy_memory_pool(MemoryPool* pool) {
    if (pool != NULL) {
        free(pool->objects);
        free(pool->data_pool);
        free(pool);
    }
}

// Memory usage tracking
void print_memory_usage(MemoryPool* pool) {
    printf("Memory Pool Usage:\n");
    printf("  Objects allocated: %d/%d\n", pool->object_count, pool->max_objects);
    printf("  Data elements used: %d/%d\n", pool->data_count, pool->max_data);
    printf("  Memory used: %.2f KB\n", 
           (pool->object_count * sizeof(Object) + pool->data_count * sizeof(int)) / 1024.0);
}

void print_object(Object* obj) {
    printf("ID: %d, Name: %s, Value: %.2f, Data: [", 
           obj->id, obj->name, obj->value);
    for (int i = 0; i < obj->data_size; i++) {
        printf("%d", obj->dynamic_data[i]);
        if (i < obj->data_size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    // Raw memory management
    printf("=== Raw Memory Management ===\n");
    Object* obj1 = create_object_raw(1, "Object 1", 100.0, 5);
    Object* obj2 = create_object_raw(2, "Object 2", 200.0, 3);
    
    if (obj1 != NULL) {
        print_object(obj1);
        destroy_object_raw(obj1);
    }
    
    if (obj2 != NULL) {
        print_object(obj2);
        destroy_object_raw(obj2);
    }
    
    // Built-in memory pool
    printf("\n=== Built-in Memory Pool ===\n");
    MemoryPool* pool = create_memory_pool(10, 100);
    
    Object* obj3 = allocate_object_builtin(pool, 3, "Pool Object 1", 300.0, 4);
    Object* obj4 = allocate_object_builtin(pool, 4, "Pool Object 2", 400.0, 6);
    
    if (obj3 != NULL) print_object(obj3);
    if (obj4 != NULL) print_object(obj4);
    
    print_memory_usage(pool);
    
    destroy_memory_pool(pool);
    
    return 0;
}
