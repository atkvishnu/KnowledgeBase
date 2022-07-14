// https://www.codechef.com/LRNDSA01
// Zonal Computing Olympiad 2014, 30 Nov 2013

// You are developing a smartphone app. 
// You have a list of potential customers for your app. 
// Each customer has a budget and will buy the app at your declared price 
// if and only if the price is less than or equal to the customer's budget.


// You want to fix a price so that the revenue you earn from the app is 
// maximized. Find this maximum possible revenue.


// For instance, suppose you have 4 potential customers and their budgets 
// are 30, 20, 53 and 14. In this case, the maximum revenue you can get is 60 .


// Input format
// Line 1 : N, the total number of potential customers.

// Lines 2 to N+1: Each line has the budget of a potential customer.


// Output format
// The output consists of a single integer, the maximum possible revenue you 
// can earn from selling your app.

#include <bits/stdc++.h>

#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;

typedef long long ll;
typedef long double ld;

// prints vector using <<. (Example: cout << v << endl;)
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
	// printing all the elems using <<
	for(auto element: vector) {
		os << element << " ";
	}
	return os;
}
 
int32_t main() {
    
    long long n;
    cin >> n;
    
    long long arr[n];
    
    for(long long i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    
    sort(arr,arr+n);
 
    long long ans = arr[0];
    
    for(long long i = 0; i < n; i++) {
    	ans = max(ans, arr[i]*(n-i));
    }
    
    cout << ans;

    return 0;

}