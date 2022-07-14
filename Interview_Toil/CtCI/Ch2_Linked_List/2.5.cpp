/**
 * Cracking the coding interview edition 6
 * Problem 2.5 Sum lists
 * You have two numbers represented by linked list, where each node contains
 * a single digit. Digits are stored in reverse order.(1's digit is at the head)
 * Write a function that adds two such numbers and returns a number in similar
 * list format.
 * example:
 * 7-->1-->6 + 5-->9-->2 = 2-->1-->9
 * which is (617 + 295  = 912)
 * What if digits are not stored in reverse order(i.e 1's digit is at tail)
 * (6--1-->7) + (2-->9-->5) = (9-->1-->2)
 *
 * Approach:
 * We will solve the problem recursively and iteratively.
 * Add numbers at same digits place, store the 1's digit of the output in new list
 * and add carry in next place's addition.
 *
 * Finally, we will solve the follow up.
 */

#include <bits/stdc++.h>
using namespace std;






struct Node {
	int data;
	Node *next;
};

void insert(Node *&head, int x) {
	Node *newNode = new Node;
	newNode->data = x;
	newNode->next = head;
	head = newNode;
}

void printList(Node *head) {
	while(head) {
		cout << head->next << " ";
		head = head->next;
	}
	cout << "null" << endl;
}



Node *addTwoList(Node *list1, Node *list2) {

	if(list1 == nullptr) {
		return list2;
	}
	if(list2 == nullptr) {
		return list1;
	}

	Node *list3 = nullptr;

	int quotient = 0;
	int remainder = 0;

	while()




}






int main() {

	



	
}



