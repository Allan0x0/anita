/* BITH132 Week 6, Day 6: BST search and why it is ~O(log n) (Unit 10, Trees)
 * Build & run: gcc -Wall day6_search.c -o out && ./out
 *
 * Everything ties together here. Searching a BST reuses the insert rule: at
 * each node, if the target is smaller go left, if larger go right, if equal you
 * found it. Every step drops one whole branch, so the work is the height of the
 * tree, not its node count.
 *
 * A balanced tree of n nodes has height about log2(n): a million nodes stand
 * only ~20 steps tall, so search touches ~20 joints, not a million. That is the
 * same O(log n) win as binary search on a sorted array (Week 5), but the tree
 * also stays cheap to insert into. The truss AS a tree: the king-post is the
 * root, rafters branch left and right, and a search walks straight down one
 * side of the frame to its joint.
 *
 * TODO (Build it): count the steps each search takes and print it. Confirm no
 * search costs more than the tree's height.
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

/* walk down one branch by the order rule; 1 if found, 0 if absent */
int search(struct node *root, int target) {
    while (root != NULL) {
        if (target == root->value) return 1;
        else if (target < root->value) root = root->left;   /* drop right branch */
        else root = root->right;                            /* drop left branch */
    }
    return 0;
}

int max(int a, int b) { return (a > b) ? a : b; }

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

    printf("height: %d (so search costs at most %d steps)\n",
           height(root), height(root) + 1);   /* height 2, at most 3 steps */

    printf("search 60: %s\n", search(root, 60) ? "found" : "not found"); /* found */
    printf("search 45: %s\n", search(root, 45) ? "found" : "not found"); /* not found */

    free_tree(root);
    return 0;
}
