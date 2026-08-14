/* Week 2 - Day 2 - Initialize and print a Member
 * gcc -Wall day2_init.c -o day2   then   ./day2
 * A struct literal fills every field at once, in order.
 * TODO: make a second Member with your own values and print it too.
 */
#include <stdio.h>

struct Member {
    float length;
    int angle;
    char type;
};

int main(void) {
    struct Member top_chord = {3.0, 30, 'C'};
    printf("Top chord: %.1f m at %d deg, type %c\n",
           top_chord.length, top_chord.angle, top_chord.type);

    top_chord.length = 3.2;   /* fields can be changed after the fact */
    printf("Adjusted length: %.1f m\n", top_chord.length);
    return 0;
}
