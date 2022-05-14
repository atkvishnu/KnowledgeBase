#include <iostream>

#include "./stack.h"


using namespace std;

int main() {

	Stack<int> stk;

	cout << "Test construct: \n";

	stk.display();

	cout << "Test isStackEmpty: \n";

	if(stk.isStackEmpty()) { cout << "PASS" << endl; }
	else { cout << "FAIL" << endl; }

	cout << "Test push: \n";
	cout << "After pushing 10 20 30 40 onto stack: \n";
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	stk.display();
	stk.pop();
	stk.pop();
	cout << "After popping 2 times: \n";

	stk.display();




	return 0;
}