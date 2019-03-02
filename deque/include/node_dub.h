#ifndef _NODE_DUB_H
#define _NODE_DUB_H

struct node_dub {
    struct node_dub * pnext;
    struct node_dub * pprev;
    int item;
};

#endif /*_NODE_DUB_H*/
