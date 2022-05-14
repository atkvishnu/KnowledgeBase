// https://www.codechef.com/LTIME105D/problems/PLPROCESS
// 5. Parallel Processing

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
    ll t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;
		vector<ll> v1;
        ll sum = 0;
        ll x1 = n;      // for passing downwards!

        while(n--){
    		ll i;
    		cin >> i;
    		v1.push_back(i);
            sum += i;
    	}

        ll x = sum;
        ll max = 0;

        vector<pair<ll,ll>> output;

        for(ll i = 0; i < x1; i++){
            max+=v1[i];
            output.push_back({max,x-max});
        }

        sort(output.begin(), output.end(), [&](pair<ll,ll>&a, pair<ll,ll>&b){
            return abs(a.first-a.second) < abs(b.first-b.second);
        });

        if(output[0].first > output[0].second){
            cout << output[0].first << endl;
        } else {
            cout << output[0].second << endl;
        }
    }
    
    return 0;
}