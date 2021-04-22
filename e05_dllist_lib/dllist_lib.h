#ifndef LINKED_LIST_H__
#define LINKED_LIST_H__

typedef void DL_LIST;

#define INSERT_FORWARD  1
#define INSERT_BACKWARD 2

typedef void data_op(const void *);
typedef int data_cmp(const void *, const void *);

DL_LIST *dl_list_create(int node_size);

int dl_list_insert(DL_LIST *list, const void *element, int mode);

void *dl_list_find(DL_LIST *list, const void *key, data_cmp *func);

int dl_list_delete(DL_LIST *list, const void *key, data_cmp *func);

int dl_list_fetch(DL_LIST *list, const void *key, data_cmp *func, void *data);

void dl_list_travel(DL_LIST *list, data_op *);

void dl_list_destroy(DL_LIST *list);

#endif