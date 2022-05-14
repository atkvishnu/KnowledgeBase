// Given three distinct integers A, B and C, print the second largest number among them.

// Input:
// The input consists of three lines.
// The first line contains a single integer A.
// The second line contains a single integer B.
// The third line contains a single integer C.

// Output:
// Print the second largest number among A, B and C, in a separate line.

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

void find_second_largest(int a, int b, int c) {
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	cout << v[1];
} 

int32_t main() {
    int a,b,c;
    cin >> a >> b >> c;
    find_second_largest(a,b,c);
    return 0;
}