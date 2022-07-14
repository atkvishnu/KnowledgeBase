#include <iostream>
#include <cstdlib>

class ThreeInOne {
private:
	int numOfStack = 3;
	int stackCapacity;
	int *stackArray;
	int *stackCapacityUsed;

	int indexOfTop(int stackNum) const;
public:

	// Create 3 stacks, each stack is of size stackCapacity.
	ThreeInOne(int stackCapacity);
	virtual ~ThreeInOne();

	// Push an element onto stack stackNum, where stackNum is fron 0 to 2.
	void push(int stackNum, int value);

	// Pop the top element on stack stackNum, where stackNum is fron 0 to 2.
	void pop(int stackNum);

	// Return topmost element from stack stackNum, where stackNum is fron 0 to 2.
	int top(int stackNum) const;

	bool isEmpty(int stackNum) const;
	bool isFull(int stackNum) const;

	void display(int stackNum);
};