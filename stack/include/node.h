/* We use the preprocessor to make sure this file is never included twice */
#ifndef _NODE_H
#define _NODE_H

/*A linked-list node that stores ints*/
struct node {
    /*Next node in the list*/
    struct node *pnext;
    /*Value stored in this node*/
    int item;
};

/*None of the below are actually implemented or used anywhere, currently*/
//void node_addnext(struct node *pnext);
//struct node * node_getnext(struct node *pfrom);
//void node_setitem(struct node *pnode, int item);

#endif /* _NODE_H */
