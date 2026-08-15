/* BITH132 Week 5, Day 4: Linear search (Unit 9, Searching)
 * Build & run: gcc -Wall day4_linear.c -o out && ./out
 *
 * The cut-list can be in any order. To find a member of a given spec (here a
 * target length), linear search walks it from the front and checks each length
 * until it hits a match. It works on unsorted data, which is its whole appeal,
 * but it may touch every item, so it is O(n).
 *
 * TODO (Build it): the function already returns the index, or -1 if absent.
 * Test both: search for a length that is present and one that is not.
 */
#include <stdio.h>

/* return the index of the first length equal to target, or -1 if none */
int linear_search(float a[], int n, float target) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    float cuts[] = {2.4f, 0.8f, 1.6f, 3.2f, 1.1f};
    int n = sizeof(cuts) / sizeof(cuts[0]);

    int hit = linear_search(cuts, n, 1.6f);
    int miss = linear_search(cuts, n, 2.0f);

    printf("1.6 m found at index %d\n", hit);    /* index 2 */
    printf("2.0 m found at index %d\n", miss);   /* index -1 (absent) */
    return 0;
}
