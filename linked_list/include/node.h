/* We use the preprocessor to make sure this file is never included twice */
#ifndef _NODE_H
#define _NODE_H

struct node {
    struct node *pnext;
    int item;

};

void addnext(struct node *pnext);

struct node * getnext(struct node *pfrom);

void setitem(struct node *pnode, int item);

#endif /* _NODE_H */
