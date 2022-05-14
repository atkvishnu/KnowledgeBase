#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <cassert>
#include <iostream>

using namespace std;

template <class T>
struct Node {
	T data;
	Node<T> *next;
};


template <class T>
class Stack {

private:
	Node<T> *stackTop;
	int size;

public:
	// default constructor
	// Stack() {
	// 	stackTop = nullptr;
	// 	size = 0;
	// }
	Stack(): stackTop{nullptr}, size{0} {}

	~Stack() {}

	void display() {
		Node<T> *curr = stackTop;
		cout << "Top : ";
		while(curr != nullptr) {
			cout << curr->data << " ";
			curr = curr->next; 
		}
		cout << endl;
		cout << "Size of stack: " << size << endl;
	}

	
	bool isStackEmpty() { return (stackTop == nullptr); }

	T top() {
		if(stackTop == nullptr) {
			cout << "Stack Underflow!\n";
		}
		return stackTop->data;
	}

	void push(T val) {
		Node<T> *newNode = new Node<T>;
		newNode->data = val;
		newNode->next = stackTop;
		stackTop = newNode;
		size++;
	}

	

	void pop() {
		Node<T> *temp;
		if(!isStackEmpty()) {
			temp = stackTop;
			stackTop = stackTop->next;
			delete temp;
			size--;
		} else {
			cout << "Stack is empty!\n"; 
 		}
	}

	void clear() { stackTop == nullptr; }

};

#endif	// DATA_STRUCTURES_STACK_H