// REVISIT!!!!!

// You're given a number N. Print the first N lines of the below-given pattern.

// 1 2 3 4 5
// 10 9 8 7 6
// 11 12 13 14 15
// 20 19 18 17 16
// 21 22 23 24 25
// 30 29 28 27 26

// Input:
// First-line will contain the number N.
// Output:
// Print the first N lines of the given pattern.

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

void printVectorINT(vector<int> VECTOR){
	vector<int>::iterator it;
	for(it = VECTOR.begin(); it!=VECTOR.end(); ++it){
		cout << *it << " ";
	}
}
 
int32_t main() {
    int n, i, j;
    cin >> n;
    for(i = 1; i <= n; i++){
    	if(i%2!=0){
    		for(j = (i*5)-4; j<i*5+1; j++){
    			cout << j << " ";
    		}
    	} else {
    		for(j = 5*i; j>(5*i)-5; j--){
    			cout << j << " ";
    		}
    	}
    	cout << "\n";
    }
    return 0;
}