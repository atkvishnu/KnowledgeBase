// Stack is a container adaptor which follows the LIFO (Last In First Out) order and the elements are inserted and deleted from one end of the container. 
// The element which is inserted last will be extracted first.

// Stack uses an encapsulated object of either vector or deque (by default) or list (sequential container class) as its underlying container, providing a specific set of member functions to access its elements.

// Declaration:
// 		stack <int> s;

// Some of the member functions of Stack are:
// push(g) : Insert element at the top of stack. Its time complexity is O(1).
// pop() : removes element from top of stack. Its time complexity is O(1).
// top() : access the top element of stack. Its time complexity is O(1).
// empty() : checks if the stack is empty or not. Its time complexity is O(1).
// size() : returns the size of stack. Its time complexity is O(1).



#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> STACK){
	for(int i = 0; i < STACK.size(); i++) {
		cout << STACK.pop() << " ";
	}
}

int main()
{
	stack<int> s;	// declaration of stack

	// inserting 5 elements in stack from 0 to 4
	// push()
	for(int i = 0; i < 5; i++)
		s.push(i);

	// now the stack is {0,1,2,3,4}

	// size of stack s
	// size()
	cout << "Size of stack is: " << s.size() << endl;
	

	// accessing top element from stack, it will be the last inserted element.
	// top()
	cout << "Top element of stack is: " << s.top() << endl;

	// pop()
	for(int i = 0; i < 5; i++)
		s.pop();

	// empty()
	if(s.empty())
		cout << "Stack is empty." << endl;
	else
		cout << "Stack is not empty." << endl;	


	// emplace()
	s.emplace(5);
	printStack(s);


	return 0;
}









