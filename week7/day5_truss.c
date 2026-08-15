/* BITH132 Week 7, Day 5: The finished roof-truss helper (Units 1-9 tied together)
 * Build & run: gcc -Wall day5_truss.c -o out && ./out
 *
 * This is the spine app finished. One struct Member models a truss piece
 * (Units 3-4). An array of Members is the cut-list (Unit 1). A bubble sort
 * orders it by length so offcuts are easy to spot (Unit 8). A linear search
 * finds a member by its char type (Unit 9), because type is not ordered so
 * binary search does not apply here. Print, sort, search: the same three
 * moves every week built toward.
 *
 * TODO (Build it): add a second search that finds the longest 'C' (compression)
 * member using the same array, no new data structure needed.
 */
#include <stdio.h>

struct Member {
    float length;
    int angle;
    char type;   /* 'T' tension, 'C' compression */
};

void print_cutlist(struct Member list[], int n) {
    int i;
    printf("cut-list (%d members):\n", n);
    for (i = 0; i < n; i++) {
        printf("  #%d length=%.1f angle=%d type=%c\n",
               i, list[i].length, list[i].angle, list[i].type);
    }
}

/* bubble sort ascending by length: O(n^2), fine for a small cut-list */
void sort_by_length(struct Member list[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (list[j].length > list[j + 1].length) {
                struct Member tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

/* linear search: O(n), type is not ordered so a scan is the honest choice */
int find_by_type(struct Member list[], int n, char type) {
    int i;
    for (i = 0; i < n; i++) {
        if (list[i].type == type) return i;
    }
    return -1;
}

int main(void) {
    struct Member truss[] = {
        {3.6f, 30, 'C'},
        {2.4f, 45, 'T'},
        {4.2f, 30, 'C'},
        {1.8f, 90, 'T'},
        {3.0f, 45, 'T'}
    };
    int n = sizeof(truss) / sizeof(truss[0]);
    int idx;

    printf("--- before sort ---\n");
    print_cutlist(truss, n);

    sort_by_length(truss, n);
    printf("\n--- after sort by length (kill offcuts fast) ---\n");
    print_cutlist(truss, n);

    idx = find_by_type(truss, n, 'C');
    printf("\nfirst compression member: index %d, length=%.1f\n",
           idx, idx >= 0 ? truss[idx].length : 0.0f);

    return 0;
}
