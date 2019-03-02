#ifndef _DEQUE_H
#define _DEQUE_H

struct deque {
    struct node_dub *pfirst;
    struct node_dub *plast;
};

void deq_addFirst(struct deque * deq, int val);
void deq_addLast(struct deque * deq, int val);

int deq_rmvFirst(struct deque * deq);
int deq_rmvLast(struct deque * deq);

int deq_empty(struct deque * deq);

#endif
