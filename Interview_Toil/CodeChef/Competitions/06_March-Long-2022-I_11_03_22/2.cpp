// https://www.codechef.com/MARCH221C/problems/CHFCLASS


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
    // testcases{
    // 	int N;
    // 	cin >> N;
    // 	assert(N>=1 && N<=100);
    // 	vector<int> days(30,0);
    // 	int count = 0;
    // 	days[5] = 1;
    // 	days[11] = 1;
    // 	days[17] = 1;
    // 	days[23] = 1;
    // 	days[29] = 1;
    // 	for(int i = 0; i < N; i++) {
    // 		if(days[i] > 0) {
    // 			count++;
    // 		}
    // 	}
    // 	cout << days << endl;
    // 	cout << count << endl;
    // }
	testcases{
		int n;
		cin >> n;
		int max = 0;
		max = max + (n/7);
		if(n%7 == 6) {
			max++;
		}
		cout << max << endl;
	}
    return 0;
}