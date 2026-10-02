#include <stdio.h>

struct Array {
    int length;
    int *numbers = malloc(size * sizeof(int));
}

int main(void) {

    struct Array *array = malloc(sizeof(struct Array));

    array[0] = 1;

    printf(array[0]);

    return 0;
}
