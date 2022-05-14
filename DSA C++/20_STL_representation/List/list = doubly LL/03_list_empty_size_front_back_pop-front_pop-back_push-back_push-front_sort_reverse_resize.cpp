// list = Doubly linked list


// list::empty() -> check if the list container is empty or NOT.

// Syntax: listname.empty()
// Returns: True(if list is empty) / False(otherwise)

#include <iostream>
#include <list>
using namespace std;

void printList(list<int> LIST) {
	for(auto it = LIST.begin(); it != LIST.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
}

/*
int main()
{
	list<int> myList = {};

	if(myList.empty())
		cout << "True";
	else
		cout << "False"; 

	return 0;
}
*/







// Question: Given a list of integers, find the sum of all the integers.

// Input  : 1, 5, 6, 3, 9, 2
// Output : 26

// Algorithm:
// Check if the list is empty, if not add the front element to a variable initialised as 0, and pop the front element.
// Repeat this step until the list is empty.
// Print the final value of the variable.

/*
int main()
{	
	int sum = 0;
	list<int> myList = {1, 5, 6, 3, 9, 2};

	while(!myList.empty()){
		sum += myList.front();
		myList.pop_front();
	}
	cout << sum;
	return 0;
}
*/


//--------------------------------------------------------------

// list::size() -> used to return the size of the list container or the number of elements in the list container.

// Syntax: listname.size();

/*
int main()
{
	list<int> myList = {1,2,3,4,5,6};

	cout << myList.size();

	return 0;
}
*/




// Question: Given a list of integers, find the sum of all the integers.

// Input  : 1, 5, 6, 3, 9, 2
// Output : 26

// Algorithm:
// Check if the size of the list is 0, if not add the front element to a variable initialised as 0, and pop the front element.
// Repeat this step until the list is empty.
// Print the final value of the variable.

/*
int main()
{
	int sum = 0;
	list<int> myList = {1, 5, 6, 3, 9, 2};
	while(!myList.size()==0){
		sum+= myList.front();
		myList.pop_front();
	}
	cout << sum;
	return 0; 
}
*/


//--------------------------------------------------------------

// list::front() -> reference the first element of the list container.
// This fn. can be used to fetch the first element of a list.

// Syntax: listname.front()


//--------------------

// list::back() -> reference the last element of the list container.
// This fn. can be used to fetch the last element of a list.

// Syntax: listname.back()

//--------------------

// list.pop_front() ->  pops/removes front element, container size decreases by 1.

//--------------------

// list.pop_back() -> pops/removes last element, container size decreases by 1.

//--------------------

// list.push_front() -> push element to front of the list, container size ++

//--------------------

// list.push_back() -> push element to back of the list, container size --

//--------------------

// list.reverse() -> reverses a list container. Reverses the order of elements in the list container.

//--------------------

// list.resize(int n, value_type val) -> used to resize a list container. It takes a number n as parameter and resizes the list container to contain exactly "n" elements.

// If the list already has more than n elements, then the function erases the elements from the list except the first n element.
// If the list contains less than n elements, then the function adds the difference number of elements to the list with their default values.
// The function also accepts a parameter val, if this parameter is specified and the number of elements in the list container is less than n then the function adds elements to the list with their value assigned to val.

int main()
{
	list<int> myList = {1,2,10,20,30,150};

	cout << "myList: ";
	printList(myList);

	cout << "Element at front: " << myList.front() << endl;
	cout << "Element at back: " << myList.back() << endl;

	myList.pop_front();
	myList.pop_back();

	cout << "After popping front and back elems (using .pop_front() & .pop_back()): ";
	printList(myList);

	myList.push_front(1);
	myList.push_back(1);

	cout << "After adding the elements again (using .push_back() & .push_front()): ";
	printList(myList);

	// sort the list (.sort())
	myList.sort();
	cout << "Sorted list: ";
	printList(myList);


	// reverse the list (.reverse())
	myList.reverse();
	cout << "Reversed list: ";
	printList(myList);


	// resize the list (.resize(n))
	myList.resize(3);
	cout << "Resized list to 3 elems: ";
	printList(myList);


	// resize the list (.resize(n,val))
	myList.resize(30,-1);
	cout << "Resized list to 30 elems with -1 placeholder: ";
	printList(myList);

	return 0;
}















