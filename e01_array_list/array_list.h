#ifndef ARRAY_LIST_H__
#define ARRAY_LIST_H__

#define ARRAY_SIZE 1024

typedef int datatype;

typedef struct {
    datatype data[ARRAY_SIZE];
    int last;
} array_list;

array_list *array_list_create();
void array_list_create1(array_list **);
int array_list_insert(array_list *, int, datatype *);
int array_list_delete(array_list *, int);
int array_list_find(array_list *, datatype *);
int array_list_is_empty(array_list *);
int array_list_set_empty(array_list *);
int array_list_length(array_list *);
void array_list_display(array_list *);
int array_list_destroy(array_list *);
int array_list_union(array_list *, array_list *);

#endif
