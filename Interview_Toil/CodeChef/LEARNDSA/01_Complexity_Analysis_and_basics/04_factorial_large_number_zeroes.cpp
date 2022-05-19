// https://www.codechef.com/LRNDSA01
// Question: Find number of trailing zeroes in a factorial!

// Approach 1: 
// Calculate factorial manually and count the number of zeroes by dividing by 10.
// This will result in buffer overflow if number is large which is the case here!
// We need a formula!

// Approach 2:
// Take prime factors of factorial n. A trailing zero is always produced by
// prime factors 2 and 5. 
// If no. of 5's and 2's are counted, we will get the number of zeroes.
// Ex. n = 5. Factors of 5! = (2*2*2*3*5). So, count of trailing 0s is 1.
// Ex2. n = 11. Factors of 11! = ((2^8)*(3^4)*(5^2)*7). zeroes = 2.
// Observations:
// - Number of 2s >= Number of 5s. If we count number of 5s, we are done!
// Calculate floor(n/5) to find number of 5s in prime factors of n!
// Ex. 7! has one 5.
// 10! has two 5s.
// There is one another possibility, when numbers like 25, 125, etc. comes in there are more than one 5's.
// Ex. 28! has one extra 5, and the no. of 0's become 6.
// SOLUTION: 
// Divide n by 5 and remove all single 5's, then divide by 25 to remove extra 5's, and so on.
// FORMULS:
// Trailing 0s in n! = Count of 5's in prime factors of n!
// 					 = floor(n/5) + floor(n/25) + floor(n/125) + ......... 



#include <bits/stdc++.h>

using namespace std;
/*
void findZeroes(int n) {

	int count = 0;

	// keep dividing n by powers of 5 and update count
	for(int i=5; n/i >= 1; i*=5){
		count += n/i;
	}

	cout << count << endl;
}

int32_t main() {
    int t, i;
    cin >> t;
    while(t--){
    	cin >> i;
    	findZeroes(i);
    }
    return 0;
}
*/

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    long long ans = 0;
    while (n >= 5)
    {
      ans += n / 5;
      n /= 5;
    }
    cout << ans << endl;
  }
}
