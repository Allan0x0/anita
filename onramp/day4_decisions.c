/* Day 4 - Decisions (if / else)
 * Compile:  gcc day4_decisions.c -o day4
 * Run:      ./day4     try 15, then 2, then 6 - each hits a different line.
 */
#include <stdio.h>

int main(void) {
    float span;
    printf("Enter the span in metres: ");
    scanf("%f", &span);

    if (span > 12.0) {
        printf("Too wide - needs an engineer.\n");
    } else if (span < 3.0) {
        printf("Very small - a single beam may do.\n");
    } else {
        printf("Standard truss territory. Good.\n");
    }
    return 0;
}
