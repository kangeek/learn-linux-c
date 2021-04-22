#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"

int main() {
    array_list *list;
    list = array_list_create();
    if (list == NULL) {
        fprintf(stderr, "array_list_create() failed! \n");
        exit(1);
    }

    printf("now whether list is empty: %d\n", array_list_is_empty(list));

    int a = 0, b = 1, c = 2;

    if (array_list_insert(list, 0, &a) != 0) {
        fprintf(stderr, "array_list_insert failed.\n");
        exit(1);
    }
    printf("now whether list is empty: %d\n", array_list_is_empty(list));

    if (array_list_insert(list, 1, &c) != 0) {
        fprintf(stderr, "array_list_insert failed.\n");
        exit(1);
    }
    if (array_list_insert(list, 1, &b) != 0) {
        fprintf(stderr, "array_list_insert failed.\n");
        exit(1);
    }
    array_list_display(list);

    int index = array_list_find(list, &c);
    printf("find %d at index [%d]\n", c, index);

    if (array_list_delete(list, index) != 0) {
        fprintf(stderr, "array_list_insert failed.\n");
        exit(1);
    }
    array_list_display(list);
}