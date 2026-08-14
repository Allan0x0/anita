/* BITH132 Week 5, Day 6: Sort then search (Units 8 and 9 together)
 * Build & run: gcc -Wall day6_both.c -o out && ./out
 *
 * The two units combined. Start with an unsorted cut-list of timber lengths.
 * First SORT it (selection sort here), then BINARY-SEARCH the sorted list for a
 * member of a given spec. The sort is the price you pay once so every later
 * search is O(log n) instead of O(n).
 *
 * TODO (Build it): search for a length that is absent and confirm it reports
 * "not found" (returns -1).
 */
#include <stdio.h>

void selection_sort(float a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            float tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}

int binary_search(float a[], int n, float target) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    float cuts[] = {2.4f, 0.8f, 1.6f, 3.2f, 1.1f};
    int n = sizeof(cuts) / sizeof(cuts[0]);
    int i, idx;

    selection_sort(cuts, n);   /* pay the sort cost once */

    printf("sorted cut-list:");
    for (i = 0; i < n; i++) {
        printf(" %.1f", cuts[i]);   /* 0.8 1.1 1.6 2.4 3.2 */
    }
    printf("\n");

    idx = binary_search(cuts, n, 1.6f);
    printf("1.6 m -> index %d\n", idx);   /* index 2 */

    idx = binary_search(cuts, n, 2.0f);
    if (idx == -1) {
        printf("2.0 m -> not found\n");   /* absent */
    } else {
        printf("2.0 m -> index %d\n", idx);
    }
    return 0;
}
