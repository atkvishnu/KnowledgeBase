// https://www.codechef.com/APRIL221D/problems/MANIPULATE

#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif

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

const ll MOD = 1e9+7;       // 1000000007
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

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

//-----------------------------------------


template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){      // print vector
    for(auto element: vector){ os << element << " ";}
    return os;
}

//-----------------------------------------


int solve() {
    int x, y;
    cin >> x >> y;
    if(x >= y) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
 
int32_t main() {
    fast();
    // testcases {
    //     solve();
    // }
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}