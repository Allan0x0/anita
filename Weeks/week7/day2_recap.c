/* BITH132 Week 7, Day 2: Structs and pointers recap (Units 3-4)
 * Build & run: gcc -Wall day2_recap.c -o out && ./out
 *
 * A struct bundles related fields under one name: struct Member models one
 * truss piece with a length, an angle, and a type ('T' tension, 'C' compression).
 *
 * A pointer holds an address, not a value. "&m" reads as "the address of m".
 * Once you have that address in a pointer, "->" reaches through it to read
 * or change the fields it points at, no copy involved.
 *
 * TODO (Build it): write a function that takes struct Member *m and doubles
 * its length through the pointer; confirm the caller's copy changed too.
 */
#include <stdio.h>

struct Member {
    float length;
    int angle;
    char type;
};

void print_member(const struct Member *m) {
    printf("Member: length=%.1f angle=%d type=%c\n", m->length, m->angle, m->type);
}

int main(void) {
    struct Member rafter;
    rafter.length = 3.6f;
    rafter.angle = 30;
    rafter.type = 'C';

    struct Member *p = &rafter;   /* p holds the address of rafter */

    print_member(p);              /* pointer read via -> */
    p->angle = 35;                /* pointer write via -> */
    printf("after edit through pointer: angle=%d\n", rafter.angle);

    return 0;
}
