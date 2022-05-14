// *** Lists are sequence containers that *allow non-contiguous memory allocation*.
// *** List is a sequence container which *takes constant time[O(1)]* in *inserting and removing elements*. 
// *** List in STL is implemented as *Doubly Link List*.
// *** Normally, when we say a List, we talk about a doubly linked list.
// *** For implementing a singly linked list, we use a forward list.
// *** The elements from List cannot be directly accessed. For example,
// to access element of a particular position ,you have to iterate from a known position to that particular position.

// *** As compared to vector, the list has slow traversal, but once a position has been found, insertion and deletion are quick.

// declaration
// list <int> LI;
// Here LI can store elements of int type.

// here LI will have 5 int elements of value 100.
// list<int> LI(5, 100)

// Some of the member function of List:

// begin(): It returns an iterator pointing to the first element in list.Its time complexity is O(1).
// end(): It returns an iterator referring to the theoretical element(doesn’t point to an element) which follows the last element.Its time complexity is O(1).
// rbegin(), rend(), cbegin(), cend(), crbegin(), crend()

// empty(): It returns whether the list is empty or not.It returns 1 if the list is empty otherwise returns 0.Its time complexity is O(1).
// assign(): It assigns new elements to the list by replacing its current elements and change its size accordingly.It time complexity is O(N).
// back(): It returns reference to the last element in the list.Its time complexity is O(1).
// erase(): It removes a single element or the range of element from the list.Its time complexity is O(N).
// front(): It returns reference to the first element in the list.Its time complexity is O(1).
// push_back(g): It adds a new element "g" at the end of the list, after its current last element. Its time complexity is O(1).
// push_front(g): It adds a new element "g" at the beginning of the list, before its current first element. Its time complexity is O(1).
// remove(): It removes all the elements from the list, which are equal to given element. Its time complexity is O(N).
// remove_if(): removes all the values from the list if condn. is true
// pop_back(): It removes the last element of the list, thus reducing its size by 1. Its time complexity is O(1).
// pop_front(): It removes the first element of the list, thus reducing its size by 1. Its time complexity is O(1).
// insert(): It insert new elements in the list before the element on the specified position. Its time complexity is O(N).
// reverse(): It reverses the order of elements in the list. Its time complexity is O(N).
// size(): It returns the number of elements in the list. Its time complexity is O(1).
// sort(): sorts the list in increasing order
// list_unique() : removes all duplicate consecutive elems from the list.
// clear(): removes all the elements of the list container, making the size = 0
// swap() : swaps the contents of one list with another list of same type and size.
// list_splice(): used to transfer elements from one list to another
// list_merge() : merges two sorted lists into one
// list_emplace() : extends list by inserting new elements at given position.
// emplace(position, value): inserts an elemnet at the position specified.
// emplace_back(value): adds "value" @ end of list. It's different from push_back() because it directly creates elements at position whereas push_back() first makes a temp. copy and copies from there. emplace_back() is faster in implementation than push_back()
// emplace_front(value): adds "value" @ beginning of list. It is different from push_front() by the fact that it directly creates elements at position whereas push_front() first makes a temporary copy and copies from there. emplace_front() is faster in implementation than push_front()


/*
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list <int> LI;
	list <int>::iterator it;

	// inserts elements @ end of the list
	LI.push_back(4);
	LI.push_back(5);

	// inserts elements @ beginning of the list
	LI.push_front(3);
	LI.push_front(6);
	

	it = LI.begin();

	LI.insert(it, 10);

	cout << "Element of list: ";
	for(it = LI.begin(); it!=LI.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	LI.reverse();

	cout << "Element of list after reversing: ";
	for(it = LI.begin(); it!=LI.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	LI.remove(5);

	cout << "Element of list after deleting 5: ";
	for(it = LI.begin(); it!=LI.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// removes last element from list
	LI.pop_back();
	// removes first element from list
	LI.pop_front();
	cout << "Element of list after pops: ";
	for(it = LI.begin(); it!=LI.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}
*/

#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void printList(list<int> &g){
	list<int>::iterator it;

	for(it = g.begin(); it != g.end(); it++)
		cout << *it << " ";

	cout << "\n";
}


int main()
{
	list<int> gqlist1, gqlist2;

	for(int i = 0; i < 10; i++) {
		gqlist1.push_back(i*2);
		gqlist2.push_back(i*3);
	}
    cout << "\nList 1 (gqlist1) is : ";
    printList(gqlist1);
 
    cout << "\nList 2 (gqlist2) is : ";
    printList(gqlist2);
 
    cout << "\ngqlist1.front() : " << gqlist1.front();
    cout << "\ngqlist1.back() : " << gqlist1.back();
 
    cout << "\ngqlist1.pop_front() : ";
    gqlist1.pop_front();
    printList(gqlist1);
 
    cout << "\ngqlist2.pop_back() : ";
    gqlist2.pop_back();
    printList(gqlist2);
 
    cout << "\ngqlist1.reverse() : ";
    gqlist1.reverse();
    printList(gqlist1);
 
    cout << "\ngqlist2.sort(): ";
    gqlist2.sort();
    printList(gqlist2);

	return 0;
}















