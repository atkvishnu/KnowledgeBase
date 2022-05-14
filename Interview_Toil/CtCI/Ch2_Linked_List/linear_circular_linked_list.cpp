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
	Node *head;
public:
	LinkedList(){head = NULL;}
	LinkedList(int A[], int n);		// A : Array with elements | n : No. of elements
	~LinkedList();
	void Display();
	void RDisplay(Node *head);
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
	head = new Node;
	head->data = A[0];
	head->next = head;
	last = head;
	for (int i = 1; i < n; ++i)
	{
		t = new Node;
		t->data = A[i];
		// t->next = NULL;
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

/**
 * @brief      Destroys the Linked List.
 */
LinkedList::~LinkedList() {
	Node *p = head;
	while(head){
		head = head->next;
		delete p;
		p = head;
	}
}

/**
 * @brief      Displays the Linked List.
 */
void LinkedList::Display() {
	Node *p = head;
	do {
		cout << p->data << " ";
		p = p->next;
	} while(p!=head);
	cout << endl;
}

void LinkedList::RDisplay(Node *h){
	static int flag = 0;
	Node *head;
	if(h!=head || flag==0){
		flag = 1;
		cout << h->data << " ";
		RDisplay(h->next);
	}
	flag = 0;
}


int LinkedList::Length() {
	Node *p = head->next;
	int len = 0;
	while(p != head) {
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
	p = head;
	
	if(index < 0 || index > Length())
		return ;

	if(index == 0){
		// t->next = head;
		// head = t;
		t = new Node;
		t->data = x;
		if(head == NULL){
			head = t;
			head->next = head;
		} else {
			while(p->next != head){
				p = p->next;
			}
			p->next = t;
			t->next = head;
			head= t;
		}
	} else {
		for (int i = 0; i < index-1; ++i){
			p = p->next;
		}
		t = new Node;
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}


int LinkedList::Delete(int index) {
	Node *q, *p = head;
	int x = -1;
	if(index < 0 || index > Length())
		return -1;

	if(index==1) {
		while(p->next != head){
			p = p->next;
		}
		x = head->data;
		if(head==p){
			delete head;
			head = NULL;
		} else {
			p->next = head->next;
			delete head;
			head = p->next;
		}
	} else {
		for (int i = 0; i < index-2; ++i)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		x = q->data;
		delete q;
	}
	return x;
}

int main() {
	int A[] = {1,2,3,4,5};
	int N = 5;
	Node *head;
	LinkedList l(A,N);
	l.Insert(3,10);		// index, x
	l.Display();
	l.Delete(4);
	l.Display();
	return 0;
}