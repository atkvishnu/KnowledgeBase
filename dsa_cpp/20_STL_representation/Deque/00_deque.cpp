// Deque -> Double Ended Queues -> Sequence Container

// feature of expansion and contraction on both ends.

// They are similar to vectors, but are more efficient in case of insertion and deletion of elements.

// Unlike vectors, contiguous storage allocation may not be guaranteed. 

// Double Ended Queues are basically an implementation of the data structure double-ended queue.

// A queue data structure allows insertion only at the end and deletion from the front.

// Elements are removed from the front and added at the back.

// Double-ended queues are a special case of queues where insertion and deletion operations are possible at both the ends.

// The functions for deque are same as vector, with an addition of push and pop operations for both front and back.

//----------------------------------------------------------

// ITERATORS

// begin() - used to return an iterator pointing to the first element of the deque container.
// end() - used to return an iterator pointing to the last element of the deque container.

// rbegin() - Returns a reverse iterator which points to the last element of the deque (i.e., its reverse beginning).
// rend() - Returns a reverse iterator which points to the position before the beginning of the deque (which is considered its reverse end).

// cbegin() - Returns a constant iterator pointing to the first element of the container, that is, the iterator CANNOT be used to modify, only traverse the deque.

//----------------------------------------------------------

// insert() - Inserts an element. And returns an iterator that points to the first of the newly inserted elements.

// max_size() - Returns the maximum number of elements that a deque container can hold.

// assign() - Assign values to the same or different deque container.

// resize() - Function which changes the size of the deque.


// push_front() - It is used to push elements into a deque from the front.
// push_back() - This function is used to push elements into a deque from the back.

// emplace_front() - used to insert a new element into the deque container. The new element is added to the beginning of the deque.
// emplace_back() - used to insert a new element into the deque container. The new element is added to the end of the deque.


// pop_front() - used to pop or remove elements from a deque from the front.
// pop_back() - used to pop or remove elements from a deque from the back.


// front() - used to reference the first element of the deque container.
// back() - used to reference the last element of the deque container.

// clear() - used to remove all the elements of the deque container, thus making its size 0.
// erase() - used to remove elements from a container from the specified position or range.

// empty() - used to check if the deque container is empty or not.
// size() - used to return the size of the deque container or the number of elements in the deque container.


// operator = -> = operator is used to assign new contents to the container by replacing the existing contents.
// operator [] -> [] operator is used to reference the element present at position given inside the operator.

// at() - used reference the element present at the position given as the parameter to the function.
// swap() - used to swap the contents of one deque with another deque of same type and size.

// find() - Finds the element in the given range of numbers. Returns an iterator to the first element in the range [first,last] that compares equal to val. If no such element is found, the function returns last.


//----------------------------------------------------------


#include <deque>
#include <iostream>
 
using namespace std;

void printDeque(deque<int> DEQUE){
	deque<int>::iterator it;
	for(it = DEQUE.begin(); it != DEQUE.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}


int main()
{
	deque<int> deq1;
	deque<int> deq2 = {1,2,3,4};
	deq1.push_back(10);
	deq1.push_back(20);
	deq1.push_back(30);
	deq1.push_front(100);

	cout << "The deque deq1 is: \n";
	printDeque(deq1);
	printDeque(deq2);


	cout << "deq1.size(): " << deq1.size();
	cout << "\ndeq1.max_size(): " << deq1.max_size();

	cout << "\ndeq1.at(2): " << deq1.at(2);

	// front()
	cout << "\ndeq1.front(): " << deq1.front();
	// back()
	cout << "\ndeq1.back(): " << deq1.back();

	cout << "\ndeq1.pop_back(): ";
	deq1.pop_back();
	printDeque(deq1);

	cout << "\ndeq2.pop_front(): ";
	deq2.pop_front();
	printDeque(deq2);

	// empty()
	if(deq1.empty())
		cout << "True";
	else
		cout << "False";

	// size()
	cout << "\nSize: " << deq1.size();

	// clear()
	deque<int> deq3 = {2,4,6,8,10,12};
	deq3.clear();
	printDeque(deq3);

	// erase(position)
	// erase(startingPosition, endingPosition)
	deque<int> deq4 = {2,4,6,8,10,12};
	deque<int>::iterator it;
	it = deq4.begin();
	deq4.erase(it);
	printDeque(deq4);

	deque<int> mydeque{ 1, 2, 3, 4, 5 };
    deque<int>::iterator it1, it2;
 
    it1 = mydeque.begin();
    it2 = mydeque.end();
    it2--;
    it2--;
 
    mydeque.erase(it1, it2);
    printDeque(mydeque);


    // Question: Given a list of integers, remove all the even elements from the deque and print the deque. 
    deque<int> mydeque1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    deque<int>::iterator i;
    i = mydeque1.begin();
    while (i != mydeque1.end()) {
        if (*i % 2 == 0)     
			 /* Not a good idea to erase inside loop, if you delete last element, mydeque1.end() cannot be found resulting in infinite loop */
            mydeque1.erase(i);
        	i++;       
    }
    printDeque(mydeque1);

	return 0;
}


