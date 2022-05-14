// https://www.codechef.com/LRNDSA01
// Lapindrome is defined as a string which when split in the middle, 
// gives two halves having the same characters and same frequency of each character. 
// If there are odd number of characters in the string, we ignore the middle character 
// and check for lapindrome. For example gaga is a lapindrome, since the two 
// halves ga and ga have the same characters with same frequency. 
// Also, abccab, rotor and xyzxy are a few examples of lapindromes. 
// Note that abbaab is NOT a lapindrome. 
// The two halves contain the same characters but their frequencies do not match.
// Your task is simple. Given a string, you need to tell if it is a lapindrome.

// Input:
// First line of input contains a single integer T, the number of test cases.
// Each test is a single line containing a string S composed of only lowercase English alphabet.
// Output:
// For each test case, output on a separate line: "YES" if the string is a lapindrome and "NO" if it is not.

#include <bits/stdc++.h>

#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
	// printing all the elems using <<
	for(auto element: vector) {
		os << element << " ";
	}
	return os;
}
 
int32_t main() {
    int t;
    string word;
    vector<char> v1, v2;
    cin >> t;
    while(t--){
    	cin >> word;
    	if(word.size()%2!=0){		// if odd no. of chars, ignore the middle char.
    		for (int i = 0; i < word.size()/2; ++i)
    		{
    			v1.push_back(word[i]);
    		}
    		for (int j = (word.size()/2)+1; j < word.size(); ++j)
    		{
    			v2.push_back(word[j]);
    		}
    	} else {
    		for (int i = 0; i < word.size()/2; ++i)
    		{
    			v1.push_back(word[i]);
    		}
    		for (int j = word.size()/2; j < word.size(); ++j)
    		{
    			v2.push_back(word[j]);
    		}
    	}
    	sort(v1.begin(),v1.end());
    	sort(v2.begin(),v2.end());
    	if(v1==v2){
    		cout << "YES" << endl;
    	} else {
    		cout << "NO" << endl;
    	}
    	v1.clear();
    	v2.clear();
    }
    return 0;
}