/* BITH132 Week 7, Day 4: Sorting and searching recap (Units 8-9)
 * Build & run: gcc -Wall day4_recap.c -o out && ./out
 *
 * Bubble sort is O(n^2): it compares nearly every pair, so cost grows with
 * the square of the input size. Binary search is O(log n), but only on
 * sorted input: each comparison halves the range left to search. Linear
 * search needs no sorting but costs O(n): it may check every slot.
 *
 * This program counts real comparisons for linear vs binary search on the
 * same sorted array, so the O(n) vs O(log n) gap is a number, not a claim.
 *
 * TODO (Build it): grow the array to 100 sorted values and print how the
 * comparison counts change; linear grows with n, binary barely moves.
 */
#include <stdio.h>

int linear_search(int arr[], int n, int target, int *comparisons) {
    int i;
    *comparisons = 0;
    for (i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == target) return i;
    }
    return -1;
}

int binary_search(int arr[], int n, int target, int *comparisons) {
    int lo = 0, hi = n - 1;
    *comparisons = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        (*comparisons)++;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;   /* drop the left half */
        else hi = mid - 1;                          /* drop the right half */
    }
    return -1;
}

int main(void) {
    int cuts[] = {10, 20, 30, 40, 50, 60, 70, 80};   /* must be sorted for binary search */
    int n = sizeof(cuts) / sizeof(cuts[0]);
    int target = 70;
    int cmp_lin, cmp_bin;
    int idx_lin = linear_search(cuts, n, target, &cmp_lin);
    int idx_bin = binary_search(cuts, n, target, &cmp_bin);

    printf("array size: %d, target: %d\n", n, target);
    printf("linear search: found at index %d, %d comparisons (O(n))\n", idx_lin, cmp_lin);
    printf("binary search: found at index %d, %d comparisons (O(log n))\n", idx_bin, cmp_bin);

    return 0;
}
