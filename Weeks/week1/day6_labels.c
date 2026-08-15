/* Week 1 - Day 6 - Strings are char arrays (Unit 2 preview)
 * gcc day6_labels.c -o day6   then   ./day6
 * A string ends with a hidden \0. members[4][5] = 4 labels, up to 4 chars + \0.
 * TODO: print each member with its label AND its length from the cut-list.
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char label[] = "TC1";
    printf("Label: %s\n", label);
    printf("First char: %c\n", label[0]);
    printf("Length: %d\n", (int) strlen(label));

    char members[4][5] = {"TC1", "TC2", "BC1", "KP1"};
    int i;
    for (i = 0; i < 4; i++) printf("Member %d: %s\n", i, members[i]);
    return 0;
}
