/**
 * @Question   Palindrome
 *
 * @brief      This file implements 2 6.
 *
 * @author     Atkum
 * @date       2022
 */

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
    for(auto element: vector) {
        os << element << " ";
    }
    return os;
}

void printList( Node * head ) {
  while( head ) {
    cout << (char)head->data << "-->";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

void insert(Node *&head, char x) {
	Node *nextNode = new Node;
	nextNode->data = x;
	nextNode->next = head;
	head = nextNode;
}


void isPalindromeIter1(Node *&head1) {
	
	Node *newNode = new Node;
	newNode = head1;
	int countNodes = 0;
	int mid;

	while(newNode) {
		countNodes++;
		newNode = newNode->next;
	}

	mid = countNodes/2;
	newNode = head1;

	while(newNode->data > mid) {
		newNode = newNode->next;
	}

	vector<int> v1, v2;

	while(newNode) {
		v1.push_back(newNode->data);
		newNode = newNode->next;
	}

	while(head1->data > mid) {
		v2.push_back(head1->data);
		head1 = head1->next;
	}


	cout << v1 << endl;
	cout << v2 << endl;


	// if(v1==v2) {
	// 	return true;
	// } else {
	// 	return false;
	// }


	// return true;
}


// bool isPalindromeIter2(head2) {
	




	
// }



// bool isPalindromeRecur(head) {








// }










int main()
{

  Node * head1 = nullptr;
  insert( head1, 'a' );
  insert( head1, 'b' );
  insert( head1, 'c' );
  insert( head1, 'c' );
  insert( head1, 'b' );
  insert( head1, 'a' );
  cout << "List 1: ";
  printList(head1);

  // if ( isPalindromeIter1(head1) ) {
  //   cout << "List 1 is pallindrome list\n";
  // } else {
  //   cout << "List 1 is not a pallindrome list\n";
  // }
  isPalindromeIter1(head1);
  cout << "List 1: ";
  printList(head1);

  // Node * head2 = nullptr;
  // insert( head2, 'r');
  // insert( head2, 'a');
  // insert( head2, 'd');
  // insert( head2, 'a');
  // insert( head2, 'r');
  // cout << "List 2: ";
  // printList(head2);

  // if ( isPalindromeIter2( head2 ) ) {
  //   cout << "List 2 is pallindrome list\n";
  // } else {
  //   cout << "List 2 is not a pallindrome list\n";
  // }

  // cout << "List 2: ";
  // printList(head2);

  // Node * head = nullptr;
  // insert( head, 'a' );
  // insert( head, 'b' );
  // insert( head, 'c' );
  // insert( head, 'b' );
  // insert( head, 'd' );
  // cout << "List 3: ";
  // printList(head);

  // if ( isPalindromeRecur(head) ) {
  //   cout << "List 3 is pallindrome list\n";
  // } else {
  //   cout << "List 3 is not a pallindrome list\n";
  // }

  // cout << "List 3: ";
  // printList(head);
  return 0;
}