#include <stdio.h>
#include <stdlib.h>

#include "btree.h"

void btree_put(leaf *root, int value) {
    if (value < root->value) {
        if (root->left != NULL) {
            btree_put(root->left, value);
        } else {
            leaf *node = (leaf *)malloc(sizeof(leaf));
            node->value = value;
            root->left = node;
        }
    } else {
        if (root->right != NULL) {
            btree_put(root->right, value);
        } else {
            leaf *node = (leaf *)malloc(sizeof(leaf));
            node->value = value;
            root->right = node;
        }
    }
}

leaf *btree_get(leaf *root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->value) {
        return btree_get(root->left, value);
    } else if (value == root->value) {
        return root;
    } else {
        return btree_get(root->right, value);
    }
}

result *btree_inorder(leaf *root, result *tail) {
    if (root->right != NULL) {
        tail = btree_inorder(root->right, tail);
    }

    result *current = (result *)malloc(sizeof(result));
    current->value = root->value;
    current->next = tail;
    tail = current;

    if (root->left != NULL) {
        tail = btree_inorder(root->left, current);
    }

    return tail;
}
