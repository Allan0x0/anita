/* BITH132 Week 7, Day 1: Arrays and strings recap (Units 1-2)
 * Build & run: gcc -Wall day1_recap.c -o out && ./out
 *
 * An array is a fixed-size run of same-type slots sitting back to back in
 * memory. A cut-list is exactly this: N member lengths, one float per slot.
 * A string is just a char array with a NUL byte ('\0') marking the end, so
 * a label like "rafter" is a small array too.
 *
 * Any loop that touches every slot once (print it, sum it, count matches)
 * does N units of work for N slots: that is O(n), linear in the input size.
 *
 * TODO (Build it): add a fourth cut length, resize the array, and confirm
 * the loop still visits every slot with no code changes beyond the count.
 */
#include <stdio.h>

int main(void) {
    float cuts[] = {2.4f, 1.8f, 3.0f};
    int n = sizeof(cuts) / sizeof(cuts[0]);
    char label[] = "rafter";
    int i;
    float total = 0.0f;

    printf("cut-list (%d members): ", n);
    for (i = 0; i < n; i++) {
        printf("%.1f ", cuts[i]);
        total += cuts[i];   /* one loop, O(n): touches each slot once */
    }
    printf("\n");

    printf("label: %s (length %d chars, plus 1 for '\\0')\n",
           label, (int)sizeof(label) - 1);
    printf("total cut length: %.1f\n", total);

    return 0;
}
