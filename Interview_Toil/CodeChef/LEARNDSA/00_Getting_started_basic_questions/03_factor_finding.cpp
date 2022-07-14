// Question: You are given a number N and find all the distinct factors of N.

// Input:
// First-line will contain the number N.
// Output:
// In the first line print number of distinct factors of N.
// In the second line print all distinct factors in ascending order separated by space.


#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    vector<int> factors;	// storing factors
    int n, cnt;
    cin >> n;
    int i = n;
    while(i>0){				// this loop finds the factors
    	if(n%i==0){
    		cnt++;
    		factors.push_back(i);
    		i--;
    	}
    	else{
    		i--;
    	}
    }
    cout << cnt;		// first line
    cout << endl;
    sort(factors.begin(), factors.end());
    for(auto j = factors.begin(); j != factors.end(); j++){		// second line
    	cout << *j << " ";
    }
    return 0;
}




















