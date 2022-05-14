#include <iostream>
using namespace std;

class Stack {
private:
	int top;			/* maintains top index of stack */
	int size;
	int *s;				/* for making new array */
public:
	Stack(int size);
	~Stack();
	void push(int x);
	int pop();
	int peek(int index);
	int stackTop();
	bool isEmpty();
	bool isFull();
	void Display();
};

Stack::Stack(int size) {
	this->size = size;
	top = -1;
	s = new int[size];
}

Stack::~Stack() {
	delete[] s;
}

void Stack::push(int x) {
	if(isFull()) {
		cout << "Stack Overflow!" << endl;
	} else {
		top++;
		s[top] = x;	
	}
}

int Stack::pop() {
	int x = -1;
	if(isEmpty()) {
		cout << "Stack Underflow!" << endl;
	} else {
		x = s[top];
		top--;
	}
	return x;
}

int Stack::peek(int index) {
	int x = -1;
	if(top-index+1<0 || top-index+1==size) {
		cout << "Invalid position. \n";
	} else {
		x = s[top-index+1];
	}
	return x;
}

int Stack::stackTop() {
	if(isEmpty()) return -1;
	
	return s[top];
}


bool Stack::isEmpty(){
	if(top==-1) {
		return 1;
	} else {
		return 0;
	}
}

bool Stack::isFull() {
	if(top==size-1) {
		return 1;
	} else {
		return 0;
	}
}

void Stack::Display() {
	for(int i = top; i >= 0; i--) {
		cout << s[i] << endl;
	}
	cout << endl;
}


int main() {
	int A[] = {1,2,3,4,5};
	int n = sizeof(A)/sizeof(A[0]);
	Stack stk(n);
	for (int i = 0; i < n; ++i) {
		stk.push(A[i]);
	}
	// stk.push(11);
	cout << "Stack: " << endl;
	stk.Display();
	cout << stk.isFull() << endl;
	cout << stk.isEmpty() << endl;
	cout << stk.stackTop() << endl;
	cout << stk.peek(2) << endl;
}