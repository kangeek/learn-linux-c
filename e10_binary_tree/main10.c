#include <stdlib.h>
#include <stdio.h>

#define NAME_SIZE 32
#define FILE_NAME "generalized_list.txt"

typedef struct score_st {
    int id;
    char name[NAME_SIZE];
    int math;
    int chinese;
} score;

typedef struct tree_node_st {
    score data;
    struct tree_node_st *l, *r;
} node;

void print_s(score *s) {
    printf("%d %s %d %d\n", s->id, s->name, s->math, s->chinese);
}

int tree_insert(node **pNode, const score *data) {
    if (*pNode == NULL) {
        *pNode = malloc(sizeof(**pNode));
        if (*pNode == NULL)
            return -1;
        (*pNode)->data = *data;
        (*pNode)->l = (*pNode)->r = NULL;
        return 0;
    }
    if (data->id <= (*pNode)->data.id)
        return tree_insert(&((*pNode)->l), data);
    return tree_insert(&((*pNode)->r), data);
}

static node **_find(node **root, int id) {
    if (*root == NULL)
        return NULL;

    if (id == (*root)->data.id)
        return root;
    else if (id < (*root)->data.id)
        return _find(&(*root)->l, id);
    else
        return _find(&(*root)->r, id);
}

score *find(node *root, int id) {
    node **found = _find(&root, id);
    if (*found == NULL) return NULL;
    return &(*found)->data;
}

void travel(node *root) {
    if (root == NULL) {
        printf("-\n");
        return;
    }
    print_s(&root->data);
    travel(root->l);
    travel(root->r);
}

// 生成广义表
void to_generalized_list(node *root) {
    printf("(");
    if (root != NULL) {
        printf("%d", root->data.id);
        to_generalized_list(root->l);
        to_generalized_list(root->r);
    }
    printf(")");
}

node *_from_generalized_list(FILE *fp) {
    char c = fgetc(fp);
    if (c != '(')
        exit(1);

    c = fgetc(fp);
    if (c == ')')
        return NULL;

    node *new = malloc(sizeof(*new));
    new->data.id = c - 48;
    snprintf(new->data.name, NAME_SIZE, "stu%c", c);
    new->data.chinese = rand() % 100;
    new->data.math = rand() % 100;

    new->l = _from_generalized_list(fp);
    new->r = _from_generalized_list(fp);

    fgetc(fp);
    return new;
}

// 从广义表生成二叉树
node *from_generalized_list(const char *path) {
    FILE *fp = fopen(path, "r");
    node *root = NULL;
    if (fp == NULL) {
        fprintf(stderr, "Open file [%s] failed.\n", path);
        exit(1);
    }

    root = _from_generalized_list(fp);

    fclose(fp);
    return root;
}

static int children_count(node *root) {
    if (root == NULL)
        return 0;
    return 1 + children_count(root->l) + children_count(root->r);
}

static node *to_min_node(node *root) {
    if (root->l == NULL)
        return root;
    return to_min_node(root->l);
}

static node *to_max_node(node *root) {
    if (root->r == NULL)
        return root;
    return to_max_node(root->r);
}

static void turn_left(node **root) {
    node *temp = to_min_node((*root)->r);
    temp->l = *root;
    *root = (*root)->r;
    temp->l->r = NULL;
}

static void turn_right(node **root) {
    node *temp = to_max_node((*root)->l);
    temp->r = *root;
    *root = (*root)->l;
    temp->r->l = NULL;
}

void balance(node **root) {
    if (*root == NULL)
        return;

    int sub;
    while (1) {
        sub = children_count((*root)->l) - children_count((*root)->r);

        if (sub < -1) turn_left(root);    // 往左旋
        else if (sub > 1) turn_right(root);   // 往右旋
        else break;
    }

    balance(&(*root)->l);
    balance(&(*root)->r);
}

int delete(node **root, int id) {
    node **p_delete = _find(root, id);
    if (*p_delete == NULL) return -1;

    node *temp = *p_delete;
    if (temp->l == NULL)
        *p_delete = temp->r;
    else {
        *p_delete = temp->l;
        to_max_node(temp->l)->r = temp->r;
    }
    free(temp);
    return 0;
}

int main(void) {
    int ids[] = {1, 2, 3, 7, 6, 5, 9, 8, 4};

    node *root = NULL;
    score *temp;

    for (int i = 0; i < sizeof(ids) / sizeof(int); ++i) {
        temp = malloc(sizeof(*temp));
        if (temp == NULL)
            return -1;
        temp->id = ids[i];
        snprintf(temp->name, NAME_SIZE, "std%d", ids[i]);
        temp->math = rand() % 100;
        temp->chinese = rand() % 100;

        tree_insert(&root, temp);
    }

    balance(&root);

    travel(root);

    score *found = find(root, 7);
    if (found != NULL) {
        printf("Find score with (id==7): ");
        print_s(found);
    }

    printf("Delete score with (id==5) >>>> \n");
    delete(&root, 5);

    travel(root);

    to_generalized_list(root);
    printf("\n======================\n");

    node *generated = from_generalized_list(FILE_NAME);
    travel(generated);
}