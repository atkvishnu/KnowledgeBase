// https://www.codechef.com/COOK138D/problems/HOLIDAYS
// 4. Lazy salesman

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
    while(t--) {
    	int n,w,a;
    	cin >> n >> w;
    	int sum = 0;
    	int count = 0;
    	vector<int> vec;
    	for (int i = 0; i < n; ++i)
    	{
    		cin >> a;
    		vec.push_back(a);
    	}
    	sort(vec.begin(),vec.end());
    	for (int i = n-1; w > sum; i--){
    		sum+=vec[i];
    		count++;
    	}
    	cout << n-count << endl;
    }
    return 0;
}