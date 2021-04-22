#ifndef ARRAY_STACK_H__
#define ARRAY_STACK_H__

#define MAX_SIZE 5

typedef int datatype;

typedef struct node_st {
    datatype data[MAX_SIZE];
    int top;
} array_stack;

array_stack *array_stack_create(void);
int array_stack_empty(array_stack *);
int array_stack_push(array_stack *, datatype *);
int array_stack_pop(array_stack *, datatype *);
int array_stack_top(array_stack *, datatype *);
void array_stack_travel(array_stack *);
void array_stack_destroy(array_stack *);

#endif