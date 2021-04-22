#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

list *linked_list_create() {
    list *head = NULL;
    head = malloc(sizeof(*head));
    if (head == NULL)
        return NULL;
    head->next = NULL;
    return head;
}

int linked_list_insert_at(list *l, int pos, datatype e) {
    if (pos < 0)
        return -1;

    list *list_node = l;
    for (int i = 0; i < pos; i++) {
        if(list_node->next == NULL) {
            return -2;
        } else {
            list_node = list_node->next;
        }
    }

    list *node = malloc(sizeof(*node));
    if (node == NULL)
        return -3;
    node->element = e;
    node->next = list_node->next;
    list_node->next = node;

    return 0;
}

int linked_list_append(list *l, datatype e) {
    list *list_node = l;
    while(list_node->next != NULL) {
        list_node = list_node->next;
    }

    list *node = malloc(sizeof(*node));
    if (node == NULL)
        return -3;
    node->element = e;
    node->next = list_node->next;
    list_node->next = node;

    return 0;
}

int linked_list_delete_at(list *l, int pos, datatype *e) {
    if (pos < 0)
        return -1;

    list *list_node = l;
    for (int i = 0; i < pos; i++) {
        if (list_node->next == NULL)
            return -2;
        else
            list_node = list_node->next;
    }
    list *deleted_node = list_node->next;
    list_node->next = list_node->next->next;
    *e = deleted_node->element;
    free(deleted_node);

    return 0;
}

int linked_list_delete(list *l, datatype *e) {
    list *list_node = l;
    while(list_node->next->next != NULL) {
        list_node = list_node->next;
    }

    *e = list_node->next->element;
    free(list_node->next);
    list_node->next = NULL;

    return 0;
}

int linked_list_is_empty(list *l) {
    return l->next == NULL;
}

void linked_list_display(list *l) {
    list *list_node = l;
    while(list_node->next != NULL) {
        list_node = list_node->next;
        printf("%d ", list_node->element);
    }
    printf("\n");
}

void linked_list_destroy(list *l) {
    list *list_node = l;
    list *next_node;

    while (list_node != NULL) {
        next_node = list_node->next;
        free(list_node);
        list_node = next_node;
    }

    return;
}