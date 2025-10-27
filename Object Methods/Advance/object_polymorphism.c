#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Base Object structure
typedef struct {
    int id;
    char name[50];
    float value;
} Object;

// Function pointer types for polymorphism
typedef void (*PrintFunction)(void* obj);
typedef float (*CalculateFunction)(void* obj);
typedef void (*UpdateFunction)(void* obj, float delta);

// Extended Object with polymorphism
typedef struct {
    Object base;
    PrintFunction print;
    CalculateFunction calculate;
    UpdateFunction update;
} PolymorphicObject;

// Different object types
typedef struct {
    Object base;
    float multiplier;
} MultiplierObject;

typedef struct {
    Object base;
    float divisor;
} DivisorObject;

// Print functions
void print_multiplier(void* obj) {
    MultiplierObject* m_obj = (MultiplierObject*)obj;
    printf("MultiplierObject - ID: %d, Name: %s, Value: %.2f, Multiplier: %.2f\n",
           m_obj->base.id, m_obj->base.name, m_obj->base.value, m_obj->multiplier);
}

void print_divisor(void* obj) {
    DivisorObject* d_obj = (DivisorObject*)obj;
    printf("DivisorObject - ID: %d, Name: %s, Value: %.2f, Divisor: %.2f\n",
           d_obj->base.id, d_obj->base.name, d_obj->base.value, d_obj->divisor);
}

// Calculate functions
float calculate_multiplier(void* obj) {
    MultiplierObject* m_obj = (MultiplierObject*)obj;
    return m_obj->base.value * m_obj->multiplier;
}

float calculate_divisor(void* obj) {
    DivisorObject* d_obj = (DivisorObject*)obj;
    return d_obj->base.value / d_obj->divisor;
}

// Update functions
void update_multiplier(void* obj, float delta) {
    MultiplierObject* m_obj = (MultiplierObject*)obj;
    m_obj->base.value += delta;
    m_obj->multiplier += delta * 0.1;
}

void update_divisor(void* obj, float delta) {
    DivisorObject* d_obj = (DivisorObject*)obj;
    d_obj->base.value += delta;
    d_obj->divisor += delta * 0.05;
}

// Factory functions
PolymorphicObject* create_multiplier_object(int id, char name[], float value, float multiplier) {
    MultiplierObject* m_obj = (MultiplierObject*)malloc(sizeof(MultiplierObject));
    m_obj->base.id = id;
    strcpy(m_obj->base.name, name);
    m_obj->base.value = value;
    m_obj->multiplier = multiplier;
    
    PolymorphicObject* p_obj = (PolymorphicObject*)malloc(sizeof(PolymorphicObject));
    p_obj->base = m_obj->base;
    p_obj->print = print_multiplier;
    p_obj->calculate = calculate_multiplier;
    p_obj->update = update_multiplier;
    
    free(m_obj);
    return p_obj;
}

PolymorphicObject* create_divisor_object(int id, char name[], float value, float divisor) {
    DivisorObject* d_obj = (DivisorObject*)malloc(sizeof(DivisorObject));
    d_obj->base.id = id;
    strcpy(d_obj->base.name, name);
    d_obj->base.value = value;
    d_obj->divisor = divisor;
    
    PolymorphicObject* p_obj = (PolymorphicObject*)malloc(sizeof(PolymorphicObject));
    p_obj->base = d_obj->base;
    p_obj->print = print_divisor;
    p_obj->calculate = calculate_divisor;
    p_obj->update = update_divisor;
    
    free(d_obj);
    return p_obj;
}

// Generic operations
void process_object(PolymorphicObject* obj) {
    printf("Processing object:\n");
    obj->print(obj);
    float result = obj->calculate(obj);
    printf("Calculation result: %.2f\n", result);
    obj->update(obj, 10.0);
    printf("After update:\n");
    obj->print(obj);
    printf("New calculation result: %.2f\n", obj->calculate(obj));
    printf("\n");
}

int main() {
    // Create different types of objects
    PolymorphicObject* obj1 = create_multiplier_object(1, "Multiplier", 100.0, 2.5);
    PolymorphicObject* obj2 = create_divisor_object(2, "Divisor", 200.0, 4.0);
    
    // Process objects polymorphically
    process_object(obj1);
    process_object(obj2);
    
    // Cleanup
    free(obj1);
    free(obj2);
    
    return 0;
}
