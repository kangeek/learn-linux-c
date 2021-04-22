#include <stdio.h>
#include <stdlib.h>

#include "array_stack.h"

array_stack *array_stack_create(void){
    array_stack *st;

    st = malloc(sizeof(*st));
    if (st == NULL)
        return NULL;

    st->top = -1;
    return st;
}
int array_stack_empty(array_stack *st) {
    return (st->top == -1);
}
int array_stack_push(array_stack *st, datatype *element){
    if (st->top == (MAX_SIZE-1))
        return -1;

    st->data[++st->top] = *element;
    return 0;
}
int array_stack_pop(array_stack *st, datatype *data) {
    if (st->top == -1)
        return -1;

    *data = st->data[st->top--];
    return 0;
}
int array_stack_top(array_stack *st, datatype *data) {
    if (st->top == -1)
        return -1;

    *data = st->data[st->top];
    return 0;
}
void array_stack_travel(array_stack *st) {
    if (array_stack_empty(st))
        return;

    for (int i = 0; i <= st->top; ++i) {
        printf("%d ", st->data[i]);
    }
    printf("\n");
}
void array_stack_destroy(array_stack *st) {
    free(st);
}
