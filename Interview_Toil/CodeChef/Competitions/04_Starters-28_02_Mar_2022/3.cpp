// https://www.codechef.com/START28C/problems/SUNDAY
// 3. Count the Holidays

#include <bits/stdc++.h>
using namespace std;

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


int32_t main() {
	fast();
	testcases{
		int n;
		cin >> n;
		int arr[n];
		int counter = 8;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			if(arr[i]%7!=0 && arr[i]%7!=6){
				counter++;
			}
		}
		cout << counter << endl;
	}
    return 0;
}