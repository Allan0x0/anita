/* Week 2 - Day 1 - Declare a struct
 * gcc -Wall day1_member.c -o day1   then   ./day1
 * A struct bundles related fields under one name: a truss Member.
 * TODO: add a fourth field, e.g. "float force;", and print it too.
 */
#include <stdio.h>

struct Member {
    float length;
    int angle;
    char type;   /* 'T' tension, 'C' compression */
};

int main(void) {
    struct Member m;   /* one blank Member: three fields in one box */
    m.length = 2.5;
    m.angle = 45;
    m.type = 'T';
    printf("Member: length=%.1f angle=%d type=%c\n", m.length, m.angle, m.type);
    return 0;
}
