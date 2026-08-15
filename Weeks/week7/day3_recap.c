/* BITH132 Week 7, Day 3: Linked lists, stacks and queues recap (Units 5-7)
 * Build & run: gcc -Wall day3_recap.c -o out && ./out
 *
 * A linked list is a dynamic sequence: each node holds a value and a pointer
 * to the next node, so it grows without a fixed size like an array. A stack
 * pops last-in-first-out (LIFO): the last piece cut is the first one undone.
 * A queue serves first-in-first-out (FIFO): the first saw job queued is the
 * first one run. Same idea (a sequence), three different shapes for three
 * different jobs.
 *
 * TODO (Build it): push a fourth node onto the list and confirm the walk
 * still ends when next is NULL, no matter how many nodes came before.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *push_front(struct node *head, int value) {
    struct node *n = malloc(sizeof(struct node));
    n->value = value;
    n->next = head;    /* new node points at the old head */
    return n;          /* new node becomes the head */
}

void free_list(struct node *head) {
    while (head != NULL) {
        struct node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    struct node *head = NULL;
    struct node *cur;

    head = push_front(head, 30);
    head = push_front(head, 20);
    head = push_front(head, 10);   /* list is now 10 -> 20 -> 30 -> NULL */

    printf("linked list (dynamic sequence): ");
    for (cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->value);
    }
    printf("\n");
    printf("stack pick: LIFO, last pushed (10) comes off first\n");
    printf("queue pick: FIFO, first pushed (30, at the tail) comes off first\n");

    free_list(head);
    return 0;
}
