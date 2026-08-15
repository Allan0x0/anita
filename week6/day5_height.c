/* BITH132 Week 6, Day 5: Tree depth and height (Unit 10, Trees)
 * Build & run: gcc -Wall day5_height.c -o out && ./out
 *
 * The height of a tree is the longest run of steps from the root down to a
 * leaf. An empty tree has height -1 (no nodes); a lone root has height 0. For
 * any node, its height is 1 plus the taller of its two branches.
 *
 * Height is what a search costs: it is the number of joints you may pass on the
 * way down. A short, bushy truss searches fast; a tall, lopsided one does not,
 * which is the whole point of Day 6.
 *
 * TODO (Build it): insert the values in already-sorted order (10,20,30,40) into
 * a fresh tree and print its height. It grows into a straight line, height n-1.
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

int max(int a, int b) {
    return (a > b) ? a : b;
}

/* height = 1 + taller branch; empty tree is -1 so a lone root is 0 */
int height(struct node *root) {
    if (root == NULL) return -1;
    return 1 + max(height(root->left), height(root->right));
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

    /* this balanced 7-node tree stands 2 steps tall */
    printf("nodes:  %d\n", n);            /* 7 */
    printf("height: %d\n", height(root)); /* 2 */

    free_tree(root);
    return 0;
}
