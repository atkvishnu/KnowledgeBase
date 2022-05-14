/**
 *
 * @defgroup   SINGLY_LINKED_LIST singly linked list
 *
 * @brief      This file implements singly linked list.
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief      This class describes a node.
 */
class Node {
public:
	int data;
	Node *next;
};

/**
 * @brief      This class describes operations that are available for the linked list.
 */
class LinkedList {
private:
	Node *first;
public:
	LinkedList(){first = NULL;}
	LinkedList(int A[], int n);		// A : Array with elements | n : No. of elements
	~LinkedList();
	void Display();
	void Insert(int index, int x);
	int Delete(int index);
	int Length();
};

/**
 * @brief      Constructs a new instance.
 *
 * @param      A     Array
 * @param[in]  n     Number of elements in the LL
 */
LinkedList::LinkedList(int A[], int n) {
	Node *last, *t;		// Node ptrs.
	int i = 0;
	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;
	for (int i = 1; i < n; ++i)
	{
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

/**
 * @brief      Destroys the Linked List.
 */
LinkedList::~LinkedList() {
	Node *p = first;
	while(first){
		first = first->next;
		delete p;
		p = first;
	}
}

/**
 * @brief      Displays the Linked List.
 */
void LinkedList::Display() {
	Node *p = first;
	while(p) {
		cout << p->data << "->";
		p = p->next;
	}
}


int LinkedList::Length() {
	Node *p = first;
	int len = 0;
	while(p){
		len++;
		p = p->next;
	}
	return len;
}



 
/**
 * @brief      Insert element `x` into Linked List
 *
 * @param[in]  index  The index
 * @param[in]  x      data
 */
void LinkedList::Insert(int index, int x) {
	
	Node *t, *p;
	p = first;
	
	if(index < 0 || index > Length())
		return ;

	t = new Node;
	t->data = x;
	t->next = NULL;

	if(index == 0){
		t->next = first;
		first = t;
	} else {
		for (int i = 0; i < index-1; ++i){
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}
}


int LinkedList::Delete(int index) {
	Node *p, *q = NULL;
	int x = -1;
	if(index < 1 || index > Length())
		return -1;

	if(index==1) {
		p = first;
		first = first->next;
		x = p->data;
		delete p;
	} else {
		p = first;
		for (int i = 0; i < index-1; ++i)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}
	return x;
}

int main() {
	int A[] = {1,2,3,4,5};
	int N = 5;
	LinkedList l(A,5);
	l.Insert(3,10);
	l.Display();
	return 0;
}