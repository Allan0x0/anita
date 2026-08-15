/* Week 3 - Day 3 - A self-referential struct: the node
 * gcc -Wall day3_node.c -o day3   then   ./day3
 * struct Node holds data AND a pointer to the next Node. NULL ends
 * the chain. Here three nodes are built on the stack by hand and linked.
 * TODO: add a fourth node and link it onto the end of the chain.
 */
#include <stdio.h>

struct Node {
    float length;
    struct Node *next;
};

int main(void) {
    struct Node a, b, c;
    struct Node *p;

    a.length = 2.5; a.next = &b;
    b.length = 3.0; b.next = &c;
    c.length = 2.5; c.next = NULL;   /* NULL: chain stops here */

    p = &a;
    while (p != NULL) {
        printf("node: %.1f m\n", p->length);
        p = p->next;   /* step to the next Node */
    }
    return 0;
}
