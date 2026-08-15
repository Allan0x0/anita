/* BITH132 Week 6, Day 2: Build a BST by inserting (Unit 10, Trees)
 * Build & run: gcc -Wall day2_insert.c -o out && ./out
 *
 * A binary search tree (BST) keeps an order rule at every node: everything in
 * the left branch is smaller, everything in the right branch is larger. Insert
 * one value by starting at the root and stepping left or right by that rule
 * until you fall off the tree (reach NULL), then hang the new node there.
 *
 * That rule is what makes a truss searchable: from any node you know which
 * branch could hold a value, so you never check the other side.
 *
 * TODO (Build it): print how many steps each insert took (count the hops down
 * the tree before the new node is placed).
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *make_node(int value) {
    struct node *n = malloc(sizeof(struct node));
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/* insert value under root by the BST rule; return the (possibly new) root */
struct node *insert(struct node *root, int value) {
    if (root == NULL) {
        return make_node(value);   /* empty spot: hang the node here */
    }
    if (value < root->value) {
        root->left = insert(root->left, value);    /* smaller: go left */
    } else if (value > root->value) {
        root->right = insert(root->right, value);  /* larger: go right */
    }
    /* equal value: ignore, the tree holds no duplicates */
    return root;
}

void free_tree(struct node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    int values[] = {50, 30, 70, 20, 40, 60};
    int n = sizeof(values) / sizeof(values[0]);
    int i;

    struct node *root = NULL;
    for (i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    /* spot-check the shape: root, its children, one grandchild */
    printf("root:            %d\n", root->value);              /* 50 */
    printf("root->left:      %d\n", root->left->value);        /* 30 */
    printf("root->right:     %d\n", root->right->value);       /* 70 */
    printf("root->left->left:%d\n", root->left->left->value);  /* 20 */

    free_tree(root);
    return 0;
}
