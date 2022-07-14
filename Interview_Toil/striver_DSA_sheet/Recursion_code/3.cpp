/* 
 * Print linearly from N to 1 
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 * 
 */

#include <iostream>
using namespace std;

void f(int i, int n) {
	if(i < 1)
		return;
	cout << i << " ";
	f(i-1, n);
}


int main() {
	int n;
	cin >> n;
	f(n,1);		// OR: f(n,n)
	return 0;
}