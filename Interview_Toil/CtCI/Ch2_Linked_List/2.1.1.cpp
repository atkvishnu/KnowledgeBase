/**
 * @Question Name   Remove Dups using STL
 * 
 * @Question   Write code to remove duplicates from an unsorted linked list.
 *
 * @FOLLOW UP  How would you solve this problem if a temporary buffer is not allowed?
 *             - If temporary buffer is not allowed then it can be solved using 2 pointers. The 1st solution is for this case.
 * 
 * @ Hints:    - #9 - Have you tried a hash table? You should be able to do this in a single pass of the linked list.
 *             - #40 - Without extra space, you'll need O(N^2) time. Try using two pointers, where the second one searches ahead of the head one.
 */

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *next = nullptr;
};



void insert(Node *&head, int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}



void printList(Node *head){
    while(head){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}


static inline int random_range(const int min, const int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}



void removeDuplicate1(Node *&head){
    if(head==nullptr || (head && (head->next == nullptr))){
        return;
    }
    Node *curr = head;
    while(curr){
        Node *runner = curr;
        while(runner->next != nullptr){
            if(runner->next->data == curr->data){
                runner->next = runner->next->next;  // removes the link to a node
            } else {
                runner = runner->next;      // moves pointer ahead
            }
        }
        curr = curr->next;      // moves pointer ahead
    }
}


/**
 * Method 2
 * space complexity - O(n)
 * time complexity - O(n)
 *
 * [removeDuplicates1 - Remove duplicates from the list using hash table]
 * @param head [head of list]
 */
void removeDuplicate2(Node *&head){
    if(head==nullptr || (head && (head->next == nullptr) )){
        return;
    }
    unordered_map<int, int> node_map;
    Node *prev = head;
    Node *curr = head->next;
    node_map[head->data] = 1;

    while( curr != nullptr ) {
        while(curr && node_map.find(curr->data) != node_map.end()) {
            curr = curr->next;
        }
        prev->next = curr;
        prev = curr;
        if(curr){
            node_map[curr->data] = 1;
            curr = curr->next;
        }
    }
}









int main(){
    cout << "Method 1: \n";
    Node *head = nullptr;
    for (int i = 0; i < 10; ++i)
    {
        insert(head, random_range(1,7));
    }
    printList(head);
    removeDuplicate1(head);
    printList(head);

    cout << "Method 2 : \n";
    Node *head1 = nullptr;
    for ( int i = 0; i < 10; ++i ) {
        insert(head1, random_range(1,7));
    }
    printList(head1);
    removeDuplicate2(head1);
    printList(head1);

}