// SOLVE MORE PATTERN GENERATION PROBLEMS
// GET TO KNOW HOW FORMULAS ARE MADE FOR CERTAIN PATTERNS

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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(j<n-1-i){
    			cout << " ";
    		} else {
    			cout << "*";
    		}
    	}
    	cout << "\n";
    }
    return 0;
}