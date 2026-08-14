/* Week 2 - Day 3 - An array of structs: the truss
 * gcc -Wall day3_truss.c -o day3   then   ./day3
 * A truss is many Members in a row, same as Week 1's cut-list array.
 * TODO: add a 5th Member to the array and update N; the loop just follows.
 */
#include <stdio.h>
#define N 4

struct Member {
    float length;
    int angle;
    char type;
};

int main(void) {
    struct Member truss[N] = {
        {2.5, 0,  'T'},
        {3.0, 45, 'C'},
        {3.0, 45, 'C'},
        {2.5, 0,  'T'}
    };
    int i;
    float total = 0.0;

    for (i = 0; i < N; i++) {                 /* one walk, O(n) */
        printf("Member %d: %.1f m at %d deg (%c)\n",
               i, truss[i].length, truss[i].angle, truss[i].type);
        total = total + truss[i].length;
    }
    printf("Total timber: %.1f m\n", total);
    return 0;
}
