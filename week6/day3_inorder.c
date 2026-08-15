/* BITH132 Week 6, Day 3: In-order traversal (Unit 10, Trees)
 * Build & run: gcc -Wall day3_inorder.c -o out && ./out
 *
 * A traversal visits every node in some order. In-order does three things at
 * each node, in this sequence: walk the LEFT branch, visit THIS node, walk the
 * RIGHT branch. Because a BST keeps smaller on the left, in-order visits the
 * values from smallest to largest, so it prints the tree sorted for free.
 *
 * Think of it as reading the truss left to right along the bottom chord: you
 * pass under every joint in ascending order.
 *
 * TODO (Build it): add a reverse in-order (right, node, left) and confirm it
 * prints the values largest to smallest.
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

struct node *insert(struct node *root, int value) {
    if (root == NULL) return make_node(value);
    if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);
    return root;
}

/* left, then self, then right: visits a BST in sorted order */
void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf(" %d", root->value);
    inorder(root->right);
}

void free_tree(struct node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);
    int i;

    struct node *root = NULL;
    for (i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("in-order:");
    inorder(root);              /* 20 30 40 50 60 70 80 */
    printf("\n");

    free_tree(root);
    return 0;
}
