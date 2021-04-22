#ifndef LINKED_LIST_H__
#define LINKED_LIST_H__

typedef int datatype;

typedef struct linked_node {
    datatype element;
    struct linked_node *next;
} list;

list *linked_list_create();

int linked_list_insert_at(list *, int, datatype);
int linked_list_append(list *, datatype);

int linked_list_delete_at(list *, int, datatype *);
int linked_list_delete(list *, datatype *);

int linked_list_is_empty(list *);

void linked_list_display(list *);

void linked_list_destroy(list *);

#endif