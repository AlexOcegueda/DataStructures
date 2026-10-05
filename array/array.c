#include <stdio.h>
#include <stdlib.h>
/*
 * push, pop, resize, insert, remove
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

// Pushes num to end of array
void push(struct Array *arr, int n) {
    array_set(arr, sizeof(arr->numbers)/sizeof(arr->numbers[0]), n);
};

int main(void) {

    struct Array array = array_init(5);
    struct Array *p = &array;

    //array_set(p, 0, 100);
    //printf("%d\n", array_get(p, 0));
    push(p, 67);
    printf("%d\n", array_get(p, sizeof(p->numbers)/sizeof(p->numbers[0])));
    
    

    array_free(p);
    return 0;
};
