#ifndef LINKED_LIST_H__
#define LINKED_LIST_H__

#define INSERT_FORWARD  1
#define INSERT_BACKWARD 2

typedef void data_op(const void *);
typedef int data_cmp(const void *, const void *);

typedef struct dl_list_node {
    struct dl_list_node *prev;
    struct dl_list_node *next;
    char data[0];
} node;

typedef struct dl_list_head {
    int size;
    node head;
    int (*insert)(struct dl_list_head *list, const void *element, int mode);
    void *(*find)(struct dl_list_head *list, const void *key, data_cmp *func);
    int (*remove)(struct dl_list_head *list, const void *key, data_cmp *func);
    int (*fetch)(struct dl_list_head *list, const void *key, data_cmp *func, void *data);
    void (*travel)(struct dl_list_head *list, data_op *);
    void (*destroy)(struct dl_list_head *list);
} DL_LIST;

DL_LIST *dl_list_create(int node_size);

#endif