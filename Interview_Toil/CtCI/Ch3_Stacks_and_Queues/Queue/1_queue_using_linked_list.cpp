/**
 * @defgroup   queue using linked list
 *
 * @brief      This file implements queue using linked list.
 *
 * @author     Atkum
 * @date       2022
 */

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

class queue_linked_list {
public:
	Node *front;
	Node *rear;

	queue_linked_list() { front = rear = nullptr; }
	void enqueue(int);
	int dequeue();
	void display();
};

void queue_linked_list::enqueue(int ele) {
	Node *newNode = new Node();
	newNode->data = ele;
	newNode->next = nullptr;

	if(front == nullptr) {
		front = rear = newNode;
	} else {
		rear->next = newNode;
		rear = newNode;
	}
}


int queue_linked_list::dequeue() {
	Node *newNode;
	int ele;
	if(front == nullptr) {
		cout << "Stack is empty! \n";
	} else {
		newNode = front;
		ele = newNode->data;
		if (front == rear) {	// if length of queue ios 1;
			rear = rear->next;
		}
		front = front->next;
		delete (newNode);
	}
	return ele;
}

void queue_linked_list::display() {
	if(front == nullptr) {
		cout << "Stack is empty! \n";
	} else {
		Node *temp;
		temp = front;
		while(temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}


int main() {
	int op, data;
	queue_linked_list ob;
	cout << "1. enqueue(Insertion): \n";
	cout << "2. dequeue(Deletion): \n";
	cout << "3. Display: \n";
	cout << "4. Exit: \n";

	while(1) {
		cout << "Enter choice: \n";
		cin >> op;
		if(op == 1) {
			cout << "Enter data: ";
			cin >> data;
			ob.enqueue(data);
		} else if(op == 2) {
			data = ob.dequeue();
		} else if(op == 3) {
			ob.display();
		} else if(op == 4) {
			exit(0);
		} else {
			cout << "Wrong choice!\n";
		}
	}
	return 0;
}