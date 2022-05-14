// https://www.codechef.com/COOK138D/problems/CREDITS
// 1. Complete the credits

#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
	for(auto element: vector) {
		os << element << " ";
	}
	return os;
}
 
int32_t main() {
	fast();
    int t;
    cin >> t;
    while(t--){
    	int credits;
    	cin >> credits;
    	if(credits < 35) {
    		cout << "Underload" << endl;
    	} else if (credits > 65) {
    		cout << "Overload" << endl;
    	} else {
    		cout << "Normal" << endl;
    	}
    }
    return 0;
}