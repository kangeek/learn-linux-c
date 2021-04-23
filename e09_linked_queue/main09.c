#include <stdio.h>
#include <stdlib.h>

#include "linked_queue.h"

int main() {

    int numbers[4] = {15, 26, 39, 28};
    LINKED_QUEUE *q = linked_queue_create(sizeof(int));
    if (q == NULL)
        exit(1);

    for (int i = 0; i < 4; ++i) {
        linked_queue_enqueue(q, numbers + i);
    }

    int fetched;
    for (int i = 0; i < 4; ++i) {
        linked_queue_dequeue(q, &fetched);
        printf("dequeue: %d\n", fetched);
    }

    linked_queue_destroy(q);

    exit(0);
}