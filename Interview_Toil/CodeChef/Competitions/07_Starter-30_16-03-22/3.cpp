// https://www.codechef.com/START30B/problems/MINCOLOR

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define int long long
#define br cout << endl
#define vi vector<int>
using namespace std;

void solve()
{
    int n, m, x1, x2, y1, y2;
    cin >> n >> m;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    x1--;
    x2--;
    y1--;
    y2--;
    if (((x1 + y1) % 2) != ((x2 + y2) % 2))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp = (i + j) % 2;
                if (temp == (x1 + y1) % 2)
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << 2 << " ";
                }
            }
            cout << endl;
        }
        return;
    }
    
    int res[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = (i + j) % 2;
            if (temp == (x1 + y1) % 2)
            {
                res[i][j]=1;
            
            }
            else
            {
                res[i][j]=2;
            }
        }
    }
    res[x1][y1]=1;
    res[x2][y2]=2;

    if (x2>0){
        res[x2-1][y2]=3;
    }
    if (x2<n-1){
        res[x2+1][y2]=3;
    }
    if (y2>0){
        res[x2][y2-1]=3;
    }
    if (y2<m-1){
        res[x2][y2+1]=3;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}

signed main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}