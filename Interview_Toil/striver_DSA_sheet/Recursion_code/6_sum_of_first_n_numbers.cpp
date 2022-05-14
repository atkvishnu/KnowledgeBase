#include <iostream>
using namespace std;


/*
 * Parametrized Recursion
 */

/*
void f(int i, int sum) {
	if(i<1) {
		cout << sum << endl;
		return;
	}
	f(i-1, sum+i);
}

int main() {
	int n;
	cin >> n;

	f(n, 0);

	return 0;
}
*/


/*
 * Functional Recursion
 */

int f(int n) {
	if(n==0)
		return 0;
	return n + f(n-1);
}

int main() {
	int n;
	cin >> n;

	cout << f(n);
	return 0;
}