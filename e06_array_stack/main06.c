#include <stdio.h>
#include <stdlib.h>

#include "array_stack.h"

int main(void) {

    datatype numbers[4] = {15, 26, 39, 28};
    array_stack *st = array_stack_create();
    if (st == NULL)
        exit(1);

    for (int i = 0; i < 4; ++i) {
        array_stack_push(st, numbers + i);
    }

    array_stack_travel(st);

    datatype popped;
    array_stack_pop(st, &popped);
    printf("pop: %d\n", popped);

    array_stack_travel(st);

    array_stack_destroy(st);
}