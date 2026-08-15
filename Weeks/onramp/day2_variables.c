/* Day 2 - Variables & types
 * Compile:  gcc day2_variables.c -o day2
 * Run:      ./day2
 *
 * TODO (build step): change span to 8.5 and grade to 'A', run again.
 */
#include <stdio.h>

int main(void) {
    int   members = 7;      /* whole number  -> int   */
    float span    = 6.0;    /* metres        -> float */
    float pitch   = 30.0;   /* roof angle    -> float */
    char  grade   = 'B';    /* one character -> char  */

    printf("Members: %d\n", members);
    printf("Span: %.1f m\n", span);
    printf("Pitch: %.0f degrees\n", pitch);
    printf("Grade: %c\n", grade);
    return 0;
}
