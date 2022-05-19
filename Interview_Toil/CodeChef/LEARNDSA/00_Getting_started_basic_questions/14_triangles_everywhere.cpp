// You're given the length of three sides a, b, and c respectively. 
// Now If these three sides can form an Equilateral Triangle then print 1, if these three sides can form an Isosceles Triangle then print 2, if these three sides can form a Scalene Triangle then print 3, otherwise print −1.

// Input:
// First-line will contain three numbers a, b, and c separated by space.
// Output:
// Print the answer in a new line.



#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

// void printVectorINT(vector<int> VECTOR){
// 	vector<int>::iterator it;
// 	for(it = VECTOR.begin(); it!=VECTOR.end(); ++it){
// 		cout << *it << " ";
// 	}
// }
 
int32_t main() {
	int a,b,c;
	cin >> a >> b >> c;
	if((a+b>c && b+c>a && a+c>b)&&(a == b && b == c && c == a)){		// equilateral - all sides equal
		cout << "1";
	} else if ((a+b>c && b+c>a && a+c>b)&&(a==b || b==c || c == a)) {	// isosceles - 2 sides equal
		cout << "2";
	} else if ((a+b>c && b+c>a && a+c>b)&&(a!=b && b!=c && c!=a)){		// scalene - no sides equal
		cout << "3";
	} else {
		cout << "-1";
	}  
    return 0;
}




