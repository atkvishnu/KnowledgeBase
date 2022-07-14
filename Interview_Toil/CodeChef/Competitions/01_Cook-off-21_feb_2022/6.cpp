// https://www.codechef.com/COOK138D/problems/PERFPERM

#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <chrono>
#include <complex>

using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front

#define hashmap unordered_map
#define hashset unordered_set

#define lb lower_bound
#define ub upper_bound

#define all(a)(a).begin(), (a).end()
#define rall(a)(a).rbegin(), (a).rend()

#define ff first
#define ss second

#define foi(n) for (ll i = 0; i < n; i++)
#define foj(n) for (ll j = 0; j < n; j++)
#define fok(n) for (ll k = 0; k < n; k++)

#define forr(i, a, b) for (ll i = a; i < b; i++)
#define forrr(i, b, a) for (ll i = b; i >= a; i--)
#define forrrr(i, a, b, k) for (ll i = a; i < b; i = i + k)

#define graph vector < vector < ll >>

#define sz(v) v.size()

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

typedef vector < int > vi;
typedef vector < ll > vll;
typedef vector < ld > vld;
typedef vector < string > vs;
typedef vector < double > vd;
typedef vector < pii > vpii;
// typedef vector<pll> vpll;
// typedef vector<plll> vplll;
typedef vector < set < ll >> vsll;
typedef vector < char > vc;
typedef vector < bool > vb;

typedef pair < ll, pll > plll;

typedef queue < ll > qll;

typedef map < string, int > msi;
typedef map < int, int > mii;
typedef map < ll, ll > mll;
typedef map < ll, vll > mvll;
typedef map < vll, ll > mvlll;
typedef map < char, ll > mcl;
typedef map < pair < ll, ll > , ll > mplll;
typedef map < int, string > mis;

typedef unordered_map < char, ll > umcl;
typedef unordered_map < ll, char > umlc;
typedef unordered_map < ll, ld > umld;

typedef pair < string, int > psi;
typedef pair < string, string > pss;

typedef priority_queue < ll > pq;
typedef priority_queue < pii, vector < pii > , greater < pii > > pqq;
typedef priority_queue < ll, vector < ll > , greater < ll >> prq;

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

//--------------------------------------------------------------------

void solve() {
    ll n, k;
    cin >> n >> k;
    assert(n>=1 && n<=100000);
    assert(k>=1 && k<=n);
    if (n == k) {
        foi(n) {
            cout << i + 1 << " ";
        }
        return;
    }
    vll p(n, 0);
    foi(n) {
        p[i] = i + 1;
    }
    // 1 2 3 4 5 6
    // 1 2 3 4 5 6
    if (n == k + 1) {
        swap(p[0], p[n - 1]);
        foi(n) {
            cout << p[i] << " ";
        }
        return;
    }
    ll i = k;
    while (i < n - 1) {
        swap(p[i], p[i + 1]);
        i += 2;
    }
    if (i == n - 1) {
        swap(p[i], p[i - 1]);
    }
    foi(n) {
        cout << p[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}