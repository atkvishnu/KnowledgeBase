/**
 * @defgroup   Queue implementation using Two Stacks!
 *
 * @brief      This file implements queue using two stacks.
 *
 * @author     Atkum
 * @date       2022
 */

#include <cassert>
#include <iostream>
#include <stack>

using namespace std;


namespace queue_using_two_stacks {

	template<typename T>
	class MyQueue {
		private: 
			stack<T> s1, s2;
		public:
			MyQueue() = default;		// Constructor of queue.
			void push(T x);				// Pushes x to the back of queue.
			const T& pop();				// Removes an element from the front of the queue.
			const T& peek() const;		// Return first element, without removing it.
			bool empty() const;			// Returns whether the queue is empty.
	};

	template <typename T>
	void MyQueue<T>::push(T x) {
		while(!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		s2.push(x);
		while(!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}


	template <typename T>
	const T& MyQueue<T>::pop() {
		const T& temp = MyQueue::peek();
		s2.pop();
		return temp;
	}


	template <typename T>
	const T& MyQueue<T>::peek() const {
		if(!empty()) {
			return s2.top();
		}
		cerr << "Queue is empty! \n";
		exit(0);
	}


	template <typename T>
	bool MyQueue<T>::empty() const {
		return s2.empty() && s1.empty();
	}
}				// namespace queue_using_two_stacks

void queue_test() {
    queue_using_two_stacks::MyQueue<int> que;
    cout << "Test #1\n";
    que.push(2);
    que.push(5);
    que.push(0);
    assert(que.peek() == 2);
    assert(que.pop() == 2);
    assert(que.peek() == 5);
    assert(que.pop() == 5);
    assert(que.peek() == 0);
    assert(que.pop() == 0);
    assert(que.empty() == true);
    cout << "PASSED\n";

    cout << "Test #2\n";
    que.push(-1);
    assert(que.empty() == false);
    assert(que.peek() == -1);
    assert(que.pop() == -1);
    std::cout << "PASSED\n";

    queue_using_two_stacks::MyQueue<double> que2;
    cout << "Test #3\n";
    que2.push(2.31223);
    que2.push(3.1415926);
    que2.push(2.92);

    assert(que2.peek() == 2.31223);
    assert(que2.pop() == 2.31223);
    assert(que2.peek() == 3.1415926);
    assert(que2.pop() == 3.1415926);
    assert(que2.peek() == 2.92);
    assert(que2.pop() == 2.92);
    cout << "All the tests have successfully passed!" << endl;

}



int main() {

	// data_structures::queue_using_two_stacks::MyQueue que;

	queue_test();
	return 0;
}