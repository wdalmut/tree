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

result *btree_inorder(leaf *root) {
    result *pre = NULL;
    if (root->right != NULL) {
        pre = btree_inorder(root->right);
    }

    result *current = (result *)malloc(sizeof(result));
    current->value = root->value;
    current->next = pre;

    pre = NULL;
    if (root->left != NULL) {
        pre = btree_inorder(root->left);
    }

    if (pre != NULL) {
        result *tmp = pre;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = current;
    }

    return (pre != NULL) ? pre : current;
}
