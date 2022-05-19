// ** adding a flag and toggling it helped me! REVISIT! CHECK UNDERLYING FLAG PATTERN

// You are given a list of N integers and a value K. 
// Print 1 if K exists in the given list of N integers, otherwise print −1.

// Input:
// First-line will contain two numbers N and K.
// Next line contains N space-separated numbers.
// Output:
// Print the answer in a new line


#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;


void printVector(vector<int> VECTOR){
	vector<int>::iterator it;
	for(it = VECTOR.begin(); it!=VECTOR.end(); ++it){
		cout << *it << " ";
	}
}
 
int32_t main() {
    int n, k, i;
    int flag = 1;
    cin >> n >> k;
    vector<int> v;
    while(n>0){
    	cin >> i;
    	v.push_back(i);
    	n--;
    }
    // printVector(v);
    for(auto it = v.begin(); it!=v.end(); ++it){
		if(*it==k){
			flag = 0;
		}
	}

	if(flag == 0)
		cout << "1";
	else
		cout << "-1";

    return 0;
}