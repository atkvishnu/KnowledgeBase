// Queue is a container which follows FIFO order (First In First Out) . Here elements are inserted at one end (rear ) and extracted from another end(front) .


// Declaration:
// queue <int> q;


// Some member function of Queues are:
// push(): inserts an element in queue at one end(rear ). Its time complexity is O(1).
// pop(): deletes an element from another end if queue(front). Its time complexity is O(1).
// front(): access the element on the front end of queue. Its time complexity is O(1).
// empty(): checks if the queue is empty or not. Its time complexity is O(1).
// size(): returns the size of queue. Its time complexity is O(1).

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	char qu[4] = {'a', 'b', 'c', 'd'};

	queue<char> q;

	int N = 3;

	char ch;

	

	for(int i = 0; i < 4; ++i)
		q.push(qu[i]);

	for(int i = 0; i < N; ++i){
		ch = q.front();
		q.push(ch);
		q.pop();
	}

	while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
	}

    return 0;
}













