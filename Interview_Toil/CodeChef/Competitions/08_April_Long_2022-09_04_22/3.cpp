// https://www.codechef.com/APRIL221D/problems/WATERCOOLER2

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//-----------------------------------------

#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcases int t;cin>>t; while(t--)
#define sz(a) ((int)((a).size()))
#define char unsigned char

typedef long long ll;
typedef long double ld;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_ascending;     // ordered_set (ascending)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multi_ascending;     // ordered_multiset (ascending)
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_descending;     // ordered_set (descending)
// DECLARATION: pbds_ascending A;
// INBUILT FNS: *A.find_by_order(<>), A.order_of_key(<>), *A.lower_bound(<>), *A.upper_bound(<>), A.erase(<>)


const ll MOD = 1e9+7;
const ll mod = 998244353;

ld PI = 3.1415926535897;

const ll N = 1000010;

//-----------------------------------------

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
// printing stuff

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
    testcases {
    	ll x, y, out;
    	cin >> x >> y;
    	out = y/x;
    	if(y%x!=0) cout << out << endl;
    	else cout << out-1 << endl;
    }
    return 0;
}