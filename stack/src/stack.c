#include <stdlib.h>
#include <stdio.h>

#include "../include/node.h"
#include "../include/stack.h"

void stack_push(struct stack *pstack, int val) {
    struct node *old_top = pstack->ptop;

    //make top point towards new node with item = val, pnext = old top
    pstack->ptop = malloc(sizeof(struct node));
    pstack->ptop->pnext = old_top;
    pstack->ptop->item = val;
}

int stack_pop(struct stack *pstack) {
    int top_val = pstack->ptop->item; //store value on top of stack

    //store pointer to old top
    struct node *old_top = pstack->ptop;
    //change stack struct member top to point to old top's next
    pstack->ptop = pstack->ptop->pnext;
    free(old_top); //free old top of stack

    return top_val;
}

int stack_peek(struct stack *pstack) {
    return pstack->ptop->item;
}

void stack_print(struct stack * pstack) {
    for(struct node *current = pstack->ptop; current != NULL; current = current->pnext) {
        printf("(%d) ", current->item);
    }
}

int stack_isempty(struct stack *pstack) {
    return pstack->ptop == NULL;
}

//TODO
/*Wishlist: provide fprintf-like printing functionality*/
//void stack_fprint() {
//}

