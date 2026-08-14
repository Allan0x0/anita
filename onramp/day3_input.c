/* Day 3 - Input
 * Compile:  gcc day3_input.c -o day3
 * Run:      ./day3   then type a number and press Enter
 *
 * The & before span means "the address of span" - it tells scanf
 * WHERE to store what you typed. This idea grows into pointers (Unit 4).
 */
#include <stdio.h>

int main(void) {
    float span;
    printf("Enter the span in metres: ");
    scanf("%f", &span);
    printf("You entered %.2f m\n", span);
    return 0;
}
