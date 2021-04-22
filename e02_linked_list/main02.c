#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    list *l = linked_list_create();

    linked_list_insert_at(l, 0, 10);

    for (int i = 0; i < 6; i++) {
        linked_list_append(l, arr[i]);
    }

    linked_list_insert_at(l, 0, 11);
    linked_list_insert_at(l, 4, 12);

    linked_list_display(l);

    datatype *deleted = malloc(sizeof(*deleted));
    linked_list_delete(l, deleted);
    printf("deleted: %d\n", *deleted);
    linked_list_delete_at(l, 4, deleted);
    printf("deleted at 4: %d\n", *deleted);

    linked_list_display(l);

    linked_list_destroy(l);

    exit(0);
}