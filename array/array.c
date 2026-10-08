#include <stdio.h>
#include <stdlib.h>
/*
 * insert, remove
 */
struct Array {
    int *numbers; 
    int size;
    int capacity;
};

struct Array array_init(int capacity) {
    struct Array array;
    array.numbers = malloc(capacity * sizeof(int));
    array.size = 0;
    array.capacity = capacity;
    return array;
};

void array_set(struct Array *arr, int position, int value) {
    arr->numbers[position] = value;  
};

int array_get(struct Array *arr, int position) { 
    return arr->numbers[position];
};

void array_free(struct Array *arr) {
    free(arr->numbers);
    arr->numbers = NULL;
}

struct Array resize(struct Array *arr) {
    struct Array new_array = array_init(arr->capacity * 2);
    
    new_array.size = arr->size;

    for (int i = 0; i < arr->size; i++) {
        array_set(&new_array, i, arr->numbers[i]);
    };
    array_free(arr);
    return new_array;
};

// Pushes num to end of array
void push(struct Array *arr, int n) {
    if (arr->size == arr->capacity) {
        *arr = resize(arr);
    };
    array_set(arr, arr->size, n);
    arr->size++;
};

int pop(struct Array *arr) {
    int x = array_get(arr, arr->size - 1);
    arr->size--;
    return x;
};

void insert(struct Array *arr, int position, int value) {
    
    if (arr->size == arr->capacity) {
       *arr = resize(arr);
    };
    
    for (int i = arr->size; i > position; i--) {
        arr->numbers[i] = arr->numbers[i-1];
    };
    
    array_set(arr, position, value);
    arr->size++;
};

void remove(struct Array *arr, int position) {
    
};

void print_array(struct Array *arr) { 
    for (int i = 0; i < arr->size; i++) { 
        printf("%d\n", arr->numbers[i]);
    };
};

int main(void) {

    struct Array array = array_init(5);
    struct Array *p = &array;

    push(p, 67);
    push(p, 42);
    push(p, 99);
    push(p, 102);

    printf("size: %d\n", p->size);
    printf("capacity: %d\n", p->capacity);
    print_array(p);
    //printf("%d\n", array_get(p, 0));
    //printf("%d\n", array_get(p, 1));
    //printf("%d\n", array_get(p, 2));

    //int popped = pop(p);

    //printf("popped: %d\n", popped);
    //printf("size after pop: %d\n", p->size);

    insert(p, 1, 33);
    
    print_array(p);
    array_free(p);

    return 0;
};
