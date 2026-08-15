/* BITH132 Week 6, Day 1: Binary tree nodes (Unit 10, Trees)
 * Build & run: gcc -Wall day1_node.c -o out && ./out
 *
 * A truss is not a flat cut-list, it is a frame that branches. A binary tree
 * models that: each node holds a value and two pointers, left and right, each
 * to another node or to NULL. The top node is the root (the king-post), a node
 * with no children is a leaf (a rafter tip).
 *
 * Here we build a tiny tree by hand, three nodes, and print the root with its
 * two children, so you can see a node IS just a struct pointing at two more.
 *
 * TODO (Build it): add a third level. Give the left child its own left child
 * and print that grandchild too.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

/* make one node on the heap; children start empty (NULL) */
struct node *make_node(int value) {
    struct node *n = malloc(sizeof(struct node));
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(void) {
    struct node *root = make_node(50);   /* king-post at the top */
    root->left = make_node(30);          /* rafter down-left */
    root->right = make_node(70);         /* rafter down-right */

    printf("root:  %d\n", root->value);          /* 50 */
    printf("left:  %d\n", root->left->value);     /* 30 */
    printf("right: %d\n", root->right->value);    /* 70 */

    /* a leaf has no children: both pointers are NULL */
    printf("left is a leaf? %s\n",
           (root->left->left == NULL && root->left->right == NULL) ? "yes" : "no");

    free(root->left);
    free(root->right);
    free(root);
    return 0;
}
