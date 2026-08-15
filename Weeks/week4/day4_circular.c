/* Week 4 - Day 4 - The circular queue: wrap head and tail with % CAP
 * gcc -Wall day4_circular.c -o day4   then   ./day4
 * A plain array queue wastes space: head marches forward and never comes
 * back, so old slots go dead. A circular queue wraps the index round with
 * % CAP, reusing freed slots. A count field tells full from empty.
 * TODO: dequeue two, enqueue three; watch tail wrap past the end to slot 0.
 */
#include <stdio.h>
#define CAP 4   /* small, to show the wrap quickly */

int buf[CAP];
int head = 0;    /* front slot */
int tail = 0;    /* next free slot */
int count = 0;   /* how many jobs are in the queue right now */

int enqueue(int job) {
    if (count == CAP) {
        printf("full, cannot enqueue job %d\n", job);
        return 0;
    }
    buf[tail] = job;
    tail = (tail + 1) % CAP;   /* wrap round the end */
    count++;
    return 1;
}

int dequeue(int *out) {
    if (count == 0) {
        printf("empty, nothing to dequeue\n");
        return 0;
    }
    *out = buf[head];
    head = (head + 1) % CAP;   /* wrap round the end */
    count--;
    return 1;
}

int main(void) {
    int job;

    enqueue(101);
    enqueue(102);
    enqueue(103);
    printf("count = %d\n", count);

    dequeue(&job);   printf("served %d\n", job);   /* 101 */
    dequeue(&job);   printf("served %d\n", job);   /* 102 */

    /* two slots freed at the front; these wrap tail back to the start */
    enqueue(104);
    enqueue(105);
    printf("count = %d (tail wrapped, no space wasted)\n", count);

    while (dequeue(&job)) {
        printf("served %d\n", job);   /* 103, 104, 105 */
    }

    return 0;
}
