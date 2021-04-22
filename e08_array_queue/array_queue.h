#ifndef ARRAY_QUEUE_H__
#define ARRAY_QUEUE_H__

#define MAX_SIZE 5

typedef int datatype;

typedef struct array_queue_st {
    datatype data[MAX_SIZE];
    int head;
    int tail;
} aqueue;

aqueue *aqueue_create();
int aqueue_append(aqueue *queue, datatype *element);
int aqueue_fetch(aqueue *queue, datatype *fetched);
int aqueue_is_empty(aqueue *queue);
int aqueue_is_full(aqueue *queue);
void aqueue_info(aqueue *queue);
void aqueue_destroy(aqueue *queue);

#endif