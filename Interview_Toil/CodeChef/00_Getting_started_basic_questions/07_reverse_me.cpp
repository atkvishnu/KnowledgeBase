// You are given a list of N integers and you need to reverse it 
// and print the reversed list in a new line.

// Input:
// First-line will contain the number N.
// Second line will contain N space-separated integers.
// Output:
// Print the reversed list in a single line

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

void printVector(vector<int> VECTOR){
	vector<int>::iterator it;
	for(it = VECTOR.begin(); it!=VECTOR.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

int32_t main() {
    int n, i;
    cin >> n;
    vector<int> v;
    while(n>0) {
    	cin >> i;
    	v.push_back(i);
    	n--;
    }    
    // printVector(v);
    reverse(v.begin(), v.end());
    // for(int i = 0; i < v.size(); i++){
    	
    // }
    printVector(v);
    return 0;
}