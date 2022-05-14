// https://www.codechef.com/LRNDSA02/problems/STFOOD
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
    	int n;
    	cin >> n;
		int maximum = 0;
    	while(n--){
    		int s, p, v;
    		cin >> s >> p >> v;
		    assert(s>=1 && s<=10000);
    		assert(p>=1 && p<=10000);
    		assert(v>=1 && v<=10000);
    		int profit = (p/(s+1))*v;
    		if(profit>maximum) 
    			maximum = profit;
    	}
    	cout << maximum << endl;
    }
    
    return 0;
}