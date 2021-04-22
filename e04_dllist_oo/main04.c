#include <stdio.h>
#include <stdlib.h>

#include "dllist_oo.h"

#define NAME_SIZE 32

struct score_st {
    int id;
    char name[NAME_SIZE];
    int math;
    int chinese;
};

void print_data(const void *data) {
    const struct score_st *r = data;
    printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}

int cmp_id(const void *key, const void *data) {
    const int *id = key;
    const struct score_st *score = data;
    return *id - score->id;
}

int cmp_math(const void *key, const void *data) {
    const int *math = key;
    const struct score_st *score = data;
    return *math - score->math;
}

int cmp_chinese(const void *key, const void *data) {
    const int *chinese = key;
    const struct score_st *score = data;
    return *chinese - score->chinese;
}

int main() {

    DL_LIST *handler;
    struct score_st tmp;
    int ret;
    handler = dl_list_create(sizeof(struct score_st));

    for (int i = 0; i < 7; i++) {
        tmp.id = i;
        snprintf(tmp.name, NAME_SIZE, "std%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;

        ret = handler->insert(handler, &tmp, INSERT_BACKWARD);
        if (ret)
            exit(1);
    }

    printf("\n---- handler->find ----\n");
    int key = 4;
    struct score_st *found = handler->find(handler, &key, cmp_id);
//    struct score_st *found = handler->find(handler, &key, cmp_math);
    if (found == NULL)
        printf("Student with id [%d] not found.\n", key);
    else
        print_data(found);

    printf("\n---- handler->fetch ----\n");
    struct score_st *fetched = malloc(sizeof(*fetched));
    ret = handler->fetch(handler, &key, cmp_id, fetched);
    if (ret)
        printf("Student with id [%d] not fetched.\n", key);
    else
        print_data(fetched);

    printf("\n---- handler->remove ----\n");
    key = 30;
    ret = handler->remove(handler, &key, cmp_math);
    if (ret)
        printf("Student with id [%d] not deleted.\n", key);

    handler->travel(handler, print_data);

    handler->destroy(handler);

    exit(0);
}