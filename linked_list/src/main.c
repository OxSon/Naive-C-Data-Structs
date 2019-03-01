#include <stdlib.h>
#include <stdio.h>

/* node data is stored here */
#include "../include/node.h"


/**
 * Call function main as follows: ./main 1 2 3 4 5 6 7 8...
 */
int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "Need at least 1 argument!", argc);
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "main called with %d arguments\n", argc);
    /**
     * Create an array to hold the arguments (not really necessary, but for
     * demonstration how to use calloc.
     * calloc is better than malloc since it automatically initializes its data
     * to `0`. with malloc the data is uninitialized!
     */
    int length = argc-1;
    int *data = calloc(sizeof(int), argc);
    /* Get user input. note: first argument is at argv[1] */
    for (int i = 0; i < length; ++i) {
        data[i] = atoi(argv[i+1]);
    }

    /**
     * The original way this was done was bad for two reasons.
     * First of all, if the list were empty, then there would only be one node,
     * and it would be completely uninitialized.
     *
     * Furthermore, for any other size, there will be one extra element at the
     * end of the list (since the loop creates a node every loop, and there's
     * one at the beginning, there will always be n+1 nodes).
     * In either case, the last node is uninitialized, which means that there's
     * no `NULL` at the end of the list which is really bad.
     *
     * Instead, we will set up the list differently.
     */
    struct node *head, *current;
    head = current = NULL;

    /* set up our list */
    for (int i = 0; i < length; ++i) {
        /* allocate the current node */
        if (!current) {
            /* if we don't have a current node, allocate it */
            current = head = malloc(sizeof(struct node));
        } else {
            /* else just add it to the end of the list */
            current->pnext = malloc(sizeof(struct node));
            current = current->pnext;
        }
        current->item = data[i]; //set data for current node

    }

    current = head;
    //print it
    /**
     * The former loop condition `current->pnext != null` was incorrect.
     * This was printing all the elements except for the last one.
     * This worked fine with the above, since there was always one extra node,
     * but now there isn't so we change the iteration to go over the whole list.
     */
    while(current != NULL) {
        printf("(%d) ", current->item);
        current = current->pnext;
    }
    printf("\n");//blank line for formatting



    // Remove twice
    for(int i = 0; i < 2; i++) {
        struct node *old_head = head;
        head = head->pnext;
        free(old_head);
    }

    /* Just for reference, another way to print it: */
    for (current = head; current != NULL; current = current->pnext) {
        printf("(%d) ", current->item);

    }
    puts("\n");

    return 0;
}
