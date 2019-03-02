#include <stdlib.h>

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
}

int deq_rmvFirst(struct deque * deq){
    int val = deq->pfirst->item;
    //TODO is this the right way to do this? unsure
    free(deq->pfirst);
    deq->pfirst = NULL;

    return val;
}

int deq_rmvLast(struct deque * deq){
    //TODO
    return 0;
}

int deq_empty(struct deque * deq){
    return deq->pfirst == NULL;
}
