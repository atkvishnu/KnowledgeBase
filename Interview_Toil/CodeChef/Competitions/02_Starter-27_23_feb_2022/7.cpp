// https://www.codechef.com/START27D/problems/STR_REVERSE
// 7. String Reverse

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
    ll t;
    cin >> t;
    while(t--){
    	string str;
    	cin >> str;
    	string ts = str;
    	int n = str.length();
    	int cnt = 0;
    	for(int i = n-1, j = 0; i>=0 && j<n;){
    		if(str[j]!=str[i]){
    			cnt++;
    			j++;
    		} else {
    			i--;
    			j++;
    		}
    	}
    	cout << cnt << endl;
    }
    return 0;
}