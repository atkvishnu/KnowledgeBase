/**
 * @defgroup   3.1
 *
 * @brief      3.1. Three in One
 * 			   Describe how you could use a single array to implement three stacks.
 *
 * @author     Vishnu
 * @date       2022
 */


#include "3.1.h"

using namespace std;

ThreeInOne::ThreeInOne(int stackCapacity) {
	this->stackCapacity = stackCapacity;
	stackArray = new int[numOfStack * stackCapacity]();
	stackCapacityUsed = new int[numOfStack]();
}


ThreeInOne::~ThreeInOne() {
	delete[] stackArray;
	delete[] stackCapacityUsed;
}


void ThreeInOne::push(int stackNum, int value) {
	if(isFull(stackNum)) {
		cout << "Stack " << stackNum << " is empty.\n";
	} else {
		stackCapacityUsed[stackNum]++;
		stackArray[indexOfTop(stackNum)] = value;
	}

}

void ThreeInOne::pop(int stackNum) {
	if(isEmpty(stackNum)) {
		cout << "Stack " << stackNum << " is empty.\n";
	} else {
		int topIndex = indexOfTop(stackNum);
		stackArray[topIndex] = 0;
		stackCapacityUsed[stackNum]--;
	}
}

int ThreeInOne::top(int stackNum) const {
	if(isEmpty(stackNum)) {
		cout << "Stack " << stackNum << " is empty.\n";
		exit(1); 
	} else {
		return stackArray[indexOfTop(stackNum)];
	}
}

bool ThreeInOne::isEmpty(int stackNum) const {
	return (stackCapacityUsed[stackNum] == 0);
}

bool ThreeInOne::isFull(int stackNum) const {
	return (stackCapacityUsed[stackNum] == stackCapacity);
}

int ThreeInOne::indexOfTop(int stackNum) const {
	int startIndex = stackNum * stackCapacity;
	int capacity = stackCapacityUsed[stackNum];
	return (startIndex + capacity - 1);
}

// void ThreeInOne::display(int stackNum) {
// 	for(int i = 0; i < stackNum; i++) {
// 		for (int j = i * stackCapacity; j < stackArray[stackNum * stackCapacity]; ++j)
// 		{
// 			cout << stackArray[j] << " ";
// 		}
// 	}
// 	cout << endl;
// }

int main() {
	ThreeInOne stkthree(3);
	stkthree.push(0, 10);
	stkthree.push(0, 11);
	stkthree.push(0, 12);
	stkthree.push(0, 13);
	stkthree.push(1, 5);
	stkthree.push(1, 6);
	stkthree.push(1, 7);
	stkthree.push(1, 8);
	stkthree.push(2, 1);
	stkthree.push(2, 2);
	stkthree.push(2, 3);
	stkthree.push(2, 4);
	

	// stkthree.display(0);
	// stkthree.display(1);
	// stkthree.display(2);


	// stkthree.indexOfTop(0);
	// stkthree.indexOfTop(1);
	// stkthree.indexOfTop(2);

	stkthree.pop(0);
	stkthree.pop(1);
	stkthree.pop(2);


	stkthree.top(0);
	stkthree.top(1);
	stkthree.top(2);

	stkthree.pop(1);
	stkthree.pop(1);
	stkthree.pop(1);

	stkthree.isEmpty(1);
	stkthree.isFull(1);


}






// 	int numOfStack = 3;
// 	int stackCapacity;
// 	int *stackArray;
// 	int *stackCapacityUsed;

// 	int indexOfTop(int stackNum) const;
// public:

// 	// Create 3 stacks, each stack is of size stackCapacity.
// 	ThreeInOne(int stackCapacity);
// 	virtual ~ThreeInOne();

// 	// Push an element onto stack stackNum, where stackNum is fron 0 to 2.
// 	void push(int stackNum, int value);

// 	// Pop the top element on stack stackNum, where stackNum is fron 0 to 2.
// 	void pop(int stackNum);

// 	// Return topmost element from stack stackNum, where stackNum is fron 0 to 2.
// 	int top(int stackNum) const;

// 	bool isEmpty(int stackNum) const;
// 	bool isFull(int stackNum) const;