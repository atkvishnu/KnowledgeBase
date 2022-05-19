#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

void printVectorINT(vector<int> VECTOR){
	vector<int>::iterator it;
	for(it = VECTOR.begin(); it!=VECTOR.end(); ++it){
		cout << *it << " ";
	}
}
 
int32_t main() {
    ll n;
    cin >> n;
    ll ans = (n*(n+1))/2;
    cout << ans;
    return 0;
}