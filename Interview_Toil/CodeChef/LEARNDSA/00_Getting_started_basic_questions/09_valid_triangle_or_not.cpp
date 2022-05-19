// KIM THE FORMULA
// https://cdncontribute.geeksforgeeks.org/wp-content/uploads/check-whether-triangle-valid-not-sides-given1.jpg
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b>c && b+c>a && a+c>b){		// condition for a valid triangle ** REMEMBER 
		cout << "YES";
	} else {
		cout << "NO";
	}
    return 0;
}


