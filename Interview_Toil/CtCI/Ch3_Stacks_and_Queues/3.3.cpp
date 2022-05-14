/**
 * @defgroup   3.3 Stack of Plates
 *
 * @brief      Implement a stack of plates. Create a new stack if previous one exceeds the capacity.
 *
 * @author     Vishnu
 * @date       2022
 */


#include <iostream>
#include <stack>
#include <climits>

using namespace std;

#define STACK_NUM 100

class newStack {

private:
	stack<int> *myStack;
	int threshold;
	int curStack;

public:
	newStack() {
		threshold = 10;
		myStack = new stack<int>[STACK_NUM];
		curStack = 0;
	}

	void push(int data) {
		if(myStack[curStack].size() >= threshold) {
			curStack++;
		}
		myStack[curStack].push(data);
	}

	void pop() {
		if(myStack[curStack].empty()) {
			if(curStack == 0) {
				cout << "Current stack is empty,\n";
				return;
			}
			curStack--;
		}
		myStack[curStack].pop();
	}

	int top() {
		if(myStack[curStack].empty()) {
			if(curStack == 0) {
				return INT_MIN;
			}
			curStack--;
		}
		return myStack[curStack].top();
	}

	bool isEmpty() {
		if(curStack == 0) {
			return myStack[curStack].empty();
		} else {
			return false;
		}
	}

	void popAt(int index) {
		if(myStack[index].empty()) {
			cout << index << "th sub-stack is empty.\n";
			return;
		}
		myStack[index].pop();
	}
};



int main() {

	newStack theStack;

	for (int i = 0; i < 100; ++i) {
		theStack.push(i);
	}

	cout << "Pop out one element from 4th stack " << endl;
	theStack.popAt(4);

	cout << "Pop out all element from plates of stack." << endl;

	for (int i = 0; i < 100; ++i) {
		cout << "Pop out the element: " << theStack.top() << endl;
		theStack.pop();
	}

	return 0;
}