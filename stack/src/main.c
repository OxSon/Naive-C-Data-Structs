#include <stdlib.h>
#include <stdio.h>

#include "../include/stack.h"

int main() {
    struct stack *pstack = calloc(1, sizeof(struct stack));
    fprintf(stderr, "stack is empty: %d\n", stack_isempty(pstack));

    stack_push(pstack, 10);
    stack_push(pstack, 20);
    stack_push(pstack, 30);

    fprintf(stderr, "peeking: %d\n", stack_peek(pstack));
    fprintf(stderr, "popping: %d\n", stack_pop(pstack));

    printf("Printing stack: ");
    stack_print(pstack);
    printf("\n");

    fprintf(stderr, "stack is empty: %d\n", stack_isempty(pstack));

    return 0;
}
