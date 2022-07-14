// https://www.codechef.com/MARCH221C/problems/COUNTONES
// 1 testcase passed
// 
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

unsigned int cntSetBits(unsigned int n) {
	unsigned int count = 0;
	while(n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}

vector<string> generateBinary(int n){
	queue<string> que;
	vector<string> vec;
	que.push("1");
	while(n--) {
		string str1 = que.front();
		que.pop();
		vec.push_back(str1);

		string str2 = str1;
		que.push(str1.append("0"));
		que.push(str2.append("1"));
	}
	return vec;
}

//-----------------------------------------

int32_t main() {
	fast();
	testcases {
		ll N, K;
		cin >> N >> K;

		vector<string> vec;
		vec = generateBinary(pow(2,N)-1);

		map<string, ll> mp;

		for (ll i = 0; i < vec.size(); ++i)
		{
			string str = vec[i];
			mp[str]++;
		}
		vec.clear();
		for(auto it: mp) {
			vec.push_back(it.first);
		}
		ll sum = 0;
		ll setBits;
		ll num = 0;	
		for (ll i = 0; i < K; ++i)
		{
			num = stoi(vec[i], 0, 2);
			setBits = cntSetBits(num);
			sum += setBits;
		}
		cout << sum << endl;
	}
    
    return 0;
}