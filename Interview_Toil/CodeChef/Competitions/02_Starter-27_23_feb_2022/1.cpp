// https://www.codechef.com/START27D/problems/SHOPCHANGE
// 1. Shopping Change

#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;
 
int32_t main() {
	fast();
    int t;
    int TOTAL_MONEY = 100;
    cin >> t;
    while(t--){
    	int spending;
    	cin >> spending;
    	cout << TOTAL_MONEY - spending << endl;
    }
    return 0;
}