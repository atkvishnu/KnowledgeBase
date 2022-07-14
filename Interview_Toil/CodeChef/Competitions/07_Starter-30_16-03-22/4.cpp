#include<bits/stdc++.h>
#define ll  long long int
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll a[n], b[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        ll op1 = b[0] - a[0], op2 = 0;
        ll res1 = 0, res2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (op1 + op2 < b[i] - a[i])
            {
                op2 += ((b[i] - a[i]) - op1 - op2);
            }
            else if (op1 + op2 > b[i] - a[i])
            {
                op1 -= (op1 + op2 - (b[i] - a[i]));
            }

            if (op1 < 0 || op2 > (b[n - 1] - a[n - 1]))
            {
                res1 = -1;
                res2 = 0;
                break;
            }

            res1 = max(res1, op1);
            res2 = max(res2, op2);
        }

        ll res = res1 + res2;

        cout << res << endl;
    }
}