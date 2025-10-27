#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// RAW METHOD - Manual serialization
char* serialize_object_raw(Object obj) {
    char* buffer = (char*)malloc(200 * sizeof(char));
    if (buffer != NULL) {
        sprintf(buffer, "ID:%d|NAME:%s|VALUE:%.2f", obj.id, obj.name, obj.value);
    }
    return buffer;
}

Object deserialize_object_raw(char* data) {
    Object obj = {0, "", 0.0};
    char* token = strtok(data, "|");
    
    while (token != NULL) {
        if (strncmp(token, "ID:", 3) == 0) {
            obj.id = atoi(token + 3);
        } else if (strncmp(token, "NAME:", 5) == 0) {
            strcpy(obj.name, token + 5);
        } else if (strncmp(token, "VALUE:", 6) == 0) {
            obj.value = atof(token + 6);
        }
        token = strtok(NULL, "|");
    }
    return obj;
}

// BUILT-IN METHOD - Using binary serialization
void serialize_object_builtin(Object obj, FILE* file) {
    fwrite(&obj, sizeof(Object), 1, file);
}

Object deserialize_object_builtin(FILE* file) {
    Object obj;
    fread(&obj, sizeof(Object), 1, file);
    return obj;
}

// JSON-like serialization
char* serialize_to_json_raw(Object obj) {
    char* buffer = (char*)malloc(200 * sizeof(char));
    if (buffer != NULL) {
        sprintf(buffer, "{\"id\":%d,\"name\":\"%s\",\"value\":%.2f}", 
                obj.id, obj.name, obj.value);
    }
    return buffer;
}

void print_object(Object* obj) {
    printf("ID: %d, Name: %s, Value: %.2f\n", obj->id, obj->name, obj->value);
}

int main() {
    Object obj = {1, "Test Object", 99.99};
    
    // Raw serialization
    char* serialized = serialize_object_raw(obj);
    printf("Raw Serialized: %s\n", serialized);
    
    Object deserialized = deserialize_object_raw(serialized);
    printf("Raw Deserialized: ");
    print_object(&deserialized);
    
    // Built-in serialization
    FILE* file = fopen("object.dat", "wb");
    if (file != NULL) {
        serialize_object_builtin(obj, file);
        fclose(file);
        
        file = fopen("object.dat", "rb");
        if (file != NULL) {
            Object deserialized2 = deserialize_object_builtin(file);
            printf("Built-in Deserialized: ");
            print_object(&deserialized2);
            fclose(file);
        }
    }
    
    // JSON-like serialization
    char* json = serialize_to_json_raw(obj);
    printf("JSON Serialized: %s\n", json);
    
    free(serialized);
    free(json);
    return 0;
}
