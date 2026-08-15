/* Week 3 - Day 5 - Insert and delete on a list: repoint next, no shifting
 * gcc -Wall day5_splice.c -o day5   then   ./day5
 * Splicing a node in or out is O(1) once you hold the spot: no moving
 * every later Member, only a next pointer changes hands.
 * TODO: write insert_before(head, target, node) using a trailing pointer.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    float length;
    struct Node *next;
};

struct Node *make_node(float length) {
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL) {
        return NULL;
    }
    n->length = length;
    n->next = NULL;
    return n;
}

/* insert fresh right after "after": after->next = fresh; fresh->next = old next */
void insert_after(struct Node *after, struct Node *fresh) {
    fresh->next = after->next;
    after->next = fresh;
}

/* delete the node right after "before"; frees it, relinks around it */
void delete_after(struct Node *before) {
    struct Node *doomed = before->next;
    if (doomed == NULL) {
        return;
    }
    before->next = doomed->next;   /* skip over doomed */
    free(doomed);
}

void print_list(struct Node *head) {
    struct Node *p;
    for (p = head; p != NULL; p = p->next) {
        printf("%.1f m -> ", p->length);
    }
    printf("NULL\n");
}

int main(void) {
    struct Node *head, *mid, *tail, *brace;

    head = make_node(2.5);
    mid = make_node(3.0);
    tail = make_node(2.5);
    head->next = mid;
    mid->next = tail;

    printf("before insert: ");
    print_list(head);

    brace = make_node(1.8);
    insert_after(head, brace);   /* splice brace in after head, O(1) */
    printf("after insert:  ");
    print_list(head);

    delete_after(head);          /* remove brace again, O(1) */
    printf("after delete:  ");
    print_list(head);

    free(tail);
    free(mid);
    free(head);
    return 0;
}
