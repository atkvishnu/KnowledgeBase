// You're given a number N. 
// If N is divisible by 5 or 11 but not both then print "ONE"(without quotes). 
// If N is divisible by both 5 and 11 then print "BOTH"(without quotes). 
// If N is not divisible by 5 or 11 then print "NONE"(without quotes).


#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    int n;
    cin >> n;
    if(n%5==0 && n%11==0) {
    	cout << "BOTH";
    } else if (n%5==0 || n%11==0) {
    	cout << "ONE";
    } else if (n%5!=0 && n%11!=0) {
    	cout << "NONE";
    }
    return 0;
}