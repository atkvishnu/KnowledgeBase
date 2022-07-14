// A priority queue is a container that provides constant time extraction of the largest element, at the expense of logarithmic insertion. It is similar to the heap in which we can add element at any time but only the maximum element can be retrieved. In a priority queue, an element with high priority is served before an element with low priority.

// Declaration:
// priority_queue<int> pq;

// Some member functions of priority queues are:
// empty(): Returns true if the priority queue is empty and false if the priority queue has at least one element. Its time complexity is O(1).
// pop(): Removes the largest element from the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
// push(): Inserts a new element in the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
// size(): Returns the number of element in the priority queue. Its time complexity is O(1).
// top(): Returns a reference to the largest element in the priority queue. Its time complexity is O(1).


#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> pq;
	pq.push(10);
	pq.push(20);
	pq.push(5);


	while(!pq.empty())
	{
		cout << "Size of pq is: " << pq.size() << endl;
		cout << "Ele @ top: " << pq.top() << endl;
		pq.pop();
	}

	return 0;
}