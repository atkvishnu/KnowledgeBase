// https://www.codechef.com/COOK138D/problems/PREFPERM
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;
 
int32_t main() {
	fast();
    int n;
    cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        vector<int> vec;
        for (int i = 0; i < b; i++)
        {
            int x;
            cin>>x;
            vec.push_back(x);
        }
        sort(vec.begin(),vec.end());
        int temp=0;
        for (int i= 0; i < b; i++)
        {
            int p=vec[i];
            for(int j=p;j>temp;j--)
            {
                cout<<j<<" ";
            }
            temp=vec[i];
        }
        cout<<endl;
    }
    
    return 0;
}
