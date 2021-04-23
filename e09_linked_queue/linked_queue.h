#ifndef LINKED_QUEUE_H__
#define LINKED_QUEUE_H__

#include "dllist_lib.h"

typedef DL_LIST LINKED_QUEUE;

LINKED_QUEUE *linked_queue_create(int ele_size);

int linked_queue_enqueue(LINKED_QUEUE *queue, const void *element);

int linked_queue_dequeue(LINKED_QUEUE *queue, void *data);

void linked_queue_destroy(LINKED_QUEUE *queue);

#endif