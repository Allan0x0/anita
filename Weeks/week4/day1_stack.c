/* Week 4 - Day 1 - The stack (LIFO): push and pop on the top only
 * gcc -Wall day1_stack.c -o day1   then   ./day1
 * An offcut stack: cut a piece, drop the offcut on top. Push adds on top,
 * pop takes from the top. Last in, first out. Both are O(1).
 * TODO: change CAP to 3 and push 4 offcuts to see the overflow guard fire.
 */
#include <stdio.h>
#define CAP 8

float stack[CAP];
int top = 0;   /* index of the next free slot; also the count */

/* push one offcut onto the top; guard against overflow */
int push(float offcut) {
    if (top == CAP) {
        printf("overflow: stack full, cannot push %.1f\n", offcut);
        return 0;
    }
    stack[top] = offcut;
    top++;
    return 1;
}

/* pop the top offcut into *out; guard against underflow */
int pop(float *out) {
    if (top == 0) {
        printf("underflow: stack empty, nothing to pop\n");
        return 0;
    }
    top--;
    *out = stack[top];
    return 1;
}

int main(void) {
    float got;

    push(0.4);   /* offcut lengths in metres */
    push(1.1);
    push(0.7);

    printf("pushed 3 offcuts, top = %d\n", top);

    while (pop(&got)) {
        printf("pop: %.1f m\n", got);   /* comes out 0.7, 1.1, 0.4 */
    }

    return 0;
}
