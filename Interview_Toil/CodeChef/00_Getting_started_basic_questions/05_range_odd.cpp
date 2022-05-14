// You're given two numbers L and R. Print all odd numbers between L and R (both inclusive) in a single line separated by space, in ascending (increasing) order.

// Input:
// First-line will contain two numbers L and R.

// Output:
// Print all odd numbers in a single line separated by space, in ascending (increasing) order.


#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    int L, R;
    cin >> L >> R;

    for(int i = L; i <= R; i++){
    	if(i%2!=0) {
    		cout << i << " ";
    	}
    }

    return 0;
}

