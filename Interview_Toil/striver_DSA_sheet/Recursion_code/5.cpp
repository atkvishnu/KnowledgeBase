/* 
 * Print linearly from N to 1 (But by Backtracking)
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
using namespace std;

void f(int i, int n) {
	if(i>n)
		return;
	f(i+1, n);		// head recursion - BACKTRACKING
	cout << i << " ";
}

int main() {
	int n;
	cin >> n;
	f(1,n);
	return 0;
}