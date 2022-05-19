#include <iostream>

 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class BST{
private:
    Node* root;
public:
    BST(){ root = nullptr; }
    Node* getRoot(){ return root; }
    void iInsert(int key);
    void Inorder(Node* p);
    Node* iSearch(int key);
    Node* rInsert(Node* p, int key);
    Node* rSearch(Node* p, int key);
    Node* Delete(Node* p, int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
};
 
void BST::iInsert(int key) {
 
    Node* t = root;
    Node* p;
    Node* r;
 
    // root is empty
    if (root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
 
    while(t != nullptr){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }
 
    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;
 
    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }
 
}
 
void BST::Inorder(Node* p) {
    if (p){
        Inorder(p->lchild);
        std::cout << p->data << ", ";
        Inorder(p->rchild);
    }
}
 
Node* BST::iSearch(int key) {
    Node* t = root;
    while (t != nullptr){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return nullptr;
}


// recursive insert
Node* BST::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }
 
    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }
    return p;  // key == p->data?
}

//recursive search
Node* BST::rSearch(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }
 
    if (key == p->data){
        return p;
    } else if (key < p->data){
        return rSearch(p->lchild, key);
    } else {
        return rSearch(p->rchild, key);
    }
}

// recursive delete
Node* BST::Delete(Node *p, int key) {
    Node* q;
 
    if (p == nullptr){                                           // if p is null, nothing to delete
        return nullptr;
    }
 
    if (p->lchild == nullptr && p->rchild == nullptr){           // if p has no children, means it is a leaf node
        if (p == root){                                         // if p is root, delete it
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    
    // if key is less than p->data
    if(key < p->data)                                               
    {                                                                                             
        p->lchild = Delete(p->lchild, key);                     // delete leaf node from left subtree 
    }
    else if(key > p->data)
    {                                                           // if key is greater than p->data                                          
        p->rchild = Delete(p->rchild, key);                     // delete leaf node from right subtree
    }
    else
    {                                                
        if (Height(p->lchild) > Height(p->rchild)){             // based on the Height we are going to decide which subtree to delete from
            q = InPre(p->lchild);                               // Find predecessor of p->lchild
            p->data = q->data;                                  // Copy predecessor's data to p
            p->lchild = Delete(p->lchild, q->data);             // Delete predecessor recursively
        } else {
            q = InSucc(p->rchild);                              // Find successor of p->rchild
            p->data = q->data;                                  // Copy successor's data to p
            p->rchild = Delete(p->rchild, q->data);             // Delete successor recursively
        }
    }
    return p;                                                   // Return p
}

/* 
[BST::Height] - Height of tree (Helper function of Delete)
@param p - Node pointer
@return - Height of tree
*/
int BST::Height(Node *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

/*
[BST::InPre] - Inorder predecessor - Rightmost child of left subtree  (Helper function of Delete)
@param p - Node pointer
@return - Inorder predecessor
*/

Node* BST::InPre(Node *p) {
    while (p && p->rchild != nullptr){          //Rightmost child of left subtree 
        p = p->rchild;
    }
    return p;
}

/*
[BST::InPre] - Inorder successor - Leftmost child of right subtree (Helper function of Delete)
@param p - Node pointer
@return - Inorder successor
*/
Node* BST::InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}
 
 
int main() {
 
    BST bst;
 
    // Iterative insert
    bst.iInsert(10);
    bst.iInsert(5);
    bst.iInsert(20);
    bst.iInsert(8);
    bst.iInsert(30);
 
    // Inorder traversal
    bst.Inorder(bst.getRoot());
    std::cout << std::endl;
 
    // Iterative search
    Node* temp = bst.iSearch(2);
    if (temp != nullptr){
        std::cout << temp->data << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
 
    // Recursive search
    temp = bst.rSearch(bst.getRoot(), 20);
    if (temp != nullptr){
        std::cout << temp->data << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
 
    // Recursive insert
    bst.rInsert(bst.getRoot(), 50);
    bst.rInsert(bst.getRoot(), 70);
    bst.rInsert(bst.getRoot(), 1);
    bst.Inorder(bst.getRoot());
    std::cout << "\n" << std::endl;
 
    // Inorder predecessor and inorder successor
    BST bs;
    bs.iInsert(5);
    bs.iInsert(2);
    bs.iInsert(8);
    bs.iInsert(7);
    bs.iInsert(9);
    bs.iInsert(1);
 
    temp = bs.InPre(bs.getRoot());
    std::cout << "InPre: " << temp->data << std::endl;
 
    temp = bs.InSucc(bs.getRoot());
    std::cout << "InSucc: " << temp->data << std::endl;
 
    bs.Inorder(bs.getRoot());
    std::cout << std::endl;
 
    // Delete
    bs.Delete(bs.getRoot(), 7);
    bs.Inorder(bs.getRoot());
    
    return 0;
}