/* Week 1 - Day 1 - Declare an array
 * gcc day1_declare.c -o day1   then   ./day1
 * Arrays count from 0: cut[7] has boxes cut[0]..cut[6].
 */
#include <stdio.h>

int main(void) {
    float cut[7];       /* 7 boxes: cut[0] .. cut[6] */
    cut[0] = 2.5;
    cut[1] = 2.5;
    cut[2] = 3.0;
    printf("First member: %.1f m\n", cut[0]);
    printf("Third member: %.1f m\n", cut[2]);
    return 0;
}
