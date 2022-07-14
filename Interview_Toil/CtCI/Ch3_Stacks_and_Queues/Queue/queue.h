/* This class specifies the basic operation on a queue as a linked list */
#ifndef DATA_STRUCTURES_QUEUE_H_
#define DATA_STRUCTURES_QUEUE_H_

#include <iostream>
#include <cassert>
using namespace std;


template<class T>
struct Node {
	T data;
	Node<T> *next;
};

template<class T>
class Queue {
private:
	Node<T> *queueFront;	/* Pointer to the front of the queue */
	Node<T> *queueRear;		/* Pointer to the rear of the queue */
	int size;
public:
	Queue(): queueFront{nullptr}, queueRear{nullptr}, size{0} {}	/* Default Constructor */
	~Queue() {}		/* Destructor */

	/* Add new item to the queue */
	void enQueue(T item) {
		Node<T> *newNode = new Node<T>;
		newNode->data = item;
		newNode->next = nullptr;
		if(queueFront == nullptr) {
			queueFront = newNode;
			queueRear = newNode;
		} else {
			queueRear->next = newNode;
			queueRear = queueRear->next;
		}
		size++;
	}

	bool isEmptyQueue() { return (queueFront == nullptr); }

	/* Remove the top element of the queue */
	void deQueue() {
		Node<T> *temp;
		if(!isEmptyQueue()) {
			temp = queueFront;
			queueFront = queueFront->next;
			delete temp;
			size--;
		} else {
			cout << "Queue is empty!" << endl;
		}
	}

	/** Returns the first element of the queue */
	T front() {
		if(queueFront == nullptr) {
			cout << "Queue is empty!";
		}
		return queueFront->data;	
	}

	void clear() {
		queueFront = nullptr;
	}


	void display() {
		Node<T> *curr = queueFront;
		cout << "Front --> ";
		while(curr != nullptr) {
			cout << curr->data << " | ";
			curr = curr->next;
		}
		cout << endl;
		cout << "Size of queue: " << size << endl;
	}

};

#endif // DATA_STRUCTURES_QUEUE_H_