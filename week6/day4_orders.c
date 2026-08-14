/* BITH132 Week 6, Day 4: Pre-order and post-order (Unit 10, Trees)
 * Build & run: gcc -Wall day4_orders.c -o out && ./out
 *
 * Same three moves as in-order, different sequence, different use:
 *   pre-order:  visit THIS node, then left branch, then right branch.
 *   post-order: left branch, then right branch, then visit THIS node.
 *
 * Pre-order visits a node before its children, which is how you copy a truss:
 * you must place the king-post before the rafters that hang off it. Post-order
 * visits a node after its children, which is how you take a truss down (or free
 * a tree): clear both branches before you remove the joint above them.
 *
 * TODO (Build it): use post-order to add up every value in the tree, freeing
 * nothing, and print the total.
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

/* self first: parents printed before their children */
void preorder(struct node *root) {
    if (root == NULL) return;
    printf(" %d", root->value);
    preorder(root->left);
    preorder(root->right);
}

/* self last: children printed before their parent */
void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->value);
}

void free_tree(struct node *root) {
    if (root == NULL) return;
    free_tree(root->left);   /* post-order: clear branches before the joint */
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

    printf("pre-order: ");
    preorder(root);            /* 50 30 20 40 70 60 80 */
    printf("\n");

    printf("post-order:");
    postorder(root);           /* 20 40 30 60 80 70 50 */
    printf("\n");

    free_tree(root);
    return 0;
}
