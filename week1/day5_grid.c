/* Week 1 - Day 5 - 2-D array: many trusses
 * gcc day5_grid.c -o day5   then   ./day5
 * roof[t][m] = truss t, member m. A grid needs two nested loops.
 * TODO: print a grand total for the whole roof.
 */
#include <stdio.h>

int main(void) {
    float roof[3][4] = {
        {2.5, 2.5, 3.0, 1.2},
        {2.6, 2.6, 3.1, 1.3},
        {2.4, 2.4, 2.9, 1.1}
    };
    int t, m;
    for (t = 0; t < 3; t++) {
        float sum = 0.0;
        for (m = 0; m < 4; m++) sum = sum + roof[t][m];
        printf("Truss %d total: %.1f m\n", t, sum);
    }
    return 0;
}
