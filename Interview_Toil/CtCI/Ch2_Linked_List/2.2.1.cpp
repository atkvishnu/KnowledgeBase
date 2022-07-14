/**
 * @QName      Return Kth to Last
 * 
 * @ Question   Implement an algorithm to find the k'th to last element of a singly linked list.
 *
 * @ Hints:	   - 8 : What if you knew the LL size? What is the difference between finding the Kth-to-last element and finding the Xth element?
 *             - 25 : If you don't know the LL size, can you compute it? How does it impact the runtime?
 *             - 41 : Try implementing it recursively. If you could find the (K-1)th to last element, can you find the Kth element?
 *             - 67 : You might find it useful to return multiple values. Some language don't directly support this, but there are workarounds in essentially any language. What are some of the workarounds?
 *             - 126 : Can you do it iteratively? Imagine if you had two pointers pointing to adjacent nodes and they were moving at the same speed through the linked list. When one hits the end of the LL, where will be the other one?  
 * @ Approaches:
 *  1. Iterative:
 *       Use two pointers
 *       Move first pointer k places.
 *       Now move second pointer(from start) and first pointer (from k+1) simultanously.
 *       When second pointer would have reached end, first pointer would be at kth node.
 *
 *  2. Recursive:
 *       Maintain an index to keep track of node.
 *       Solve the problem for n-1 nodes and add 1 to index.
 *       Since each parent call is adding 1, when counter reaches k,
 *       we have reached length-k node from start, which is kth node from last.
 */

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *next;
};

void printLinkedList(Node *head) {
    while(head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

void insert(Node *&head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}


Node * kthToLastIterative(Node *head, int k){
    if(head == nullptr) {
        return head;
    }
    Node *ptr1 = head;
    Node *ptr2 = head;

    int i = 0;
    while(i<k && ptr1){
        ptr1 = ptr1->next;
        ++i;
    }

    if(i<k){
        return nullptr;
    }

    while(ptr1 != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr2;
}


/**
 * [kthToLastHelper - helper routine to find nth node for recursive approach
 * @param  head  - head of the list
 * @param  k     - the k value for finding kth element from last of the list.
 * @param  i     - an index maintained to keep track of current node.
 * @return       - kth node from last.
 */
Node * kthToLastHelper( Node * head, int k , int & i) {
  if ( head == nullptr ) {
    return nullptr;
  }

  Node * node = kthToLastHelper(head->next, k, i);
  i = i + 1;
  //if we have solved problem k times from last.
  if ( i == k ) {
    return head;
  }
  return node;
}


/**
 * kthToLastRecursive - Recursive approach for finding kth to last element of list.
 * @param  head  - head of node
 * @param  k     - the k value for finding kth element from last of the list.
 * @return       - kth node from last.
 */
Node * kthToLastRecursive( Node * head, int k ) {
  int i = 0;
  return kthToLastHelper(head, k, i);
}


int main() {
    Node *head = nullptr;
    for (int i = 7; i > 0; i--) {
        insert(head, i);
    }
    printLinkedList(head);

    

  std::cout << "4th node from last (Recursive) : ";
  Node *node4 = kthToLastRecursive(head, 4);
  if ( node4 != nullptr ) {
    std::cout << node4->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }










    std::cout << "4th node from last (Iterative) : ";
    Node *node4 = kthToLastIterative(head, 4);
    if ( node4 != nullptr ) {
        std::cout << node4->data << std::endl;
    } else {
        std::cout << "NULL NODE\n";
    }



}





