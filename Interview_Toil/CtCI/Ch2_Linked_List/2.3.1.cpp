 /**
 * Cracking the coding interview - edition 6
 * Problem 2.3 Delete middle node:
 * Implement an algorithm to delete a node in the middle of a singly linked list.
 * We are given pointer to that node.
 *
 * Approach:
 * In order to remove a node 'A' from a list, We will need to connect pointer of
 * A's previous node to A's next node. Here we don't have access to previous node.
 * However, we have pointer to that node, we can copy the data of next node to
 * the pointed node and then remove the next node.
 * Assumption here is that we are not given last node of the list for deletion.
 *
 * IMPLEMENTATION:
 * Copy the data from the next node into the node of choice, then delete that node.
 *
 * TIME COMPLEXITY:
 * O(1), as we perform 3 assignments and one deletion.
 *
 * SPACE COMPLEXITY:
 * O(1), as we do not use any space for this algorithm.
 */


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void insert(Node *&head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printLinkedList(Node *head){
    while(head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

void deleteNode(Node *n){
    Node* to_delete = n->next;

    n->data = to_delete->data;
    n->next = to_delete->next;

    delete to_delete;
    
}





int main() {
    Node *head = nullptr;
    for (int i = 0; i < 7; ++i) {
        insert(head, (i*2));
    }
    printLinkedList(head);
    deleteNode(head->next->next);
    deleteNode(head->next->next);
    printLinkedList(head);
}

// head->next->next = 8
// head->next->next->next = 6
