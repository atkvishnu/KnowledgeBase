// https://www.codechef.com/LRNDSA02/problems/PSHOT
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
	for(auto element: vector) {
		os << element << " ";
	}
	return os;
}

void solve(string str){
	for (int i = 0; i < sizeof(str); ++i)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}

int32_t main() {
	fast();
    int t;
    cin >> t;
    assert(t>=1 && t<=100000);
    while(t--){
    	int n;
    	cin >> n;
    	assert(n>=1 && n<=100000);
    	string str;
    	cin >> str;
    	solve(str);
    }
    return 0;
}