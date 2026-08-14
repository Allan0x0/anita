/* BITH132 Week 5, Day 2: Selection sort (Unit 8, Sorting)
 * Build & run: gcc -Wall day2_selection.c -o out && ./out
 *
 * Another simple sort for the cut-list of timber lengths. Selection sort keeps
 * a sorted front and an unsorted tail. Each round it scans the tail for the
 * smallest length and swaps it into the front. A sorted cut-list lets you pack
 * pieces against the stock in order, so you leave smaller offcuts.
 *
 * Still O(n^2) comparisons like bubble sort, but it does at most one swap per
 * round (n-1 swaps total) instead of many, which matters when a swap is costly.
 *
 * TODO (Build it): count the swaps in a `swaps` variable and print the total.
 */
#include <stdio.h>

int main(void) {
    float cuts[] = {2.4f, 0.8f, 1.6f, 3.2f, 1.1f};
    int n = sizeof(cuts) / sizeof(cuts[0]);
    int i, j;

    for (i = 0; i < n - 1; i++) {
        int min = i;   /* assume the front of the tail is the smallest */
        for (j = i + 1; j < n; j++) {
            if (cuts[j] < cuts[min]) {
                min = j;   /* found a smaller length further along */
            }
        }
        if (min != i) {
            float tmp = cuts[i];   /* one swap puts the smallest in place */
            cuts[i] = cuts[min];
            cuts[min] = tmp;
        }
    }

    printf("sorted cut-list:");
    for (i = 0; i < n; i++) {
        printf(" %.1f", cuts[i]);   /* 0.8 1.1 1.6 2.4 3.2 */
    }
    printf("\n");
    return 0;
}
