#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
};

Node *top;

void push(int x) {
	Node *temp = new Node;
	temp->data = x;
	temp->next = top;
	top = temp;
}

void pop() {
	if(top == nullptr) {
		cout << "Stack Underflow\n";
	} else {
		Node *temp = top;
		cout << "\n" << temp->data << " deleted!\n";
		top = top->next;
		delete temp;
	}
}

void peek() {
	Node *temp = top;
	while(temp!=nullptr) {
		cout << temp->data << "\n";
		temp = temp->next;
	}
}



int main() {
	int ch = 0, x = 0;
	do {
		std::cout << "\n0. Exit or Ctrl+C";
        std::cout << "\n1. Push";
        std::cout << "\n2. Pop";
        std::cout << "\n3. Print";
        std::cout << "\nEnter Your Choice: ";
        std::cin >> ch;
        switch(ch) {
        	case 0:
        		break;
        	case 1:
        		cout << "\nInsert: ";
        		cin >> x;
        		push(x);
        		break;
        	case 2:
        		pop();
        		break;
        	case 3:
        		peek();
        		break;
        	default:
        		cout << "Invalid option!\n";
        		break;
        }
	} while (ch!=0);
}



