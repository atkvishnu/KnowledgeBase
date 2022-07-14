// https://www.codechef.com/MARCH221C/problems/MAXMEXPATH


#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define ordered_set tree<ll, ll, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define element(x) find_by_order(x)

ordered_set ost;
int n;
vector<int> adjc[100005];
int aval[100005];

int dfs(int node, int pa) {
	ost[aval[node]] += 1;
	int maxi = 0;

	int l = 0;
	int r = ost.size()-1;
	int mid;

	while(l<=r) {
		mid = (l+r)/2;
		auto ele=*ost.find_by_order(mid);
		if(ele.first<=mid) {
			maxi = max(mid+1,maxi);
			l = mid+1;
		} else {
			r = mid -1;
		}
	}
	for(auto u:adjc[node]) {
		if(u!=pa) {
			maxi = max(maxi, dfs(u,node));
		}
	}
	ost[aval[node]]--;
	if(ost[aval[node]]==0) {
		ost.erase(ost.find(aval[node]));
	}
	return maxi;
}

int32_t main() {
	fast();
	testcases{
		cin >> n;
		for (long i = 0; i < n+1; ++i){
			adjc[i].clear();
		}
		for (long i = 1; i < n+1; ++i){
			cin >> aval[i];
		}
		for (long i = 0; i < n-1; ++i){
			int a, b;
			cin >> a >> b;
			adjc[a].push_back(b);
			adjc[b].push_back(a);
		}
		int ans = dfs(1,0);
		cout << ans << endl;
	}
    return 0;
}