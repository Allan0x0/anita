/* BITH132 Week 5, Day 5: Binary search (Unit 9, Searching)
 * Build & run: gcc -Wall day5_binary.c -o out && ./out
 *
 * Binary search needs the cut-list already SORTED (ascending here). It keeps a
 * range [lo, hi] and looks at the middle length: if that is the target it is
 * done; if the target is larger it drops the left half, else it drops the right.
 * Each step halves the range, so it is O(log n), which crushes linear O(n) at
 * scale: a list of a million lengths takes about 20 steps, not a million.
 *
 * It only works on sorted input, because dropping half the range assumes every
 * length to one side of the middle is smaller (or larger) than it.
 *
 * TODO (Build it): print lo, mid and hi each step to watch the range halve.
 */
#include <stdio.h>

/* return the index of target in the sorted array a, or -1 if absent */
int binary_search(float a[], int n, float target) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;   /* middle without overflow */
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            lo = mid + 1;   /* target is in the right half */
        } else {
            hi = mid - 1;   /* target is in the left half */
        }
    }
    return -1;
}

int main(void) {
    float cuts[] = {0.8f, 1.1f, 1.6f, 2.4f, 3.2f};   /* must be sorted */
    int n = sizeof(cuts) / sizeof(cuts[0]);

    int hit = binary_search(cuts, n, 2.4f);
    int miss = binary_search(cuts, n, 2.0f);

    printf("2.4 m found at index %d\n", hit);    /* index 3 */
    printf("2.0 m found at index %d\n", miss);   /* index -1 (absent) */
    return 0;
}
