/**
 * @defgroup   3.5 Sort Stack
 *
 * @brief      Write a program to sort a stack such that the smallest items are on the top.
 *			   You can use an additional temporary stack, but you may not copy the elements into any 
 *			   other data structure (such as an array).
 *			   The stack supports the following operations: push, pop, peek, and isEmpty. 
 *			   
 * @brief2     Sort one using an additional temporary stack. min element on top of the sorted stack.
 *
 * @author     Vishnu
 * @date       2022
 */

#include <iostream>
#include <stack>

using namespace std;


void sortStack(stack<int> *st) {
	stack<int> sorted;			// top contains largest element, an additional temporary stack
	while(!(*st).empty()) {
		int temp = (*st).top();
		(*st).pop();
		while(!sorted.empty() && temp<sorted.top()) {
			(*st).push(sorted.top());
			sorted.pop();
		}
		sorted.push(temp);
	}
	while(!sorted.empty()) {
		(*st).push(sorted.top());		// this step reverse the sorted order to original stack
		sorted.pop();
	}
}


int main() {
	stack<int> my_stack;
	int arr[] = {6,4,8,9,10,99,7,1,100};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout << "Elements in the stack: \n";
	for (int i = 0; i < size; ++i) {
		cout << "Push in element - " << arr[i] << endl;
		my_stack.push(arr[i]);
	}

	sortStack(&my_stack);
	cout << "The sorted stack is: \n";
	while(!my_stack.empty()) {
		cout << my_stack.top() << endl;
		my_stack.pop();
	} 





	return 0;
}























