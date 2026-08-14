/* Week 1 - Day 2 - Fill, then loop
 * gcc day2_fill.c -o day2   then   ./day2
 */
#include <stdio.h>

int main(void) {
    float cut[7] = {2.5, 2.5, 3.0, 3.0, 1.8, 1.8, 1.2};
    int i;
    for (i = 0; i < 7; i++) {
        printf("Member %d: %.1f m\n", i, cut[i]);
    }
    return 0;
}
