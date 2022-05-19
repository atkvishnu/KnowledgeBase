// BE CAREFUL FROM THE NEXT TIME. formula!
// REVISIT.

// You are given a number N and find the sum of the first N odd and even numbers in a line separated by space. 
// All even and odd numbers should be greater than 0.

// Input:
// First-line will contain the number N.
// Output:
// Print the sum of the first N odd and even numbers in a line separated by space

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

void printVectorINT(vector<int> VECTOR){
	vector<int>::iterator it;
	for(it = VECTOR.begin(); it!=VECTOR.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}
 
int32_t main() {
	long long int n;
    cin >> n;
    
    long long int oddSum = n*n;
    long long int evenSum = n*(n+1);

    cout << oddSum << " " << evenSum;


    return 0;
}


