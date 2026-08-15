/* Week 3 - Day 1 - Pointer arithmetic: walk an array with a moving pointer
 * gcc -Wall day1_ptrwalk.c -o day1   then   ./day1
 * truss[i] and *(truss + i) reach the same box. A pointer can also walk
 * by itself: p++ moves it to the next Member, no index needed.
 * TODO: add a 5th Member and update N; the walk just follows.
 */
#include <stdio.h>
#define N 4

struct Member {
    float length;
    int angle;
    char type;   /* 'T' tension, 'C' compression */
};

int main(void) {
    struct Member truss[N] = {
        {2.5, 0,  'T'},
        {3.0, 45, 'C'},
        {3.0, 45, 'C'},
        {2.5, 0,  'T'}
    };
    struct Member *p;
    int i;

    /* by index: truss[i] */
    for (i = 0; i < N; i++) {
        printf("index  %d: %.1f m (%c)\n", i, truss[i].length, truss[i].type);
    }

    /* by pointer arithmetic: same boxes, no index at all */
    for (p = truss; p < truss + N; p++) {
        printf("pointer  : %.1f m (%c)\n", p->length, p->type);
    }

    /* truss[2] and *(truss + 2) are the same box */
    printf("truss[2].length = %.1f, (*(truss + 2)).length = %.1f\n",
           truss[2].length, (*(truss + 2)).length);

    return 0;
}
