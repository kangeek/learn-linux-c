#include <stdio.h>
#include <stdlib.h>

#include "linked_stack.h"

int main() {

    int numbers[4] = {15, 26, 39, 28};
    LINKED_STACK *st = linked_stack_create();
    if (st == NULL)
        exit(1);

    for (int i = 0; i < 4; ++i) {
        linked_stack_push(st, numbers + i);
    }

    int popped;
    for (int i = 0; i < 4; ++i) {
        linked_stack_pop(st, &popped);
        printf("pop: %d\n", popped);
    }

    linked_stack_destroy(st);

    exit(0);
}