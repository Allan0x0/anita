/* Week 4 - Day 3 - The queue (FIFO): enqueue at the back, dequeue at the front
 * gcc -Wall day3_queue.c -o day3   then   ./day3
 * Saw-jobs wait in line. A new job joins at the back (enqueue). The saw
 * takes the next job from the front (dequeue). First in, first out.
 * head marks the front, tail the back. Both ops are O(1).
 * TODO: enqueue past CAP to see the "queue full" guard fire.
 */
#include <stdio.h>
#define CAP 8

int queue[CAP];
int head = 0;   /* front: next to be served */
int tail = 0;   /* back: next free slot */

/* enqueue a job id at the back */
int enqueue(int job) {
    if (tail == CAP) {
        printf("queue full, cannot enqueue job %d\n", job);
        return 0;
    }
    queue[tail] = job;
    tail++;
    return 1;
}

/* dequeue the job at the front into *out */
int dequeue(int *out) {
    if (head == tail) {
        printf("queue empty, nothing to dequeue\n");
        return 0;
    }
    *out = queue[head];
    head++;
    return 1;
}

int main(void) {
    int job;

    enqueue(101);   /* jobs arrive in this order */
    enqueue(102);
    enqueue(103);

    printf("enqueued 3 jobs\n");

    while (dequeue(&job)) {
        printf("saw job: %d\n", job);   /* served 101, 102, 103 */
    }

    return 0;
}
