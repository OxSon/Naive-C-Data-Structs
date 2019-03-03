#include <stdlib.h>
#include <stdio.h>

#include "../include/node_dub.h"
#include "../include/deque.h"

void deq_addFirst(struct deque * deq, int val){
    struct node_dub *old_first = deq->pfirst;
    deq->pfirst = calloc(1, sizeof(struct node_dub));

    if(old_first != NULL) {
        deq->pfirst->pnext = old_first;//new node points forward to old first
        old_first->pprev = deq->pfirst;//old first points backwards to new node
    } else {
        //last is now also first if deque was previously empty
        deq->plast = deq->pfirst;
    }

    deq->pfirst->item = val;
}

void deq_addLast(struct deque * deq, int val){
    struct node_dub *old_last = deq->plast;
    deq->plast = calloc(1, sizeof(struct node_dub));

    if(old_last != NULL) {
        deq->plast->pprev = old_last;//new node points backwards towards old last
        old_last->pnext = deq->plast;//old last points forwards towards new node
    } else {
        //first is now also last if deque was previously empty
        deq->pfirst = deq->plast;
    }

    deq->plast->item = val;
}

int deq_rmvFirst(struct deque * deq){
    struct node_dub *old_first = deq->pfirst; //get current first
    int val = old_first->item; //store item stored in that node

    deq->pfirst = old_first->pnext; //make new first = old firsts next pointer
    deq->pfirst->pprev = NULL; //null it out FIXME is this necessary?
    free(old_first);//TODO is this the right way to do this? unsure

    return val;
}

int deq_rmvLast(struct deque * deq){
    struct node_dub *old_last = deq->plast;
    int val = old_last->item;

    deq->plast = old_last->pprev;
    deq->plast->pnext = NULL;
    free(old_last);
    //TODO is this the right way to do this? unsure
    return val;
}

int deq_empty(struct deque * deq){
    return deq->pfirst == NULL;
}

void deq_print(struct deque * deq) {
    struct node_dub *current;
    for(current = deq->pfirst; current != NULL; current = current->pnext) {
        printf("(%d) ", current->item);
    }
}

void deq_print_reverse(struct deque * deq) {
    struct node_dub *current;
    for(current = deq->plast; current != NULL; current = current->pprev) {
        printf("(%d) ", current->item);
    }
}
