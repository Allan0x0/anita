/* Week 4 - Day 2 - Undo with a stack: each cut pushes, undo pops the last
 * gcc -Wall day2_undo.c -o day2   then   ./day2
 * Every cut you make pushes its offcut onto the undo stack. Pressing undo
 * pops the most recent cut first, so undos come out in reverse of the cuts.
 * That reversal is what LIFO means. Push and pop are O(1).
 * TODO: after two undos, push one new cut and undo again; watch the order.
 */
#include <stdio.h>
#define CAP 8

float undo[CAP];
int top = 0;

int cut(float offcut) {
    if (top == CAP) {
        printf("overflow: undo stack full\n");
        return 0;
    }
    undo[top] = offcut;
    top++;
    printf("cut: made offcut %.1f m (undo depth %d)\n", offcut, top);
    return 1;
}

int undo_last(float *out) {
    if (top == 0) {
        printf("nothing to undo\n");
        return 0;
    }
    top--;
    *out = undo[top];
    return 1;
}

int main(void) {
    float got;

    cut(0.4);   /* cut order: 0.4, then 1.1, then 0.7 */
    cut(1.1);
    cut(0.7);

    printf("--- pressing undo ---\n");
    while (undo_last(&got)) {
        printf("undo: reversed cut of %.1f m\n", got);   /* 0.7, 1.1, 0.4 */
    }

    return 0;
}
