# Some useful C++ tricks for beginners in Competitive Programming

1. Using the **auto** keyword to declare datatypes can save a lot of time during programming contests.

When a variable is defined as auto, compiler can determing the datatype on its own.  

```
**Example**:

**auto** a = 100; // a will become 'int'
**auto** b = 1LL; // b will become 'long long'
**auto** c = 1.0; // c will become 'double'
**auto** d = "variable"; // d will become 'string'
```

2.  The watch macro is one of the most useful tricks ever.

```    
    #define watch(x) cout << (#x) << " is " << (x) << endl
```    
If you’re debugging your code, watch(variable); will print the name of the variable and its value. (It’s possible because it’s build in preprocessing time.)
    
3.  Using typedef’s can save a lot of time of yours which you might spend re-writing the same snippet again and again.  

```
	**Example**:
    
    typedef long long ll;
    typedef pair w;
    typedef vector va;
    typedef vector vb;
    typedef vector vc;
```

4.  There’s an inbuilt function to evaluate the [greatest common divisor of two numbers](https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/). It’s called **__gcd()** and it’s present in the **algorithm** header file. To read more about it, refer: [https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/](https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/)

5.  Using “\n” for adding new line breaks is much faster than using “endl”.

6.  If you use `**ios::sync_with_stdio(false)**` at the beginning of your code, you’ll make **cin** and **cout** as fast as **printf** and **scanf**, but you’ll no longer be able to use neither _printf_ nor _scanf_.

----
----
----
# Writing C/C++ code efficiently in Competitive programming

First of all you need to know about [Template](https://www.geeksforgeeks.org/template-specialization-c/), [Macros](https://www.geeksforgeeks.org/interesting-facts-preprocessors-c/) and [Vectors](https://www.geeksforgeeks.org/vector-in-cpp-stl/) before moving on the next phase! 

-   `Templates` are the foundation of generic programming, which involve writing code in a way that is independent of any particular type.
-   A `Macro` is a fragment of code which has been given a name. Whenever the name is used, it is replaced by the contents of the macro.
-   `Vectors` are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.

So we can use these powerful tools for writing our code in a effective way.  
Some of the cool tricks that may be used in Competitive programming are given as follows:


1.  **Using Range based for loop**: This is very cool feature in C++11 and would be considered best if you want to iterate from begins to end. This code shows how to use ranged for loops to iterate through an array and a vector:


```cpp
// C++ program to demonstrate range based for
// loops for accessing vector and array elements
#include<iostream>
#include <vector>
using namespace std;

int main()
{
	// Create a vector object that
	// contains 5 elements
	vector<int> vec = {0, 1, 2, 3, 4};

	// Type inference by reference using auto.
	// Range based loops are preferred when no
	// modification is needed in value
	for (const auto &value : vec)
		cout << value << ' ';

	cout << '\n';

	// Basic 5 element integer array
	int array[]= {1, 2, 3, 4, 5};
	for (const auto &value: array)
		cout << value << " ";

	return 0;
}

```

**Output:**

0 1 2 3 4
1 2 3 4 5

2.  **Initializer list:** This type is used to access the values in a C++ initialization list. Here the objects of this type are automatically constructed by the compiler from initialization list declarations, which is a list of comma-separated elements enclosed in braces.

```cpp
#include<iostream>

template<typename T>
void printList(std::initializer_list<T> text)
{
	for (const auto & value: text)
		std::cout << value << " ";
}

// Driver program
int main()
{
	// Initialization list
	printList( {"One", "Two", "Three"} );
	return 0;
}

```


**Output:** 
One Two Three

3.  **Assigning Maximum or Minimum value:** This one is useful to avoid extra effort in writing max() or min() function.

```cpp
#include<iostream>

// Call by reference is used in x
template<typename T, typename U>
static inline void amin(T &x, U y)
{
	if (y < x)
		x = y;
}

// call by reference is used in x
template<typename T, typename U>
static inline void amax(T &x, U y)
{
	if (x < y)
		x = y;
}

// Driver program to find the Maximum and Minimum value
int main()
{
	int max_val = 0, min_val = 1e5;
	int array[]= {4, -5, 6, -9, 2, 11};

	for (auto const &val: array)

		// Same as max_val = max (max_val, val)
		// Same as min_val = min (min_val,val)
		amax(max_val, val), amin (min_val, val);


	std::cout << "Max value = " << max_val << "\n"
			<< "Min value = " << min_val;
	return 0;
}

```

**Output:**

Max value = 11
Min value = -9

4.  **Fast Input/Output in C/C++:** In Competitive programming, you must read Input/Output as fast as possible to save valuable time.

```c
#include <bits/stdc++.h>

template<typename T> void scan(T &x)
{
	x = 0;
	bool neg = 0;
	register T c = getchar();

	if (c == '-')
		neg = 1, c = getchar();

	while ((c < 48) || (c > 57))
		c = getchar();

	for ( ; c < 48||c > 57 ; c = getchar());

	for ( ; c > 47 && c < 58; c = getchar() )
		x= (x << 3) + ( x << 1 ) + ( c & 15 );

	if (neg) x *= -1;
}

template<typename T> void print(T n)
{
	bool neg = 0;

	if (n < 0)
		n *= -1, neg = 1;

	char snum[65];
	int i = 0;
	do
	{
		snum[i++] = n % 10 + '0';
		n /= 10;
	}

	while (n);
	--i;

	if (neg)
		putchar('-');

	while (i >= 0)
		putchar(snum[i--]);

	putchar('\n');
}

// Driver Program
int main()
{
	int value;

	// Taking input
	scan(value);

	// Printing output
	print(value);
	return 0;
}

```


Input:  756
Output: 756

To know more about fast input and output [Read this article](https://www.geeksforgeeks.org/fast-io-for-competitive-programming/) . 

5.  **Using Macros as for loop**: Perhaps, it would not be good to use such macros as it would reduce the readability of code but for writing fast code you can take that risk!

```cpp
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)


// Driver program to test above Macros
int main()
{
	int i;
	int array[] = {4, 5, 6, 9, 22, 11};
	int size= sizeof(array)/sizeof(array[0]);
	
	// Default 0 index based loop
	rep(i, size)	
		cout << array[i] << " ";
	cout<<"\n";
	
	// Starting index based loop
	REP(i, 1, size-1)	
		cout << array[i] << " ";
	cout<<"\n";
	
	// Reverse for loop
	REPR(i, size-1,0)	
		cout << array[i] << " ";
	return 0;
}

```


**Output** 

4 5 6 9 22 11
5 6 9 22 11
11 22 9 6 5 4

-  **Using “bits/stdc++.h”:** Instead of adding tons of #include lines, just use #include<bits/stdc++.h> The files includes all the header files you’ll need in competitive programming, saving a lot of your time.
-   **Containers:** Using various containers like vector, list, map etc enables one to use the pre-defined functions and reduces the size of code considerably (more often than not)
-   **Fast cin and cout:** If you use cin and cout for I/O, just add the following line just after the main().

```
std::ios_base::sync_with_stdio(false);
```

-   **auto:** Using auto to declare datatypes can save lot of time during programming contests. When a variable is defined as auto, compiler determines its type during compile-time.
-   **Libraries and pre-defined functions:** Using builtin functions such as __gcd(A,B), swap, _builtin_popcount(R), _builtin_clz(R) etc wherever that can be applied. Try to learn different functions available in [algorithm](https://www.geeksforgeeks.org/c-magicians-stl-algorithms/) library of C++.They are useful most of the times in programs

----
----
----



Although practice is the only way that ensures increased performance in programming contests but having some tricks up your sleeve ensures an upper edge and fast debugging.

**1) Checking if the number is even or odd without using the % operator:**  
Although this trick is not much better than using % operator but is sometimes efficient (with large numbers). Use & operator:


```cpp
if (num & 1)
	cout << "ODD";
else
	cout << "EVEN";
```

Example:  
num = 5  
Binary: “101 & 1” will be 001, so true  
num = 4  
Binary: “100 & 1” will be 000, so false.

**2) Fast Multiplication or Division by 2**  
Multiplying by 2 means shifting all the bits to left and dividing by 2 means shifting to the right.

Example : 2 (Binary 10): shifting left 4 (Binary 100) and right 1 (Binary 1)

```cpp
n = n << 1; // Multiply n with 2
n = n >> 1; // Divide n by 2
```

**3) Swapping of 2 numbers using XOR:**  
This method is fast and doesn’t require the use of 3rd variable.

```cpp
// A quick way to swap a and b
a ^= b;
b ^= a;
a ^= b;

```

**4) Avoiding use of strlen():**

```cpp
// Use of strlen() can be avoided by:
for (i=0; s[i]; i++)
{

}
// loop breaks when the character array ends.

```

**5) Use of emplace_back() (Discussed [here](https://www.geeksforgeeks.org/insert-elements-c-stl-list/), [here](https://www.geeksforgeeks.org/inserting-elements-in-stdmap-insert-emplace-and-operator/) and [here](https://www.geeksforgeeks.org/insertion-deletion-stl-set-c/))**  
Instead of push_back() in STL emplace_back can be used because it is much faster and instead of allocating memory somewhere else and then appending it directly allocates memory in the container.

**6) Inbuilt GCD function:** C++ has inbuilt GCD function and there is no need to explicitly code it. Syntax: __gcd(x, y);

**7) Using Inline functions:** We can create inline functions and use them without having to code them up during the contest. Examples: (a) function for sieve, (b) function for palindrome.


**8) Maximum size of the array:** We must be knowing that the maximum size of array declared inside the main function is of the order of 10^6 but if you declare array globally then you can declare its size upto 10^7.

**9) Calculating the most significant digit:** To calculate the most significant digit of any number log can be directly used to calculate it.

```
Suppose the number is N then 
Let double K = log10(N);
now K = K - floor(K);
int X = pow(10, K);
X will be the most significant digit.
```

**10) Calculating the number of digits directly:** To calculate number of digits in a number, instead of looping you can efficiently use log :

```
Number of digits in N =floor(log10(N)) + 1;  
```

**11) [Efficient trick to know if a number is a power of 2](https://www.geeksforgeeks.org/program-to-find-whether-a-no-is-power-of-two/)** sing the normal technique of division the complexity comes out to be O(logN), but it can be solved using O(v) where v are the number of digits of number in binary form.

```cpp
/* Function to check if x is power of 2*/
bool isPowerOfTwo (int x)
{
	/* First x in the below expression is for the case when x is 0 */
	return x && (!(x&(x-1)));
}
```

**12) C++11 has in built algorithms for following:**

```
       // are all of the elements positive?
       all_of(first, first+n, ispositive()); 

      // is there at least one positive element?
      any_of(first, first+n, ispositive());

      // are none of the elements positive?
      none_of(first, first+n, ispositive()); 
```

Please refer [Array algorithms in C++ STL (all_of, any_of, none_of, copy_n and itoa)](https://www.geeksforgeeks.org/useful-array-algorithms-in-c-stl/) for details.

**13) Copy Algorithm: used to copy elements from one container to another.**

```
int source[5] = {0, 12, 34, 50, 80};
int target[5];
// copy 5 elements from source to target
copy_n(source, 5, target);
```

Please refer [Array algorithms in C++ STL (all_of, any_of, none_of, copy_n and itoa)](https://www.geeksforgeeks.org/useful-array-algorithms-in-c-stl/) for details.

**14) The Iota Algorithm** The algorithm iota() creates a range of sequentially increasing values, as if by assigning an initial value to *first, then incrementing that value using prefix ++. In the following listing, iota() assigns the consecutive values {10, 11, 12, 13, 14} to the array arr, and {‘a’, ‘b’, ‘c’} to the char array c[].

```cpp
int a[5] = {0};
char c[3] = {0};

// changes a to {10, 11, 12, 13, 14}
iota(a, a+5, 10);
iota(c, c+3, 'a'); // {'a', 'b', 'c'}

```

Please refer [Array algorithms in C++ STL (all_of, any_of, none_of, copy_n and itoa)](https://www.geeksforgeeks.org/useful-array-algorithms-in-c-stl/) for details.

**15) Initialization in Binary form:** In C++ 11 assignments can also be made in binary form.

```cpp
// C++ code to demonstrate working of
// "binary" numbers
#include<iostream>
using namespace std;
int main()
{
	auto number = 0b011;
	cout << number;
	return 0;
}

```

Output :

3

**16) Use of “and”** Though not a very productive one, this tip helps you to just use conditional operator and instead of typing &.

```cpp
// C++ code to demonstrate working of "and"
#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	if (a < 20 and a > 5)
	cout << "Yes";
	return 0;
}

```
Output :

Yes

----
----
----


# Write a one line C function to round floating point numbers

**Algorithm:** roundNo(num)  
1. If num is positive then add 0.5.  
2. Else subtract 0.5.  
3. Type cast the result to int and return.  

**Example:**  
num = 1.67, (int) num + 0.5 = (int)2.17 = 2  
num = -1.67, (int) num – 0.5 = -(int)2.17 = -2

**Implementation:**

```cpp
/* Program for rounding floating point numbers */
# include<stdio.h>

int roundNo(float num)
{
	return num < 0 ? num - 0.5 : num + 0.5;
}

int main()
{
	printf("%d", roundNo(-1.777));
	getchar();
	return 0;
}

```

Output: -2

**Time complexity:** O(1)  
**Space complexity:** O(1)

Now try rounding for a given precision. i.e., if given precision is 2 then function should return 1.63 for 1.63322 and -1.63 for 1.6332.



























