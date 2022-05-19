// Raju is planning to visit his favourite restaurant. 
// He shall travel to it by bus. 
// Only the buses whose numbers are divisible by 5 or by 6 shall take him to his destination. 
// You are given a bus number N. 
// Find if Raju can take the bus or not. 
// Print YES if he can take the bus, otherwise print NO.

// Input:
// The first and only line of the input shall contain an integer N, denoting the bus number.

// Output:
// Print YES if Raju can take that bus, else print NO.

#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    int n;
    cin >> n;
    if(n%5 == 0 || n%6 == 0) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
    
    return 0;
}