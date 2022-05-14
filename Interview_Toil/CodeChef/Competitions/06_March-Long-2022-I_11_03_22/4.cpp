// https://www.codechef.com/MARCH221C/problems/GENIUS

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

void solve(int N, int X) {
	int solved_correct = 0;
	int solved_wrong = 0;
	int unattempted = 0;
	if(X%3 == 0) {
		solved_correct = X/3;
	} else if (X%3==1) {
		solved_correct += X/3;
		solved_correct += 1;
		solved_wrong += 2;
	} else if (X%3 == 2) {
		solved_correct += X/3;
		solved_correct += 1;
		solved_wrong += 1;
	}
	unattempted = N - solved_correct - solved_wrong;
	if(solved_correct + solved_wrong <= N) {
		cout << "Yes" << endl;
		cout << solved_correct << " " << solved_wrong << " " << unattempted << endl;
	} else {
		cout << "No" << endl;
	}
}



int32_t main() {
	fast();
    testcases {
    	int N, X;
    	cin >> N >> X;
    	solve(N,X);
    }
    return 0;
}