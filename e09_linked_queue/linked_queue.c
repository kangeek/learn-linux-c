#include "linked_queue.h"

LINKED_QUEUE *linked_queue_create(int ele_size) {
    return dl_list_create(ele_size);
}

int linked_queue_enqueue(LINKED_QUEUE *queue, const void *element) {
    return dl_list_insert(queue, element, INSERT_FORWARD);
}

static int _always_match(const void *p1, const void *p2) {
    return 0;
}

int linked_queue_dequeue(LINKED_QUEUE *queue, void *data) {
    return dl_list_fetch(queue, (void *) 0, _always_match, data);
}

void linked_queue_destroy(LINKED_QUEUE *queue) {
    dl_list_destroy(queue);
}

