
// Pascal's triangle in steps of 2 starting from -N

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7, N = 1e6 + 5;
int power(int x, int y)
{
    if (y < 0)
        return 0;
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % M;
        x = x * x % M;
        y /= 2;
    }
    return res;
}
int fact[N], inv[N];

int choose(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    int ans = (fact[n] * inv[r]) % M;
    ans = (ans * inv[n - r]) % M;
    return ans;
}

signed main()
{
    fact[0] = 1, inv[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % M;
        inv[i] = power(fact[i], M - 2);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        for (int i = l; i <= r; i++)
        {
            int ans = 0;
            if ((i + n) % 2 == 0)
                ans = choose(n, (i + n) / 2);
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}