# 1.

Compute XOR from 1 to n (direct method) :

Method 1 (NOOB approach):

1. Initialize result as 0.
1. Traverse all numbers from 1 to n.
1. Do XOR of numbers one by one with result.
1. At the end, return result.

Method 2 (Efficient method) :

1. Find the remainder of n by moduling it with 4.
2. If rem = 0, then xor will be same as n.
3. If rem = 1, then xor will be 1.
4. If rem = 2, then xor will be n+1.
5. If rem = 3 ,then xor will be 0.

```cpp
// Direct XOR of all numbers from 1 to n
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}
```

                    Input: 6
                    Output: 7

Time Complexity: O(1)
Auxiliary Space: O(1)

How does this work?
When we do XOR of numbers, we get 0 as XOR value just before a multiple of 4. This keeps repeating before every multiple of 4.

                    Number Binary-Repr  XOR-from-1-to-n
                    1         1           [0001]
                    2        10           [0011]
                    3        11           [0000]  <----- We get a 0
                    4       100           [0100]  <----- Equals to n
                    5       101           [0001]
                    6       110           [0111]
                    7       111           [0000]  <----- We get 0
                    8      1000           [1000]  <----- Equals to n
                    9      1001           [0001]
                    10     1010           [1011]
                    11     1011           [0000] <------ We get 0
                    12     1100           [1100] <------ Equals to n

# 2.

know if a number is a power of 2?

```cpp
//  Function to check if x is power of 2 -- O(1) O(1)
bool isPowerOfTwo(int x)
{
     // First x in the below expression is
     // for  the case when x is 0
     return x && (!(x & (x - 1)));
}
```

```cpp
// Function to check if x is power of 2 -- O(1) O(1)
// simply take the log of the number on base 2 and if you get an integer then the number is the power of 2
bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;

   return (ceil(log2(n)) == floor(log2(n)));
}
```

```cpp
// Function to check if x is power of 2  -- O(1) O(1)
bool isPowerofTwo(long long n)
{
    if (n == 0)
        return 0;
    if ((n & (~(n - 1))) == n)
        return 1;
    return 0;
}
```

# 3.

Given a set, find XOR of the XOR’s of all subsets.
i.e if the set is {1,2,3}. All subsets are : [{1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}]. Find the XOR of each of the subset and then find the XOR of every subset result.

The solution of XOR is always 0 when n > 1 and Set[0] when n is 1.

```cpp

// C++ program to find XOR of XOR's of all subsets
#include <bits/stdc++.h>
using namespace std;

// Returns XOR of all XOR's of given subset
int findXOR(int Set[], int n)
{
    // XOR is 1 only when n is 1, else 0
    if (n == 1)
        return Set[0];
    else
        return 0;
}

// Driver program
int main()
{
    int Set[] = { 1, 2, 3 };
    int n = sizeof(Set) / sizeof(Set[0]);
    cout << "XOR of XOR's of all subsets is "
         << findXOR(Set, n);
    return 0;
}
```

> Output:  
> XOR of XOR's of all subsets is 0

Time Complexity: O(1)
Auxiliary Space: O(1)

# 4.

We can quickly find number of leading, trailing zeroes and number of 1’s in a binary code of an integer in C++ using GCC. It can be done by using inbuilt function i.e.
Number of leading zeroes: builtin_clz(x)
Number of trailing zeroes : builtin_ctz(x)
Number of 1-bits: \_\_builtin_popcount(x)

# 5.

Convert binary code directly into an integer in C++.

```cpp
// Conversion into Binary code//
#include <iostream>
using namespace std;

int main()
{
    auto number = 0b011;
    cout << number;
    return 0;
}
```

> Output: 3

# 6.

Quickest way to swap two numbers:

```cpp
a ^= b;
b ^= a;
a ^= b;
```

# 7.

flip the bits of a number:

It can be done in a simple way, just simply subtract the number from the value obtained when all the bits are equal to 1.

                    Number : Given Number
                    Value  : A number with all bits set in given number.
                    Flipped number = Value – Number.

                    Example :
                    Number = 23,
                    Binary form: 10111;
                    After flipping digits number will be: 01000;
                    Value: 11111 = 31;

We can find the most significant set bit in O(1) time for a fixed size integer. For example below code is for 32-bit integer.

```cpp
int setBitNumber(int n)
{
    // Below steps set bits after
    // MSB (including MSB)

    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n>>1;

    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n>>2;

    n |= n>>4;
    n |= n>>8;
    n |= n>>16;

    // Increment n by 1 so that
    // there is only one set bit
    // which is just before original
    // MSB. n now becomes 1000000000
    n = n + 1;

    // Return original MSB after shifting.
    // n now becomes 100000000
    return (n >> 1);
}
```

# 8.

Find `most significant set bit` of a number

Given a number, find the greatest number less than the given a number which is the power of two or find the most significant bit number .

Examples:

                    Input : 10
                    Output : 8
                    Greatest number which is a Power of 2 less than 10 is 8
                    Binary representation of 10 is 1010
                    The most significant bit corresponds
                    to decimal number 8.

                    Input : 18
                    Output : 16

A simple solution is to one by one divide n by 2 until it becomes 0 and increment a count while doing this. This count actually represents the position of MSB.

```cpp
// Simple CPP program to find MSB number
// for given POSITIVE n.
#include <iostream>
using namespace std;

int setBitNumber(int n)
{
    if (n == 0)
        return 0;

    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }

    return (1 << msb);
}

// Driver code
int main()
{
    int n = 0;
    cout << setBitNumber(n);
    n = ~(int)0; // test for possible overflow
    cout << "\n" << (unsigned int)setBitNumber(n);

    return 0;
}
```

> Output: 0

Method 2:
An efficient solution for a fixed size integer (say 32 bits) is to one by one set bits, then add 1 so that only the bit after MSB is set. Finally right shift by 1 and return the answer. This solution does not require any condition checking.

```cpp
// CPP program to find MSB number for ANY given n.
#include <iostream>
#include <limits.h>
using namespace std;

int setBitNumber(int n)
{
    // Below steps set bits after
    // MSB (including MSB)

    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;

    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    // The naive approach would increment n by 1,
    // so only the MSB+1 bit will be set,
    // So now n theoretically becomes 1000000000.
    // All the would remain is a single bit right shift:
    //    n = n + 1;
    //    return (n >> 1);
    //
    // ... however, this could overflow the type.
    // To avoid overflow, we must retain the value
    // of the bit that could overflow:
    //     n & (1 << ((sizeof(n) * CHAR_BIT)-1))
    // and OR its value with the naive approach:
    //     ((n + 1) >> 1)
    n = ((n + 1) >> 1) |
        (n & (1 << ((sizeof(n) * CHAR_BIT)-1)));
    return n;
}

// Driver code
int main()
{
    int n = 273;
    cout << setBitNumber(n);
    n = ~(int)0; // test for possible overflow
    cout << "\n" << (unsigned int)setBitNumber(n);
    return 0;
}
```

> Output: 256

Method 3:

Given a number n. First, find the position of the most significant set bit and then compute the value of the number with a set bit at k-th position.

```cpp
// CPP program to find MSB
// number for given POSITIVE n.
#include <bits/stdc++.h>
using namespace std;

int setBitNumber(int n)
{

    // To find the position of the most significant set bit
    int k = (int)(log2(n));

    // To return the the value of the number with set bit at k-th position
    return 1 << k;
}

// Driver code
int main()
{
    int n = 273;
    cout << setBitNumber(n);
    n = ~(int)0; // test for possible overflow
    cout << "\n" << (unsigned int)setBitNumber(n);
    return 0;
}
```

> Output: 256

# 9.

quickly check if bits in a number are in alternate pattern (like 101010).

We compute n ^ (n >> 1). If n has an alternate pattern, then n ^ (n >> 1) operation will produce a number having set bits only. ‘^’ is a bitwise XOR operation.

```cpp
// C++ implementation to check if a number
// has bits in alternate pattern
#include <bits/stdc++.h>

using namespace std;

// function to check if all the bits are set or not
// in the binary representation of 'n'
bool allBitsAreSet(unsigned int n)
{
    // if true, then all bits are set
    if (((n + 1) & n) == 0)
        return true;

    // else all bits are not set
    return false;
}

// function to check if a number
// has bits in alternate pattern
bool bitsAreInAltOrder(unsigned int n)
{
    unsigned int num = n ^ (n >> 1);

    // to check if all bits are set
    // in 'num'
    return allBitsAreSet(num);
}

// Driver program to test above
int main()
{
    unsigned int n = 10;

    if (bitsAreInAltOrder(n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
```

> Output: Yes
