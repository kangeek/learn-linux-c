#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dllist_lib.h"

struct dl_list_node {
    struct dl_list_node *prev;
    struct dl_list_node *next;
    char data[0];
};

struct dl_list_head {
    int size;
    struct dl_list_node head;
};

DL_LIST *dl_list_create(int node_size) {
    struct dl_list_head *list = malloc(sizeof(*list));
    if (list == NULL)
        return NULL;

    list->size = node_size;
    list->head.prev = &(list->head);
    list->head.next = &(list->head);

    return list;
}

int dl_list_insert(DL_LIST *l, const void *element, int mode) {
    struct dl_list_node *new;
    struct dl_list_head *list = l;
    new = malloc(sizeof(*new) + list->size);
    if (new == NULL)
        return -1;

    memcpy(new->data, element, list->size);

    if (mode == INSERT_FORWARD) {
        new->prev = list->head.prev;
        new->next = &(list->head);
    } else if (mode == INSERT_BACKWARD) {
        new->prev = &(list->head);
        new->next = list->head.next;
    } else {
        return -3;
    }

    new->prev->next = new;
    new->next->prev = new;
    return 0;
}

static struct dl_list_node *find_(struct dl_list_head *list, const void *key, data_cmp *func) {
    struct dl_list_node *cur = NULL;
    for (cur = list->head.next; cur != &(list->head); cur = cur->next) {
        if (func(key, cur->data) == 0)
            break;
    }
    return cur;
}

void *dl_list_find(DL_LIST *l, const void *key, data_cmp *func) {
    struct dl_list_head *list = l;
    struct dl_list_node *node = find_(list, key, func);
    if (node == &list->head)
        return NULL;
    return node->data;
}

int dl_list_fetch(DL_LIST *l, const void *key, data_cmp *func, void *data) {
    struct dl_list_head *list = l;
    struct dl_list_node *found = find_(list, key, func);
    if (found == &list->head) {
        return -1;
    }
    found->prev->next = found->next;
    found->next->prev = found->prev;

    memcpy(data, found->data, list->size);

    free(found);
    return 0;
}

int dl_list_delete(DL_LIST *l, const void *key, data_cmp *func) {
    struct dl_list_head *list = l;
    struct dl_list_node *found = find_(list, key, func);
    if (found == &list->head) {
        return -1;
    }
    found->prev->next = found->next;
    found->next->prev = found->prev;

    free(found);
    return 0;
}

void dl_list_travel(DL_LIST *l, data_op *func) {
    struct dl_list_head *list = l;
    struct dl_list_node *cur = NULL;
    for (cur = list->head.next; cur != &list->head; cur = cur->next) {
        func(cur->data);
    }
}

void dl_list_destroy(DL_LIST *l) {
    struct dl_list_head *list = l;
    struct dl_list_node *cur = NULL, *next = NULL;
    for (cur = list->head.next; cur != &(list->head); cur = next) {
        next = cur->next;
        free(cur);
    }
    free(list);
}