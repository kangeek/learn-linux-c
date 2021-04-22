#include "linked_stack.h"

LINKED_STACK *linked_stack_create() {
    return dl_list_create(sizeof(int));
}

int linked_stack_push(LINKED_STACK *stack, const void *element) {
    return dl_list_insert(stack, element, INSERT_BACKWARD);
}

static int _always_match(const void *p1, const void *p2) {
    return 0;
}

int linked_stack_pop(LINKED_STACK *stack, void *data) {
    return dl_list_fetch(stack, (void *) 0, _always_match, data);
}

void linked_stack_destroy(LINKED_STACK *stack) {
    dl_list_destroy(stack);
}

