/* Week 2 - Day 6 - Tie it together: mutate a truss through pointers
 * gcc -Wall day6_mutate.c -o day6   then   ./day6
 * A function takes Member* (one) or Member array (many) and mutates
 * the real data through the pointer, no copies made.
 * TODO: write void scale_truss(struct Member truss[], int n, float factor)
 *       that multiplies every length by factor, then call it from main.
 */
#include <stdio.h>
#define N 3

struct Member {
    float length;
    int angle;
    char type;
};

/* one Member, changed through a pointer */
void bump_angle(struct Member *m, int extra) {
    m->angle = m->angle + extra;
}

/* many Members: array of structs, walked O(n), changed in place */
void print_truss(struct Member truss[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Member %d: %.1f m at %d deg (%c)\n",
               i, truss[i].length, truss[i].angle, truss[i].type);
    }
}

int main(void) {
    struct Member truss[N] = {
        {2.5, 0,  'T'},
        {3.0, 45, 'C'},
        {2.5, 0,  'T'}
    };

    print_truss(truss, N);
    bump_angle(&truss[1], 5);   /* mutate one Member through its address */
    printf("After bump:\n");
    print_truss(truss, N);
    return 0;
}
