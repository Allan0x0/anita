/* Week 2 - Day 5 - Pointers proper: &x, *p, p->field
 * gcc -Wall day5_pointers.c -o day5   then   ./day5
 * A pointer is a variable that holds an ADDRESS, not a value.
 * TODO: declare a second int, point p at it instead, and print through p.
 */
#include <stdio.h>

struct Member {
    float length;
    int angle;
    char type;
};

int main(void) {
    int angle = 45;
    int *p = &angle;    /* p holds the ADDRESS of angle */

    printf("angle = %d\n", angle);
    printf("&angle (address) = %p\n", (void *) &angle);
    printf("*p (value at that address) = %d\n", *p);

    *p = 60;             /* writing through the pointer changes angle */
    printf("angle after *p = 60 : %d\n", angle);

    struct Member m = {2.5, 45, 'T'};
    struct Member *mp = &m;
    printf("mp->length = %.1f (same as m.length = %.1f)\n", mp->length, m.length);
    return 0;
}
