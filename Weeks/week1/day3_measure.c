/* Week 1 - Day 3 - Total, longest, shortest (one walk = O(n))
 * gcc day3_measure.c -o day3   then   ./day3
 * TODO: also count members longer than 2.0 m.
 */
#include <stdio.h>

int main(void) {
    float cut[7] = {2.5, 2.5, 3.0, 3.0, 1.8, 1.8, 1.2};
    int i;
    float total = 0.0, longest = cut[0], shortest = cut[0];

    for (i = 0; i < 7; i++) {
        total = total + cut[i];
        if (cut[i] > longest)  longest  = cut[i];
        if (cut[i] < shortest) shortest = cut[i];
    }
    printf("Total timber: %.1f m\n", total);
    printf("Longest: %.1f m,  Shortest: %.1f m\n", longest, shortest);
    return 0;
}
