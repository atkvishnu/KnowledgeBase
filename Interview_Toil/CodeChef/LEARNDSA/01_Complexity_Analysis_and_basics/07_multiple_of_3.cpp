// https://www.codechef.com/LRNDSA01
// d2 = d0 mod10 + d1 mod10;
// d3 = d2 + d2 mod10;
// d4 = d3 + d3 mod10;
// d5 = d4 + d4 mod10;



#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;

/*
int32_t main() {
	fast();
	int t;
	cin >> t;
	while(t--){
		ll k, d0, d1;
		cin >> k >> d0 >> d1;
		long long sum = d0+d1;
		k-=2;
		while(k--){
			sum += (sum%10);
			if(k%12==0)
				break;
		}
		if(sum%3==0)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}    
    return 0;
}
*/

void solve() {
	ll k;
	int d0, d1, tmp;
	cin>>k>>d0>>d1;
	tmp = d0 + d1;

	assert(k >=2 and k <= 1e12);
	assert(d0 >= 1 and d0 <= 9);
	assert(d1 >= 0 and d1 <= 9);
	
	ll ans = tmp;
	ll sum = (2*tmp) % 10 + (4*tmp) % 10 + (8*tmp) % 10 + (6*tmp) % 10;

	k -= 2;

	if(k > 0) {
		ans += (tmp % 10);
		k--;
	}

	ans += (k / 4) * sum;

	k %= 4;

	int p = 2;
	while(k--) {
		ans += (p*tmp) % 10;
		p = (p * 2) % 10;
	}

	if((ans % 3) == 0)	cout<<"YES\n";
	else 				cout<<"NO\n";	
}

int main() {
	int t;
	cin>>t;
	while(t--) solve();
}









