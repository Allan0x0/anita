/* BITH132 Week 5, Day 3: Quicksort (Unit 8, Sorting)
 * Build & run: gcc -Wall day3_quicksort.c -o out && ./out
 *
 * Quicksort sorts the cut-list by divide-and-conquer. Pick a pivot length,
 * partition the list so smaller lengths sit left of it and larger sit right,
 * then sort each side the same way. Halving the work each level gives O(n log n)
 * on average, which beats the O(n^2) simple sorts on a long cut-list.
 *
 * Worst case is O(n^2) when the pivot is always the smallest or largest (for
 * example an already-sorted list with a last-element pivot).
 *
 * TODO (Build it): print the array after each partition to watch it take shape.
 */
#include <stdio.h>

void swap(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

/* partition around the last element; return the pivot's final index */
int partition(float a[], int lo, int hi) {
    float pivot = a[hi];
    int i = lo - 1;   /* boundary of the "smaller than pivot" zone */
    int j;
    for (j = lo; j < hi; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[hi]);   /* drop the pivot into place */
    return i + 1;
}

void quicksort(float a[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quicksort(a, lo, p - 1);    /* sort the smaller side */
        quicksort(a, p + 1, hi);    /* sort the larger side */
    }
}

int main(void) {
    float cuts[] = {2.4f, 0.8f, 1.6f, 3.2f, 1.1f};
    int n = sizeof(cuts) / sizeof(cuts[0]);
    int i;

    quicksort(cuts, 0, n - 1);

    printf("sorted cut-list:");
    for (i = 0; i < n; i++) {
        printf(" %.1f", cuts[i]);   /* 0.8 1.1 1.6 2.4 3.2 */
    }
    printf("\n");
    return 0;
}
