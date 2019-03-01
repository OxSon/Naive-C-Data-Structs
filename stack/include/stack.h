#ifndef _STACK_H
#define _STACK_H

/*linked-list implementation of a stack*/
struct stack {
    /*top of the stack*/
    struct node *ptop;
};

/*Adds a new node to the stack that holds the int value provided as argument*/
void stack_push(struct stack *pstack, int val);

/*Returns int value stored in stacks top node and removes said node from the stack*/
int stack_pop(struct stack *pstack);

/*Returns int value stored in stacks top node without removing it*/
int stack_peek(struct stack *pstack);

/*Prints all elements in the stack on one line*/
void stack_print(struct stack * pstack);

/*Returns 1 if stack is empty otherwise 0*/
int stack_isempty(struct stack * pstack);

//TODO
/*Wishlist: provide fprintf-like printing functionality*/
//void stack_fprint() {
//}

#endif /* _STACK_H */
