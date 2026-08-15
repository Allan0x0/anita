/* BITH132 Week 7, Day 6: Full efficiency recap, O(n) vs O(log n) made visible
 * Build & run: gcc -Wall day6_efficiency.c -o out && ./out
 *
 * Same idea as Day 4, wider lens: this counts real operations across a
 * growing input, then prints a small Big-O summary table. Linear work
 * doubles when n doubles; log work barely moves. That gap is the whole
 * reason the exam asks you to pick the right structure before you code.
 *
 * TODO (Build it): add n = 1000000 to the sizes array and see how few
 * extra steps binary search needs to cover a million-sized jump.
 */
#include <stdio.h>

/* count steps a linear scan takes over n items (worst case) */
int linear_steps(int n) {
    return n;
}

/* count steps binary search takes over n sorted items (worst case) */
int binary_steps(int n) {
    int steps = 0;
    int range = n;
    while (range > 0) {
        steps++;
        range = range / 2;
    }
    return steps;
}

int main(void) {
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int count = sizeof(sizes) / sizeof(sizes[0]);
    int i;

    printf("%-10s %-14s %-14s\n", "n", "linear O(n)", "binary O(log n)");
    for (i = 0; i < count; i++) {
        int n = sizes[i];
        printf("%-10d %-14d %-14d\n", n, linear_steps(n), binary_steps(n));
    }

    printf("\nBig-O summary (typical structure, worst case):\n");
    printf("%-10s %-10s %-10s %-10s\n", "structure", "insert", "search", "traverse");
    printf("%-10s %-10s %-10s %-10s\n", "array",     "O(n)",  "O(n)",  "O(n)");
    printf("%-10s %-10s %-10s %-10s\n", "sorted arr","O(n)",  "O(log n)", "O(n)");
    printf("%-10s %-10s %-10s %-10s\n", "list",      "O(1)",  "O(n)",  "O(n)");
    printf("%-10s %-10s %-10s %-10s\n", "stack",     "O(1)",  "O(n)",  "O(n)");
    printf("%-10s %-10s %-10s %-10s\n", "queue",     "O(1)",  "O(n)",  "O(n)");
    printf("%-10s %-10s %-10s %-10s\n", "BST(bal.)", "O(log n)", "O(log n)", "O(n)");

    return 0;
}
