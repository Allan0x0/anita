/* Day 5 - Loops (for)
 * Compile:  gcc day5_loops.c -o day5
 * Run:      ./day5
 *
 * TODO (build step): change rafters to 8, and add a 4th length.
 * Remember to change [3] to [4] AND the loop limit 3 to 4.
 */
#include <stdio.h>

int main(void) {
    int i, rafters = 5;
    for (i = 1; i <= rafters; i++) {
        printf("Rafter %d cut and ready\n", i);
    }

    float lengths[3] = {2.5, 3.0, 2.5};   /* an array - a row of boxes */
    float total = 0.0;
    for (i = 0; i < 3; i++) {
        total = total + lengths[i];
    }
    printf("Total timber: %.1f m\n", total);
    return 0;
}
