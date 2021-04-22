#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"

array_list *array_list_create() {
    array_list *array = NULL;
    array = malloc(sizeof(*array));
    if (array == NULL) {
        fprintf(stderr, "array_list_create failed\n");
        exit(1);
    }
    array->last = -1;
    return array;
}

void array_list_create1(array_list **list) {
    *list = malloc(sizeof(**list));
    if (*list == NULL)
        return;
    (*list)->last = -1;
    return;
}

int array_list_insert(array_list *list, int pos, datatype *element) {
    if (pos > ARRAY_SIZE)
        return -1;
    if (pos < 0 || pos > list->last + 1)
        return -2;
    for (int i = list->last; i >= pos; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[pos] = *element;
    list->last++;
    return 0;
}

int array_list_delete(array_list *list, int pos) {
    if (pos < 0 || pos > list->last)
        return -1;
    for (int i = pos; i < list->last; i++)
        list->data[i] = list->data[i + 1];
    list->last--;
    return 0;
}

int array_list_find(array_list *list, datatype *element) {
    for (int i = 0; i <= list->last; i++) {
        if (*element == list->data[i])
            return i;
    }
    return -1;
}

int array_list_is_empty(array_list *list) {
    return list->last == -1;
}

int array_list_set_empty(array_list *list) {
    list->last = -1;
    return 0;
}

int array_list_length(array_list *list) {
    return list->last + 1;
}

void array_list_display(array_list *list) {
    printf(">>> last = %d\n", list->last);
    printf(">>> data : ");
    for (int i = 0; i <= list->last; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int array_list_destroy(array_list *list) {
    free(list);
    return 0;
}

int array_list_union(array_list *dest, array_list *src) {
    if (array_list_length(dest) + array_list_length(src) > ARRAY_SIZE) {
        fprintf(stderr, "Length exceeded if union.\n");
        return -1;
    }
    if (array_list_is_empty(src)) {
        array_list_destroy(src);
        return 0;
    }
    for (int i = 0; i <= src->last; i++) {
        dest->data[dest->last + i + 1] = src->data[i];
    }
    dest->last += array_list_length(src);
    return 0;
}

