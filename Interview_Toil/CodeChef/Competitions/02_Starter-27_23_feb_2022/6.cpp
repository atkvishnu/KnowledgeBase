// https://www.codechef.com/START27D/problems/BINSTRING
// 6. Distinct Binary Strings

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
    	char str[n];
    	cin >> str;
    	int count = 0;
    	for(int i = 0; i < n-1; i++) {
    		if(str[i+1]!=str[i]){
    			count++;
    		}
    	}
    	cout << count+1 << endl;
    }
    return 0;
}