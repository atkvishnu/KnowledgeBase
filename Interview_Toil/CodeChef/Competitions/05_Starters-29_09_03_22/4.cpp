// https://www.codechef.com/START29C/problems/DCP

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
	int n, m;
	int mod = 1000000007;
	cin >> n >> m;
	uint64_t a[n+1], output[n+1]={0};

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= m; ++i)
	{
		uint64_t ai, xi;
		cin >> ai >> xi;
		for (uint64_t j = 1; j <= xi; ++j)
		{
			uint64_t w, aj, sum = 0;
			cin >> w >> aj;
			sum = (w*a[ai])%mod;
			a[aj] = (a[aj] + sum)%mod;
		}
		a[ai] = output[ai] = 0;
	}
	for(int i = 1; i <= n; i++) {
		cout << a[i] << endl;
	}
    return 0;
}