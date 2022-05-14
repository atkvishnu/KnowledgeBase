// https://www.codechef.com/START30B/problems/PRESUFOP


#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define repi(i, x, n) for (int i = x; i < n; i++)
#define br cout << endl
#define vi vector<int>
using namespace std;

void solve()
{
    int n,x,k;
    cin>>n>>x>>k;
    int res = min(k/x,n);
    cout<<res<<endl;

}

signed main()
{
    fastio int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}