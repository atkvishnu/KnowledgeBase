// You're given the three angles a, b, and c respectively. 
// Now check if these three angles can form a valid triangle with an area greater than 0 or not. 
// Print "YES"(without quotes) if it can form a valid triangle with an area greater than 0, otherwise print "NO" (without quotes).

// Input:
// First-line will contain three numbers a, b, and c separated by space.
// Output:
// Print "YES"(without quotes) if these sides can form a valid triangle, otherwise print "NO" (without quotes).

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
    int area = a*b*c;		// ??
    if(a+b+c == 180 && area>0)
    	cout << "YES";
    else
    	cout << "NO";
    return 0;
}














