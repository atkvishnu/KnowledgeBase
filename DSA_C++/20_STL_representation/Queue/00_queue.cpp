// Queue -> Container Adaptor -> FIFO
//  FIFO  --->  | | | | | | | | | | | |  --->

// Elements are inserted at the back (end) and are deleted from the front.

// Queues use an encapsulated object of deque or list (sequential container class) as its underlying container, providing a specific set of member functions to access its elements.

// ---------------------------------------------------------

// queue::empty() - Returns whether the queue is empty.
// queue::size() - Returns the size of the queue.

// swap() - Exchange the contents of two queues but the queues must be of the same type, although sizes may differ.

// emplace() - Insert a new element into the queue container, the new element is added to the end of the queue.

// front() - Returns a reference to the first element of the queue.
// back() - Returns a reference to the last element of the queue.

// push(g) - Adds the element ‘g’ at the end of the queue.
// pop() - Deletes the first element of the queue.

// ---------------------------------------------------------

#include <iostream>
#include <queue> 
using namespace std;

void printQueue(queue<int> QUEUE){
	while(!QUEUE.empty()){
		cout << QUEUE.front() << " ";
		QUEUE.pop();
	}
	cout << "\n";
}

int main()
{
	queue<int> queue1;
    queue<int> queue2;


	queue1.push(10);
	queue1.push(20);
	queue1.push(30);

    queue1.emplace(40);
    queue1.emplace(50);

    queue2.push(100);
    queue2.push(200);
    queue2.push(300);

    queue2.emplace(400);
    queue2.emplace(500);


	cout << "The queue1 is: ";
	printQueue(queue1);

    // size()
    cout << "\nqueue1.size() : " << queue1.size();
    
    // front()
    cout << "\nqueue1.front() : " << queue1.front();
    // back()
    cout << "\nqueue1.back() : " << queue1.back();
 
 	// pop()
    cout << "\nqueue1.pop() : ";
    queue1.pop();
    printQueue(queue1);

    // push()
    cout << "\nqueue1.push() : ";
    queue1.push(20);
    printQueue(queue1);


    // empty()
    if(queue1.empty())
    	cout << "True";
    else
    	cout << "False";


    // size()
    cout << "\nSize of queue1: " << queue1.size() << endl;


    printQueue(queue1);
    printQueue(queue2);
    queue1.swap(queue2);
    printQueue(queue1);
    printQueue(queue2);



	return 0;
}













