#include <stdio.h>
#include <stdlib.h>

#include "array_queue.h"

int main(void) {
    aqueue *q = aqueue_create();
    if (q==NULL)
        exit(1);

    int c = 'a';
    for (int i = 0; i < 4; ++i) {
        aqueue_append(q, &c);
        c++;
    }

    aqueue_info(q);

    int ret = aqueue_append(q, &c);

    if (ret == -1)
        printf("The queue is full.\n");

    int f;
    for (int i = 0; i < 2; ++i) {
        aqueue_fetch(q, &f);
        printf("%5d",f);
    }
    printf("\n");
    aqueue_info(q);

    for (int i = 0; i < 2; ++i) {
        aqueue_fetch(q, &f);
        aqueue_append(q, &c);
        aqueue_fetch(q, &f);
        printf("%5d",f);
    }
    printf("\n");
    aqueue_info(q);

    ret = aqueue_fetch(q, &f);
    if (ret == -1)
        printf("The queue is empty.\n");
}