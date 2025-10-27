#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// RAW METHOD - Simple hash function
unsigned int hash_object_raw(Object obj) {
    unsigned int hash = 0;
    hash = hash * 31 + obj.id;
    
    for (int i = 0; obj.name[i] != '\0'; i++) {
        hash = hash * 31 + obj.name[i];
    }
    
    // Convert float to int for hashing
    int value_int = (int)(obj.value * 100);
    hash = hash * 31 + value_int;
    
    return hash;
}

// BUILT-IN METHOD - Using djb2 hash algorithm
unsigned int hash_object_builtin(Object obj) {
    unsigned int hash = 5381;
    
    // Hash ID
    hash = ((hash << 5) + hash) + obj.id;
    
    // Hash name using djb2
    for (int i = 0; obj.name[i] != '\0'; i++) {
        hash = ((hash << 5) + hash) + obj.name[i];
    }
    
    // Hash value
    int value_int = (int)(obj.value * 100);
    hash = ((hash << 5) + hash) + value_int;
    
    return hash;
}

// Hash table implementation
typedef struct {
    Object key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode** buckets;
    int size;
} HashTable;

HashTable* create_hash_table(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->buckets = (HashNode**)calloc(size, sizeof(HashNode*));
    table->size = size;
    return table;
}

int get_bucket_index(HashTable* table, Object key) {
    return hash_object_builtin(key) % table->size;
}

void insert_object(HashTable* table, Object key, int value) {
    int index = get_bucket_index(table, key);
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node->key = key;
    new_node->value = value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

int get_object_value(HashTable* table, Object key) {
    int index = get_bucket_index(table, key);
    HashNode* current = table->buckets[index];
    
    while (current != NULL) {
        if (current->key.id == key.id && 
            strcmp(current->key.name, key.name) == 0 &&
            current->key.value == key.value) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Not found
}

void print_object(Object* obj) {
    printf("ID: %d, Name: %s, Value: %.2f\n", obj->id, obj->name, obj->value);
}

int main() {
    Object obj1 = {1, "Alice", 100.0};
    Object obj2 = {2, "Bob", 200.0};
    Object obj3 = {3, "Charlie", 300.0};
    
    // Raw hash
    printf("Raw Hash for obj1: %u\n", hash_object_raw(obj1));
    printf("Raw Hash for obj2: %u\n", hash_object_raw(obj2));
    printf("Raw Hash for obj3: %u\n", hash_object_raw(obj3));
    
    // Built-in hash
    printf("Built-in Hash for obj1: %u\n", hash_object_builtin(obj1));
    printf("Built-in Hash for obj2: %u\n", hash_object_builtin(obj2));
    printf("Built-in Hash for obj3: %u\n", hash_object_builtin(obj3));
    
    // Hash table usage
    HashTable* table = create_hash_table(10);
    insert_object(table, obj1, 1000);
    insert_object(table, obj2, 2000);
    insert_object(table, obj3, 3000);
    
    printf("\nHash Table Lookup:\n");
    printf("Value for obj1: %d\n", get_object_value(table, obj1));
    printf("Value for obj2: %d\n", get_object_value(table, obj2));
    printf("Value for obj3: %d\n", get_object_value(table, obj3));
    
    // Cleanup
    for (int i = 0; i < table->size; i++) {
        HashNode* current = table->buckets[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
    
    return 0;
}
