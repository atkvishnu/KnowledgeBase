// https://www.codechef.com/MARCH221C/problems/COUNTONES

#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcases int t;cin>>t; while(t--)
#define FOR(i,a,b) for(long i=a;i<b;i++)
#define pb push_back

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

vector<vector<ll>> dp;
vector<vector<ll>> dp1;

int32_t main() {
	fast();
    dp = vector<vector<ll>>(100,vector<ll>(2,0));
    dp1 = vector<vector<ll>>(100,vector<ll>(2,0));
    dp[0][0] = 1;
    dp[0][1] = 0;
    vector<ll> pre_dp(100,0);
    vector<ll> pre_dp1(100,0);
    vector<ll> prefix_pre_dp1(100+2,0);

 //    cout << dp << endl;
 //    cout << endl;
 //    cout << dp1 << endl;

    ll sum_i_dp=1;
    ll sum_i_dp1=0;

    ll ppp = 0;
    pre_dp[0] = 1;



    for(int i = 1; i < 100; i++) {
    	dp[i][1] += dp[i-1][0] + dp[i-1][1];
    	dp[i][0] += dp[i-1][0] + dp[i-1][1];
    	dp1[i][1] += dp[i-1][0] + dp[i-1][1] + dp1[i-1][0] + dp1[i-1][1];
    	dp1[i][0] += dp1[i-1][0] + dp1[i-1][1];
    	sum_i_dp += dp[i][0] + dp[i][1];
    	pre_dp[i] = sum_i_dp;
    	sum_i_dp1 += dp1[i][0] + dp[i][1];
    	pre_dp1[i] = sum_i_dp1;
    	ppp += sum_i_dp1;
    	prefix_pre_dp1[i] = ppp;
    }
    // cout << dp << endl;
    // cout << endl;
    // cout << dp1 << endl;
    testcases{

    	ll n, k;
    	cin >> n >> k;

    	ll current = 1;
    	ll output = 1;
    	ll current_1 = 1;
    	string str;

    	str.pb('1');

    	ll i = 1;

    	while(current < k) {

    		ll total = pre_dp[n-i-1];

    		if(current + total < k) {
    			str.push_back('1');
    			output += current_1 * total;
    			output += pre_dp1[n-i-1];
    			current_1++;
    			output += current_1;
    			current++;
    			current += total;
    			if(n > 3 && i <= n-3) {
    				output += prefix_pre_dp1[n-(i+2)];
    			}
    		} else {
    			str.push_back('0');
    			output += current_1;
    			current++;
    		}
    		i++;
    	}

    	cout << output << endl;

    }
    // cout << dp << endl;
    // cout << endl;
    // cout << dp1 << endl;


    return 0;
}