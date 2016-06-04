#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/btree.h"

#include "minunit.h"

int tests_run = 0;

static char *test_insert_new_nodes() {
    leaf *root = (leaf *)malloc(sizeof(leaf));
    root->value = 100;

    btree_put(root, 110);
    btree_put(root, 87);
    btree_put(root, 90);
    btree_put(root, 153);
    btree_put(root, 120);
    btree_put(root, 124);

    return 0;
}

static char *test_get_an_existing_node() {
    leaf *root = (leaf *)malloc(sizeof(leaf));
    root->value = 100;

    btree_put(root, 110);
    btree_put(root, 87);
    btree_put(root, 90);
    btree_put(root, 153);
    btree_put(root, 120);
    btree_put(root, 124);

    leaf *node = btree_get(root, 153);

    mu_assert("The value must be present in the tree", node != NULL);
    mu_assert("The value recorded is not '153'", node->value == 153);

    return 0;
}

static char *test_list_existing_leafs() {
    leaf *root = (leaf *)malloc(sizeof(leaf));
    root->value = 100;

    btree_put(root, 110);
    btree_put(root, 87);
    btree_put(root, 90);
    btree_put(root, 153);
    btree_put(root, 120);
    btree_put(root, 124);

    result *node = btree_inorder(root);

    mu_assert("The result list should not be empty", node != NULL);

    mu_assert("First element should be 87",    node->value == 87);
    mu_assert("Second element should be 90",   node->next->value == 90);
    mu_assert("Third element should be 100",   node->next->next->value == 100);
    mu_assert("Fourth element should be 110",  node->next->next->next->value == 110);
    mu_assert("Fifth element should be 120",   node->next->next->next->next->value == 120);
    mu_assert("Sixth element should be 124",   node->next->next->next->next->next->value == 124);
    mu_assert("Seventh element should be 153", node->next->next->next->next->next->next->value == 153);

    return 0;
}

static char *all_tests() {
    mu_run_test(test_insert_new_nodes);
    mu_run_test(test_get_an_existing_node);
    mu_run_test(test_list_existing_leafs);
    return 0;
}

int main(void) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

