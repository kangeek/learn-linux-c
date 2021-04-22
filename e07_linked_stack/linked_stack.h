#ifndef LINKED_SATCK_H__
#define LINKED_SATCK_H__

#include "dllist_lib.h"

typedef DL_LIST LINKED_STACK;

LINKED_STACK *linked_stack_create();

int linked_stack_push(LINKED_STACK *stack, const void *element);

int linked_stack_pop(LINKED_STACK *stack, void *data);

void linked_stack_destroy(LINKED_STACK *stack);

#endif