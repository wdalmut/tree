#ifndef _BTREE_H_
#define _BTREE_H_
#include <stdio.h>
#include <stdlib.h>

struct leaf_t {
    int value;

    struct leaf_t *left;
    struct leaf_t *right;
};
typedef struct leaf_t leaf;

struct result_t {
    int value;

    struct result_t *next;
};
typedef struct result_t result;

void btree_put(leaf *, int);
leaf *btree_get(leaf *, int);
result *btree_inorder(leaf *, result *);
#endif
