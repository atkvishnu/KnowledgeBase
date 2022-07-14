/* 
 * Print linearly from 1 to n (But by Backtracking)
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
using namespace std;

void f(int i, int n) {
	if(i<1)
		return;
	f(i-1, n);		// head recursion - BACKTRACKING
	cout << i << " ";
}

int main() {
	int n;
	cin >> n;
	f(n,n);
	return 0;
}