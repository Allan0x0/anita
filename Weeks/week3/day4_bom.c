/* Week 3 - Day 4 - Build the BOM as a linked list, with malloc
 * gcc -Wall day4_bom.c -o day4   then   ./day4
 * Nodes are allocated on the heap one at a time and linked with next.
 * Walk the chain to total the timber, then free every node.
 * TODO: write a count_nodes(head) function that returns how many nodes.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    float length;
    char type;
    struct Node *next;
};

/* make one heap node, return it (NULL if malloc failed) */
struct Node *make_node(float length, char type) {
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL) {
        return NULL;
    }
    n->length = length;
    n->type = type;
    n->next = NULL;
    return n;
}

int main(void) {
    struct Node *head, *tail, *p, *doomed;
    float total;

    head = make_node(2.5, 'T');
    if (head == NULL) {
        return 1;
    }
    tail = head;

    tail->next = make_node(3.0, 'C');
    tail = tail->next;
    tail->next = make_node(2.5, 'T');
    tail = tail->next;

    total = 0.0;
    for (p = head; p != NULL; p = p->next) {
        printf("BOM: %.1f m (%c)\n", p->length, p->type);
        total = total + p->length;
    }
    printf("Total timber: %.1f m\n", total);

    /* free every node, one at a time, keeping a hold on the next one */
    p = head;
    while (p != NULL) {
        doomed = p;
        p = p->next;
        free(doomed);
    }
    return 0;
}
