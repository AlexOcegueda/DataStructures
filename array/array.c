#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *numbers; 
};

int main(void) {

    struct Array array;
    struct Array *a1 = &array; // pointer to first array
    
    array.numbers = malloc(5*sizeof(int));

    a1->numbers[0] = 1;
    printf("%d\n", a1->numbers[0]);
    
    array.numbers[1] = 2;
    printf("%d\n", array.numbers[1]);
    
    return 0;
}
