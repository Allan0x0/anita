/* Week 3 - Day 6 - Tie it together: a BOM linked list with insert and delete
 * gcc -Wall day6_bomlist.c -o day6   then   ./day6
 * Array insert/delete: O(n), shifting. Linked list splice: O(1) once you
 * hold the spot, but O(n) to find that spot, and no O(1) random access.
 * TODO: write a find(head, length) that returns the node with that length.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    float length;
    char type;
    struct Node *next;
};

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

/* insert fresh right after "after" (O(1) once "after" is known) */
void insert_after(struct Node *after, struct Node *fresh) {
    fresh->next = after->next;
    after->next = fresh;
}

/* delete the node right after "before" (O(1) once "before" is known) */
void delete_after(struct Node *before) {
    struct Node *doomed = before->next;
    if (doomed == NULL) {
        return;
    }
    before->next = doomed->next;
    free(doomed);
}

void print_list(struct Node *head) {
    struct Node *p;
    float total = 0.0;
    for (p = head; p != NULL; p = p->next) {
        printf("%.1f m (%c) -> ", p->length, p->type);
        total = total + p->length;
    }
    printf("NULL  (total %.1f m)\n", total);
}

void free_list(struct Node *head) {
    struct Node *p = head;
    struct Node *doomed;
    while (p != NULL) {
        doomed = p;
        p = p->next;
        free(doomed);
    }
}

int main(void) {
    struct Node *head, *mid, *tail, *brace;

    head = make_node(2.5, 'T');
    mid = make_node(3.0, 'C');
    tail = make_node(2.5, 'T');
    head->next = mid;
    mid->next = tail;

    printf("start:  ");
    print_list(head);

    brace = make_node(1.8, 'B');
    insert_after(mid, brace);   /* splice in after mid */
    printf("insert: ");
    print_list(head);

    delete_after(head);         /* drop mid, the O(n) search was skipped: */
    printf("delete: ");         /* we already held "head" from Day 3/4/5 */
    print_list(head);

    free_list(head);
    return 0;
}
