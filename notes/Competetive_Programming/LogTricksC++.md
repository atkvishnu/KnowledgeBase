# Logarithm tricks for Competitive Programming

[**Logarithm**](https://www.geeksforgeeks.org/logarithm/)**:** is the inverse function of the exponentiation which means the logarithm value of a given number x is the exponent to another number.   

[[log_b(x) = y, \to b^{y} = x]]

Below are some tricks using Logarithmic function which can be handy in competitive programming.



### Checking if a number is a power of two or not:

Given an integer **N**, the task is to check that if the number N is the power of 2. 

**Examples:**
**Input:** N = 8   
**Output:** Yes

**Input:** N = 6   
**Output:** No

**Approach:** A simple method for this is to simply take the log of the number on base 2, if you get an integer then the number is the power of 2.

Below is the implementation of the above approach:

```cpp
// C++ implementation to check that
// a integer is a power of Two

#include <bits/stdc++.h>

using namespace std;

// Function to check if the number
// is a power of two
bool isPowerOfTwo(int n)
{
	return (ceil(log2(n)) == floor(log2(n)));
}

// Driver Code
int main()
{
	int N = 8;

	if (isPowerOfTwo(N)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}


```
**Output:** 

Yes



### Kth root of a Number

Given two integers **N** and **K**, the task is to find the Kth root of the number N.

**Examples:**  

> **Input:** N = 8, K = 3   
> **Output:** 2
**Input:** N = 32, K = 5   
**Output:** 2


**Approach:** A simple solution is to use logarithmic function to find the Kth root of the number.

Below is the implementation of the above approach: 

```cpp
// C++ implementation to find
// Kth root of the number

#include <bits/stdc++.h>

using namespace std;

// Function to find the
// Kth root of the number
double kthRoot(double n, int k)
{
	return pow(k,
			(1.0 / k)
				* (log(n)
					/ log(k)));
}

// Driver Code
int main()
{
	double N = 8.0;
	int K = 3;

	cout << kthRoot(N, K);

	return 0;
}

```
**Output:** 

2




### Count digits in a Number:

Given an integer **N**, the task is to count the digits in a number N.

**Examples:** 

> **Input:** N = 243   
> **Output:** 3
> 
> **Input:** N = 1000   
> **Output:** 4

**Approach:** The idea is to find the logarithm of the number base 10 to count the number of digits.

Below is the implementation of the above approach: 

```cpp
// C++ implementation count the
// number of digits in a number

#include <bits/stdc++.h>

using namespace std;

// Function to count the
// number of digits in a number
int countDigit(long long n)
{
	return floor(log10(n) + 1);
}

// Driver Code
int main()
{
	double N = 80;

	cout << countDigit(N);

	return 0;
}

```
**Output:** 

2


### Check if N is a power of K or not:

Given two integers **N** and **K**, the task is to check if Y is power of X or not.

**Examples:**  

> **Input:** N = 8, K = 2   
> **Output:** Yes
> 
> **Input:** N = 27, K = 3   
> **Output:** Yes

**Approach:** The idea is to take log of N in base K. If it turns out to be an integer, then N is a power of K.

Below is the implementation of the above approach:

```cpp
// C++ implementation to check if
// the number is power of K

#include <bits/stdc++.h>

using namespace std;

// Function to check if
// the number is power of K
bool isPower(int N, int K)
{
	// logarithm function to
	// calculate value
	int res1 = log(N) / log(K);
	double res2 = log(N) / log(K);

	// compare to the result1
	// or result2 both are equal
	return (res1 == res2);
}

// Driver Code
int main()
{
	int N = 8;
	int K = 2;

	if (isPower(N, K)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}

```
**Output:** 

Yes

### To find the power of K greater than equal to and less than equal to N:

Given two integers **N** and **K**, the task is to find the power of K greater than equal to and less than equal to N.

**Examples:** 

> **Input:** N = 7, K = 2   
> **Output:** 4 8
> 
> **Input:** N = 18, K = 3   
> **Output:** 9 27

**Approach:** The idea is to find the floor value of the log K value of the given integer N, Then compute the Kth power of this number to compute the previous and next Kth power.

Below is the implementation of the above approach:

```cpp
// C++ implementation to find the
// previous and next power of K

#include <bits/stdc++.h>

using namespace std;

// Function to return the highest power
// of k less than or equal to n
int prevPowerofK(int n, int k)
{
	int p = (int)(log(n) / log(k));
	return (int)pow(k, p);
}

// Function to return the smallest power
// of k greater than or equal to n
int nextPowerOfK(int n, int k)
{
	return prevPowerofK(n, k) * k;
}

// Driver Code
int main()
{
	int N = 7;
	int K = 2;

	cout << prevPowerofK(N, K) << " ";

	cout << nextPowerOfK(N, K) << endl;
	return 0;
}

```
**Output:** 

4 8

### To Find the position of rightmost set bit:

Given an integer **N**, the task is to find the position of the rightmost set bit.

**Examples:**  

> **Input:** N = 7   
> **Output:** 1
> 
> **Input:** N = 8   
> **Output:** 4


**Approach:**  

-   Take two’s complement of the given no as all bits are reverted except the first ‘1’ from right to left (0111)
-   Do a bit-wise & with original no, this will return no with the required one only (0100)
-   Take the log2 of the no, you will get (position – 1) (2)

Below is the implementation of the above approach:

```cpp
// C++ implementation to find the
// rightmost set bit

#include <bits/stdc++.h>

using namespace std;

// Function to find the rightmost
// bit set of the integer N
unsigned int getFirstSetBitPos(int n)
{
	return log2(n & -n) + 1;
}

// Driver Code
int main()
{
	int N = 8;

	cout << getFirstSetBitPos(N);
	return 0;
}

```
**Output:** 

4












