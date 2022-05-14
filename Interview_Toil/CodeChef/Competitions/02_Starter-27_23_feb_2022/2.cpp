// https://www.codechef.com/START27D/problems/SALE
// 2. Get Lowest Free

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
 
int32_t main() {
	fast();
    int t;
    cin >> t;
    while(t--){
    	int a, b, c;
    	vector<int> v;
    	int to_pay = 0;
    	cin >> a >> b >> c;
    	v.push_back(a);
    	v.push_back(b);
    	v.push_back(c);
    	sort(v.begin(), v.end());
    	for (int i = 1; i < 3; ++i)
    		to_pay += v[i];
    	cout << to_pay << endl;
    }
    return 0;
}