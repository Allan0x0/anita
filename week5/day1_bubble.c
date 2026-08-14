/* BITH132 Week 5, Day 1: Bubble sort (Unit 8, Sorting)
 * Build & run: gcc -Wall day1_bubble.c -o out && ./out
 *
 * The cut-list holds timber lengths in metres, in no order. Bubble sort walks
 * the list again and again, swapping any two neighbours that are out of order,
 * so big lengths "bubble" toward the end. After enough passes the whole list is
 * sorted ascending, which lets you plan cuts against the stock with less waste.
 *
 * Two nested loops over n items make it O(n^2): slow, but the simplest sort.
 *
 * TODO (Build it): add a `swapped` flag. If a full pass makes no swap the list
 * is already sorted, so break early instead of finishing every pass.
 */
#include <stdio.h>

int main(void) {
    float cuts[] = {2.4f, 0.8f, 1.6f, 3.2f, 1.1f};
    int n = sizeof(cuts) / sizeof(cuts[0]);
    int i, j;

    /* each pass pushes the next-largest length to its place at the end */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (cuts[j] > cuts[j + 1]) {
                float tmp = cuts[j];   /* swap the out-of-order neighbours */
                cuts[j] = cuts[j + 1];
                cuts[j + 1] = tmp;
            }
        }
    }

    printf("sorted cut-list:");
    for (i = 0; i < n; i++) {
        printf(" %.1f", cuts[i]);   /* 0.8 1.1 1.6 2.4 3.2 */
    }
    printf("\n");
    return 0;
}
