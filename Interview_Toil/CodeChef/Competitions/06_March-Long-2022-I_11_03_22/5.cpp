// https://www.codechef.com/MARCH221C/problems/SUBSTRING

#include <bits/stdc++.h>
using namespace std;

//-----------------------------------------

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcases int t;cin>>t; while(t--)

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
const ll mod = 998244353;

ld PI = 3.1415926535897;

const ll N = 1000010;

ll ceils(ll x, ll y) {
    return x / y + ((x % y) != 0);
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

//-----------------------------------------


template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
	for(auto element: vector) {
		os << element << " ";
	}
	return os;
}


//-----------------------------------------

void solve(string s) {
	ll n = s.length();

	ll counter = 0, ans = 0;
	for(int i = 1; i < n-1; i++) {
		if(s[i]!=s[0] and s[i]!=s[n-1]) {
			counter++;
		} else {
			counter = 0;
		}
		ans = max(counter,ans);
	}
	if(ans==0) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}

int32_t main() {
	fast();
    testcases{
    	string S;
    	cin >> S;
    	solve(S);
    }
    return 0;
}