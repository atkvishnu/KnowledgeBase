#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int d) {
		data = d;
		next = nullptr;
	}
};


void printList(Node *head) {
	while(head) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "null" << endl;
}


void deleteNode(Node *node) {
	if(node==nullptr || node->next==nullptr) {
		return;
	}
	Node *nextNode  = node->next;
	cout << "node->next: " << node->next << endl;
	cout << "nextNode->data: " << nextNode->data << endl;

	node->data = nextNode->data;
	cout << "nextNode->data: " << nextNode->data << endl;
	cout << "node->next: " << node->data << endl;

	node->next = nextNode->next;
	cout <<  "nextNode->next->data: " << nextNode->next->data << endl;
	cout << "node->next->data: " << node->next->data << endl;

	delete nextNode ;		// 1 - 2 - nextNode - 3 - 4 - 5
							//     ^
}





int main() {
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	cout << "List: \n";
	printList(head);



    deleteNode(head->next->next);
    printList(head);


	return 0;
}