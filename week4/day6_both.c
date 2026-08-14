/* Week 4 - Day 6 - Stack vs queue: same data, two output orders
 * gcc -Wall day6_both.c -o day6   then   ./day6
 * Feed the same three numbers into a stack and into a queue. The stack
 * gives them back last-in-first-out (reversed); the queue gives them back
 * first-in-first-out (same order). That is the whole difference, made real.
 * Undo wants a stack; a fair scheduler wants a queue. All ops are O(1).
 * TODO: feed four numbers instead of three and confirm the two orders.
 */
#include <stdio.h>
#define CAP 8

/* --- stack (LIFO) --- */
int stk[CAP];
int top = 0;

void push(int v) {
    if (top < CAP) { stk[top] = v; top++; }
}
int pop(int *out) {
    if (top == 0) { return 0; }
    top--;
    *out = stk[top];
    return 1;
}

/* --- queue (FIFO) --- */
int q[CAP];
int head = 0;
int tail = 0;

void enqueue(int v) {
    if (tail < CAP) { q[tail] = v; tail++; }
}
int dequeue(int *out) {
    if (head == tail) { return 0; }
    *out = q[head];
    head++;
    return 1;
}

int main(void) {
    int data[3] = {101, 102, 103};
    int i, v;

    for (i = 0; i < 3; i++) {
        push(data[i]);
        enqueue(data[i]);
    }

    printf("fed in: 101 102 103\n");

    printf("stack out (LIFO): ");
    while (pop(&v)) {
        printf("%d ", v);   /* 103 102 101 */
    }
    printf("\n");

    printf("queue out (FIFO): ");
    while (dequeue(&v)) {
        printf("%d ", v);   /* 101 102 103 */
    }
    printf("\n");

    return 0;
}
