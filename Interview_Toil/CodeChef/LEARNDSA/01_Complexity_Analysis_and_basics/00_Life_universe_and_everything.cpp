// https://www.codechef.com/LRNDSA01
// Your program is to use the brute-force approach in order to find the Answer to Life, the Universe, and Everything. More precisely… rewrite small numbers from input to output. Stop processing input after reading in the number 42. All numbers at input are integers of one or two digits.

// Sample Input:
// 1
// 2
// 88
// 42
// 99

// Sample Output:
// 1
// 2
// 88

#include <bits/stdc++.h>

#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;

typedef long long ll;
typedef long double ld;

// void printVectorINT(vector<int> VECTOR){
// 	 vector<int>::iterator it;
// 	 for(it = VECTOR.begin(); it!=VECTOR.end(); ++it){
//		 cout << *it << " ";
//	 }
// }

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
    int i;
    while(1){
    	cin >> i;
 		if(i!=42)
 			cout << i << endl;
 		else
 			break;
    }
    return 0;
}