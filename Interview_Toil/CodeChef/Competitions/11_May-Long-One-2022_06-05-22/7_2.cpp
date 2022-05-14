// Just take a root and put all nodes as it's children in a A star tree

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int b, w;
        cin >> b >> w;
        vector<char> to_put{'B', 'W'};
        if (b < w)
        {
            swap(b, w);
            swap(to_put[0], to_put[1]);
        }
        if (w == 0 && b > 1)
        {
            cout << "-1\n";
            continue;
        }
        int n = b + w;
        if (n >= 1)
            cout << to_put[0];
        if (n >= 2)
            cout << to_put[1];
        if (n >= 3)
            cout << to_put[0];
        b -= 2, w--;
        for (int i = 0; i < b; i++)
            cout << to_put[0];
        for (int i = 0; i < w; i++)
            cout << to_put[1];
        cout << '\n';
        for (int i = 1; i <= n; i++)
        {
            if (i != 2 && n > 1)
                cout << i << " " << 2 << '\n';
        }
    }
    return 0;
} //ALTDIA