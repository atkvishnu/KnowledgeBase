// https://www.codechef.com/MARCH221C/problems/SUB_XOR

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

// Function to print all sub strings
vector<string> subString(string s, int n)
{
	vector<string> v1;
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            v1.push_back(s.substr(i, len));
        }
    }
    return v1;
}

vector<string> subString1(string str, int n)
{
	vector<string> v1;
    // First loop for starting index
    for (int i = 0; i < str.length(); i++) {
        string subStr;
        // Second loop is generating sub-string
        for (int j = i; j < str.length(); j++) {
            subStr += str[j];
            v1.push_back(subStr);
        }
    }
    return v1;
}

vector<string> v1;

// str : Stores input string
// curr : Stores current subset
// index : Index in current subset, curr
void powerSet(string str, int index = -1, string curr = "")
{
    int n = str.length();
 
    // base case
    if (index == n)
        return;
 
    // First print current subset
    v1.push_back(curr);

 
    // Try appending remaining characters
    // to current subset
    for (int i = index + 1; i < n; i++) {
 
        curr += str[i];
        powerSet(str, i, curr);
 
        // Once all subsets beginning with
        // initial "curr" are printed, remove
        // last character to consider a different
        // prefix of subsets.
        curr.erase(curr.size() - 1);
    }
    return;
}



int convert(long long n) {
  ll dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

// faster conversion
unsigned binary_to_decimal(unsigned num)
{
    unsigned res = 0;

    for(int i = 0; num > 0; ++i)
    {
        if((num % 10) == 1)
            res += (1 << i);

        num /= 10;
    }

    return res;
}


int32_t main() {
	fast();
    testcases {
    	ll n;
    	string s;
    	cin >> n;
    	cin >> s;
    	v1 = powerSet(s);
    	ll sum = 0;
    	for (ll i = 0; i < v1.size(); ++i)
    	{
    		sum ^= binary_to_decimal(stoi(v1[i]));
    		sum = sum%mod;
    	}
    	cout << sum << endl;
	    // cout << v1 << endl;
    }
    return 0;
}
