/*
 *
 * Print name 3 times (using recursion).
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 * 
 */


#include <iostream>
using namespace std;

void f(int i,int n) {
	if(i > n)
		return;
	cout << "Vishnu" << endl;
	f(i+1, n);		// tail recursion
}

int main() {
	int n;
	cin >> n;
	f(1, n);
	return 0;
}





