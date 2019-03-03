#include <stdlib.h>
#include <stdio.h>

#include "../include/deque.h"

void printboth(struct deque *d) {
    printf("Printing forwards:");
    deq_print(d);
    printf("\n");

    printf("Printing backwards:");
    deq_print_reverse(d);
    printf("\n");
}

int main() {
    struct deque *d = calloc(1, sizeof(struct deque));
    printboth(d);

    for(int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            printf("Adding first: %d\n", i);
            deq_addFirst(d, i);
        }
        else {
            printf("Adding last: %d\n", i);
            deq_addLast(d, i);
        }
    }
    printboth(d);

    printf("Removing back, received value: (%d)\n", deq_rmvLast(d));
    printf("Removing front, received value: (%d)\n", deq_rmvFirst(d));
    printboth(d);

    return 0;
}

