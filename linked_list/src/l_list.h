#ifndef _L_LIST_H
#define _L_LIST_H

struct l_list {
    struct node *phead;
    struct node *ptail;
};

void add(struct node *pnode);

void get(struct l_list *plist);

#endif
