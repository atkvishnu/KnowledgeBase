#include<iostream>
#include "QueueCpp.h"
using namespace std;

// class Tree           // In this class implementation we are keeping the root as PUBLIC
// {
// public:
//     Node *root;
//     Tree(){root=NULL;}
//     void CreateTree();
//     void Preorder(Node *p);
//     void Inorder(Node *p);
//     void Postorder(Node *p);
//     void Levelorder(Node *root);
//     int Height(Node *root);
// };

// if root is made private then we will have to overload all the functions to pass root as a parameter and use root in the function
// overloaded tree class using which we can make the pointer root as private
class Tree                  // In this class implementation we are keeping the root as PRIVATE
{
private:
    Node *root;
public:
    Tree(){root=NULL;}
    void CreateTree();
    void Preorder(){Preorder(root);} 
    void Preorder(Node *p);
    void Inorder(){Inorder(root);}
    void Inorder(Node *p);
    void Postorder(){Postorder(root);}
    void Postorder(Node *p);
    void Levelorder(){Levelorder(root);}
    void Levelorder(Node *root);
    int Height(){return Height(root);}      // overloaded function. Now we can directly call these functions without passing parameters
    int Height(Node *root);
};


void Tree::CreateTree() {
    Node *p, *t;
    int x;
    Queue q(100);
 
    cout << "Enter root data: " << flush;
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.dequeue();
 
        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}


void Tree::Levelorder(Node *root) {
    Queue q(100);
    cout << root->data << ", " << flush;
    q.enqueue(root);
 
    while (!q.isEmpty()){
        root = q.dequeue();
        if (root->lchild){
            cout << root->lchild->data << ", " << flush;
            q.enqueue(root->lchild);
        }
        if (root->rchild){
            cout << root->rchild->data << ", " << flush;
            q.enqueue(root->rchild);
        }
    }
}
int Tree::Height(Node *root) {
    int l = 0;
    int r = 0;
    if (root == nullptr){
        return 0;
    }
    l = Height(root->lchild);
    r = Height(root->rchild);
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

// int main()
// {
//     Tree t;
//     t.CreateTree();
//     cout << "Preorder: " << endl;
//     t.Preorder(t.root);                     // root is a member of class Tree that's why we have kept is as public
//     cout << endl;
//     cout << "Inorder: " << endl;
//     t.Inorder(t.root);
//     cout << endl;
//     cout << "Postorder: " << endl;
//     t.Postorder(t.root);
//     cout << endl;
//     cout << "Levelorder: " << endl;
//     t.Levelorder(t.root);
//     cout << endl;
//     cout << "Height: " << t.Height(t.root) << endl;
//     return 0;
// }


int main()
{
    Tree t;
    t.CreateTree();
    cout << "Preorder: " << endl;   // root is now private
    t.Preorder();                   // so we don't have to pass root as a parameter                     
    cout << endl;
    cout << "Inorder: " << endl;
    t.Inorder();
    cout << endl;
    cout << "Postorder: " << endl;
    t.Postorder();
    cout << endl;
    cout << "Levelorder: " << endl;
    t.Levelorder();
    cout << endl;
    cout << "Height: " << t.Height() << endl;
    return 0;
}

