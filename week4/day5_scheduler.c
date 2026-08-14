/* Week 4 - Day 5 - Saw-job scheduler: jobs cut in arrival order (FIFO)
 * gcc -Wall day5_scheduler.c -o day5   then   ./day5
 * The saw-job queue is the real build step. Each job is a struct (id +
 * length). Enqueue them as they arrive, then dequeue and "cut" them. The
 * processing order equals the arrival order: a queue is fair by design.
 * TODO: add a job length total, printed as each job is cut.
 */
#include <stdio.h>
#define CAP 8

struct Job {
    int id;
    float length;   /* metres to cut */
};

struct Job queue[CAP];
int head = 0;
int tail = 0;

int enqueue(struct Job j) {
    if (tail == CAP) {
        printf("queue full, dropped job %d\n", j.id);
        return 0;
    }
    queue[tail] = j;
    tail++;
    return 1;
}

int dequeue(struct Job *out) {
    if (head == tail) {
        return 0;
    }
    *out = queue[head];
    head++;
    return 1;
}

int main(void) {
    struct Job a = {101, 2.5};
    struct Job b = {102, 3.0};
    struct Job c = {103, 1.8};
    struct Job job;

    enqueue(a);   /* arrival order: 101, 102, 103 */
    enqueue(b);
    enqueue(c);

    printf("cutting jobs in arrival order:\n");
    while (dequeue(&job)) {
        printf("cut job %d: %.1f m\n", job.id, job.length);
    }

    return 0;
}
