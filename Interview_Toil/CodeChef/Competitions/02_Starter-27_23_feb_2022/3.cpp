// https://www.codechef.com/START27D/problems/BLACKJACK
// 3. BLACKJACK

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
    while(t--) {
    	int a,b;
    	int BLACKJACK = 21;
    	cin >> a >> b;
    	if(BLACKJACK - a - b <= 10) {
    		cout << BLACKJACK - a - b << endl;
    	} else {
    		cout << "-1" << endl;
    	}
    }
    return 0;
}