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
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll a[n] = {0};

    if (s[0] == '1')
    {
        a[0] = 1;
    }

    ll prev = a[0];

    for (ll i = 1; i < n; i++)
    {
        if (s[i] == '1')
        {
            prev += (i + 1);
        }
        a[i] = prev;
        a[i] = a[i] % 2;
    }

    ll p = 1;
    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (a[i] == 1)
        {
            ans += p;
            ans = ans % mod;
        }
        p = p * 2;
        p = p % mod;
    }
    cout << ans % mod << "\n";
}

int32_t main() {
    fast();
    testcases {
        solve();
    }
    return 0;
}