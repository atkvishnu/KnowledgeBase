// https://www.codechef.com/LRNDSA01
// REVISIT... d ?? n?? ans ??

// Given an Integer N, write a program to reverse it.

// Input
// The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

// Output
// For each test case, display the reverse of the given number N, in a new line.

#include <bits/stdc++.h>

#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;

typedef long long ll;
typedef long double ld;

// void printVectorINT(vector<int> VECTOR){
// 	 vector<int>::iterator it;
// 	 for(it = VECTOR.begin(); it!=VECTOR.end(); ++it){
//		 cout << *it << " ";
//	 }
// }

// prints vector using <<. (Example: cout << v << endl;)
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
	// printing all the elems using <<
	for(auto element: vector) {
		os << element << " ";
	}
	return os;
}
 
int32_t main() {
	int t;
	cin >> t;
	while(t--){
		int n, d;
		cin >> n;
		int ans = 0;
		while(n){
			d = n%10;
			n = n/10;

			ans = ans*10+d;
		}
		cout << ans << endl;
		ans = 0;
	}
    return 0;
}