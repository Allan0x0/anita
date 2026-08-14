/* Week 3 - Day 2 - Insert into an array: everything after must shift
 * gcc -Wall day2_shift.c -o day2   then   ./day2
 * Inserting a Member mid-array means moving every later Member one box
 * right first. That is n moves in the worst case: O(n).
 * TODO: write a delete_at(truss, &n, pos) that shifts left instead.
 */
#include <stdio.h>
#define CAP 6

struct Member {
    float length;
    int angle;
    char type;
};

/* insert m at position pos, shifting truss[pos..n-1] right by one */
void insert_at(struct Member truss[], int *n, int pos, struct Member m) {
    int i;
    int shifts = 0;

    for (i = *n; i > pos; i--) {
        truss[i] = truss[i - 1];   /* one move, one shift counted */
        shifts++;
    }
    truss[pos] = m;
    *n = *n + 1;
    printf("inserted at %d, shifts made: %d\n", pos, shifts);
}

int main(void) {
    struct Member truss[CAP] = {
        {2.5, 0,  'T'},
        {3.0, 45, 'C'},
        {2.5, 0,  'T'}
    };
    int n = 3;
    int i;
    struct Member brace;

    brace.length = 1.8;
    brace.angle = 90;
    brace.type = 'B';

    insert_at(truss, &n, 1, brace);   /* insert mid-array: 2 shifts */

    for (i = 0; i < n; i++) {
        printf("Member %d: %.1f m (%c)\n", i, truss[i].length, truss[i].type);
    }
    return 0;
}
