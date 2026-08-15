/* Day 6 - Functions & strings
 * Compile:  gcc day6_functions.c -o day6
 * Run:      ./day6
 *
 * TODO (build step): call truss_height a second time with a different
 * span and print that too. One function, used twice.
 */
#include <stdio.h>

/* rough truss height from span and pitch (simplified on purpose) */
float truss_height(float span, float pitch_deg) {
    float factor = pitch_deg / 100.0;
    return (span / 2.0) * factor;
}

int main(void) {
    char label[10] = "TC1";              /* top chord, member 1 */
    float h = truss_height(6.0, 30.0);
    printf("Member %s\n", label);
    printf("Approx height: %.2f m\n", h);
    return 0;
}
