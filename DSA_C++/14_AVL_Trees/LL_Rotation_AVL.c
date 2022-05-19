#include <stdio.h>

struct Node {
    struct Node *lchild;
    int data;
    int height;   // for AVL tree we need to maintain the balance factor for each node, for which we need to use height
    struct Node *rchild;
}*root = NULL;  // global pointer root


int NodeHeight(struct Node * p) {
    int hl, hr;                         // hl - height of left subtree, hr - height of right subtree
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl>hr ? hl+1 : hr+1;
}


// function for finding the balance factor of a node
int BalanceFactor(struct Node * p) {
    int hl, hr;
    hl = p && p -> lchild ? p -> lchild -> height : 0;
    hr = p && p -> rchild ? p -> rchild -> height : 0;

    return hl - hr;
}

struct Node * LLRotation(struct Node * p) {
    struct Node * pl = p -> lchild;         // pl - pointer to left child of p
    struct Node * plr = pl -> rchild;       // plr - pointer to right child of pl

    pl -> rchild = p;                       // plr is the new right child of p
    p -> lchild = plr;                      // plr is the right child of p
    p -> height = NodeHeight(p);            // update height of p
    pl -> height = NodeHeight(pl);          // updating height of pl

    if (root == p)                          // if p is root, then pl is root now
        root = pl;                          // if p is root, then pl is root now

    return pl;                              // return the new root
}

struct Node * LRRotation(struct Node * p) { // the 3 nodes which will be involved in the rotation are p, pl and plr
    struct Node *pl = p->lchild;         // pl - left child of p
    struct Node *plr = pl->rchild;       // plr - right child of pl

    pl->rchild = plr->lchild;           //  the right child of pl becomes plr's left child 
    p->lchild = plr->rchild;            //   the left child of p becomes plr's right child

    plr->lchild = pl;                     // pl becomes the left child of plr
    plr->rchild = p;                      // p becomes the right child of plr

    pl->height = NodeHeight(pl);          // updating height of pl
    p->height = NodeHeight(p);            // updating height of p
    plr->height = NodeHeight(plr);        // updating height of plr

    if (root == p)                          // if p is root
        root = plr;                         // if p is root, then plr is root now
    return plr;                             // return the new root
}

struct Node * RRRotation(struct Node * p) {
    struct Node * pr = p -> rchild;         // pr - right child of p
    struct Node * prl = pr -> lchild;       // prl - left child of pr

    pr -> lchild = p;                       // p becomes the left child of pr
    p -> rchild = prl;                      // prl becomes the right child of p

    p -> height = NodeHeight(p);            // updating height of p
    pr -> height = NodeHeight(pr);          // updating height of pr
    prl -> height = NodeHeight(prl);        // updating height of prl

    if (root == p)                          // if p is root
        root = pr;                          // if p is root, then pr is root now
    return pr;                              // return the new root
}

struct Node * RLRotation(struct Node * p) {
    return NULL;
}

struct Node * RInsert(struct Node * p, int key) {
    struct Node * t = NULL;

    if (p == NULL)              // this is where we were creating the first node
    {                           
        t = (struct Node *) malloc(sizeof(struct Node));
        t -> data = key;
        t -> height = 1;                                // height of new node is 1
        t -> lchild = t -> rchild = NULL;
        return t;
    }
    if (key < p -> data)
        p -> lchild = RInsert(p -> lchild, key);
    else if (key > p -> data)
        p -> rchild = RInsert(p -> rchild, key);

    p->height = NodeHeight(p);                    // at returning time we need to update the height of the node

    // after updating the height we have to check whether the tree is balanced or not by checking the BalanceFactor()
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)    // if the balance factor is 2 (means the node is imbalanced) and the left child of the node is 1 then we need to do LL rotation
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p ->rchild) == 1)  // (p ->rchild) == 1 means if the node is heavy on the RHS then we need to do RLRotation
        return RLRotation(p);
    return p;

}
int main() {

    // LL rotation input
    // root = RInsert(root, 10);
    // RInsert(root, 5);
    // RInsert(root, 2);

    // LR rotation input
    root = RInsert(root, 50);           // creating the root node 50
    RInsert(root, 10);                  // inserting the nodes  this will be the left child of 50
    RInsert(root, 20);                  // inserting the nodes  this will be the right child of 50



    return 0;
}