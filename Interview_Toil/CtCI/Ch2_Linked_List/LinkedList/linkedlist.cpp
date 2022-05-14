#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};


void printLinkedList(Node *head) {
	while(head){
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "nullptr" << endl;
}


void insert(Node *&head, int data) {	// passing head by address
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}


void deleteLinkedList(Node *&head) {
	Node *nextNode;
	while(head){
		nextNode = head->next;
		delete(head);
		head = nextNode;
	}
}

// 2.3
// void deleteParticularNode(Node *node) {
// 	if (node == nullptr || node->next == nullptr) {
// 		return;
// 	}
// 	Node *nextNode = node->next;
// 	node->next = nextNode->data;
// 	node->next = nextNode->next;
// 	delete nextNode;
// }


int length(Node *head) {
	int len = 0;
	while(head) {
		len++;
		head = head->next;
	}
	return len;
}


void swap(node *n1, node *n2) {
	int temp;
	if(n1 == nullptr || n2 == nullptr)
		return;
	temp = n1->val;
	n1->val = n2->val;
	n2->val = temp;
}




int main() {
	Node *head = nullptr;
	for(int i = 0; i < 10; i++) {
		insert(head, i*2);
	}
	printLinkedList(head);
}