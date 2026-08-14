/* Week 2 - Day 4 - Pass a struct by value vs by pointer
 * gcc -Wall day4_byvalue.c -o day4   then   ./day4
 * By value copies the whole struct into the function; by pointer shares it.
 * TODO: write a second by-value function that tries to grow the length
 *       and prove the caller's copy is unchanged.
 */
#include <stdio.h>

struct Member {
    float length;
    int angle;
    char type;
};

/* by value: gets a COPY, cannot change the caller's Member */
void print_member(struct Member m) {
    printf("Member: %.1f m at %d deg (%c)\n", m.length, m.angle, m.type);
}

/* by pointer: reaches the ORIGINAL Member, no copy made */
void grow_member(struct Member *m, float extra) {
    m->length = m->length + extra;
}

int main(void) {
    struct Member web = {1.8, 60, 'T'};
    print_member(web);          /* copy goes in, original untouched */
    grow_member(&web, 0.2);     /* &web: address of web, a pointer */
    print_member(web);          /* original really changed */
    return 0;
}
