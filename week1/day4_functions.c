/* Week 1 - Day 4 - Pass the array to functions
 * gcc day4_functions.c -o day4   then   ./day4
 * Pass the array NAME (no brackets) plus its size n.
 * TODO: write float longest_member(float cut[], int n) and call it.
 */
#include <stdio.h>
#define N 7

float total_timber(float cut[], int n) {
    int i; float t = 0.0;
    for (i = 0; i < n; i++) t = t + cut[i];
    return t;
}

void print_cut(float cut[], int n) {
    int i;
    for (i = 0; i < n; i++) printf("  [%d] %.1f m\n", i, cut[i]);
}

int main(void) {
    float cut[N] = {2.5, 2.5, 3.0, 3.0, 1.8, 1.8, 1.2};
    print_cut(cut, N);
    printf("Total: %.1f m\n", total_timber(cut, N));
    return 0;
}
