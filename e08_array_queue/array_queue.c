#include <stdio.h>
#include <stdlib.h>

#include "array_queue.h"

aqueue *aqueue_create() {
    aqueue *q = malloc(sizeof(*q));
    if (q == NULL)
        return NULL;

    q->head = q->tail = 0;
    return q;
}

int aqueue_append(aqueue *queue, datatype *element) {
    if (aqueue_is_full(queue))
        return -1;

    queue->tail = (queue->tail + 1) % MAX_SIZE;
    queue->data[queue->tail] = *element;
    return 0;
}

int aqueue_fetch(aqueue *queue, datatype *fetched) {
    if (aqueue_is_empty(queue))
        return -1;

    queue->head = (queue->head + 1) % MAX_SIZE;
    *fetched = queue->data[queue->head];
    return 0;
}

int aqueue_is_empty(aqueue *queue) {
    return queue->tail == queue->head;
}

int aqueue_is_full(aqueue *queue) {
    return (queue->tail + 1) % MAX_SIZE == queue->head;
}

void aqueue_info(aqueue *queue){
    printf("------------------------------\n");
    for (int i = 0; i < queue->head * 5 + 4; ++i) {
        printf(" ");
    }
    printf("h\n");

    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("%5d", queue->data[i]);
    }
    printf("\n");

    for (int i = 0; i < queue->tail * 5 + 4; ++i) {
        printf(" ");
    }
    printf("t\n");
    printf("------------------------------\n");
}

void aqueue_destroy(aqueue *queue) {
    free(queue);
}
