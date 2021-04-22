#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dllist_oo.h"

int dl_list_insert(struct dl_list_head *list, const void *element, int mode) {
    node *new;
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

static node *find_(struct dl_list_head *list, const void *key, data_cmp *func) {
    node *cur = NULL;
    for (cur = list->head.next; cur != &(list->head); cur = cur->next) {
        if (func(key, cur->data) == 0)
            break;
    }
    return cur;
}

void *dl_list_find(struct dl_list_head *list, const void *key, data_cmp *func) {
    node *node = find_(list, key, func);
    if (node == &list->head)
        return NULL;
    return node->data;
}

int dl_list_fetch(struct dl_list_head *list, const void *key, data_cmp *func, void *data) {
    node *found = find_(list, key, func);
    if (found == &list->head) {
        return -1;
    }
    found->prev->next = found->next;
    found->next->prev = found->prev;

    memcpy(data, found->data, list->size);

    free(found);
    return 0;
}

int dl_list_delete(struct dl_list_head *list, const void *key, data_cmp *func) {
    node *found = find_(list, key, func);
    if (found == &list->head) {
        return -1;
    }
    found->prev->next = found->next;
    found->next->prev = found->prev;

    free(found);
    return 0;
}

void dl_list_travel(struct dl_list_head *list, data_op *func) {
    node *cur = NULL;
    for (cur = list->head.next; cur != &list->head; cur = cur->next) {
        func(cur->data);
    }
}

void dl_list_destroy(struct dl_list_head *list) {
    node *cur = NULL, *next = NULL;
    for (cur = list->head.next; cur != &(list->head); cur = next) {
        next = cur->next;
        free(cur);
    }
    free(list);
}

DL_LIST *dl_list_create(int node_size) {
    DL_LIST *list = malloc(sizeof(*list));
    if (list == NULL)
        return NULL;

    list->size = node_size;
    list->head.prev = &(list->head);
    list->head.next = &(list->head);

    list->insert = dl_list_insert;
    list->remove = dl_list_delete;
    list->find = dl_list_find;
    list->fetch = dl_list_fetch;
    list->travel = dl_list_travel;
    list->destroy = dl_list_destroy;

    return list;
}
