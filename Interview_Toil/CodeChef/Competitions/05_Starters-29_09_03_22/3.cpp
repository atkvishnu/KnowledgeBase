// https://www.codechef.com/START29C/problems/PMA


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


int32_t main() {
	fast();
    testcases{
    	ll n, s = 0;
    	cin >> n;
    	vector<long long> arr(n), v1, v2;
    	for(auto &X: arr){
    		cin >> X;
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		if(i & 1) {
    			v1.push_back(abs(arr[i]));
    		} else {
    			v2.push_back(abs(arr[i]));
    		}
    	}
    	sort(v1.begin(), v1.end());
    	sort(v2.begin(), v2.end());

    	if(v1[v1.size()-1] > v2[0]) {
    		swap(v1[v1.size() - 1], v2[0]);
    	}

    	for(auto x: v2) {
    		s += x;
    	}
    	for(auto x: v1) {
    		s -= x;
    	}
    	cout << s << endl;
    }
    return 0;
}