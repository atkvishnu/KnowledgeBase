# Bitwise Operators in C/C++
In C, the following 6 operators are bitwise operators (work at bit-level)   
 

![Bitwise Operators in C/C++](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Operators-In-C.png)

1.  The **& (bitwise AND)** in C or C++ takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.   
     
2.  The **| (bitwise OR)** in C or C++ takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.   
     
3.  The **^ (bitwise XOR)** in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.   
     
4.  The **<< (left shift)** in C or C++ takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.   
     
5.  The **>> (right shift)** in C or C++ takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.   
     
6.  The **~ (bitwise NOT)** in C or C++ takes one number and inverts all bits of it

**Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
	// a = 5(00000101), b = 9(00001001)
	int a = 5, b = 9;

	// The result is 00000001
	cout<<"a = " << a <<","<< " b = " << b <<endl;
	cout << "a & b = " << (a & b) << endl;

	// The result is 00001101
	cout << "a | b = " << (a | b) << endl;

	// The result is 00001100
	cout << "a ^ b = " << (a ^ b) << endl;

	// The result is 11111010
	cout << "~(" << a << ") = " << (~a) << endl;

	// The result is 00010010
	cout<<"b << 1" <<" = "<< (b << 1) <<endl;

	// The result is 00000100
	cout<<"b >> 1 "<<"= " << (b >> 1 )<<endl;

	return 0;
}
```
**Output:** 

a = 5, b = 9
a&b = 1
a|b = 13
a^b = 12
~a = 250
b<<1 = 18
b>>1 = 4



### **Interesting facts about bitwise operators**

1.  **The left shift and right shift operators should not be used for negative numbers**. If the second operand(which decides the number of shifts) is a negative number, it results in undefined behaviour in C. For example results of both 1 <<- 1 and 1 >> -1 is undefined. Also, if the number is shifted more than the size of the integer, the behaviour is undefined. For example, 1 << 33 is undefined if integers are stored using 32 bits. Another thing is, NO shift operation is performed if additive-expression(operand that decides no of shifts) is 0. See [this](https://wiki.sei.cmu.edu/confluence/display/c/INT34-C.+Do+not+shift+an+expression+by+a+negative+number+of+bits+or+by+greater+than+or+equal+to+the+number+of+bits+that+exist+in+the+operand) for more details.   
    **Note:** In **C++**, this behavior is well-defined.
2.  **The bitwise XOR operator is the most useful operator from** a **technical interview perspective.** It is used in many problems. A simple example could be “Given a set of numbers where all elements occur even a number of times except one number, find the odd occurring number” This problem can be efficiently solved by just doing XOR of all numbers.

```cpp
#include <iostream>
using namespace std;

// Function to return the only odd
// occurring element
int findOdd(int arr[], int n)
{
	int res = 0, i;
	for (i = 0; i < n; i++)
		res ^= arr[i];
	return res;
}

// Driver Method
int main(void)
{
	int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The odd occurring element is "<< findOdd(arr, n);
	return 0;
}
```

**Output:** 

The odd occurring element is 90



1.  The following are many other interesting problems using XOR operator. 
    1.  [Find the Missing Number](https://www.geeksforgeeks.org/find-the-missing-number/)
    2.  [swap two numbers without using a temporary variable](https://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/)
    3.  [A Memory Efficient Doubly Linked List](https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/)
    4.  [Find the two non-repeating elements](https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/).
    5.  [Find the two numbers with odd occurences in an unsorted-array](https://www.geeksforgeeks.org/find-the-two-numbers-with-odd-occurences-in-an-unsorted-array/).
    6.  [Add two numbers without using arithmetic operators](https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/).
    7.  [Swap bits in a given number/](https://www.geeksforgeeks.org/swap-bits-in-a-given-number/).
    8.  [Count number of bits to be flipped to convert a to b](https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/) .
    9.  [Find the element that appears once](https://www.geeksforgeeks.org/find-the-element-that-appears-once/).
    10.  [Detect if two integers have opposite signs.](https://www.geeksforgeeks.org/detect-if-two-integers-have-opposite-signs/)
2.  **The bitwise operators should not be used in place of logical operators.** The result of logical operators (&&, || and !) is either 0 or 1, but bitwise operators return an integer value. Also, the logical operators consider any non-zero operand as 1. For example, consider the following program, the results of & and && are different for same operands.

```cpp
#include <iostream>
using namespace std;

int main()
{
	int x = 2, y = 5;
	(x & y) ? cout <<"True " : cout <<"False ";
	(x && y) ? cout <<"True " : cout <<"False ";
	return 0;
}
```
**Output:** 

False True



**1.The left-shift and right-shift operators are equivalent to multiplication and division by 2 respectively.** As mentioned in point 1, it works only if numbers are positive.

```cpp
#include <iostream>
using namespace std;

int main() {

	int x = 19;
	cout<<"x << 1 = "<< (x << 1) <<endl;
	cout<<"x >> 1 = "<< (x >> 1) <<endl;
	return 0;
}
```

**Output:** 

x << 1 = 38
x >> 1 = 9

**2.The & operator can be used to quickly check if a number is odd or even.** The value of expression (x & 1) would be non-zero only if x is odd, otherwise the value would be zero.

```cpp
#include <iostream>
using namespace std;

int main() {

	int x = 19 ;
	(x & 1) ? cout<<"Odd" : cout<< "Even" ;
		
	return 0;
}
```
**Output:** 

Odd


**3.The ~ operator should be used carefully.** The result of ~ operator on a small number can be a big number if the result is stored in an unsigned variable. And the result may be a negative number if the result is stored in a signed variable (assuming that the negative numbers are stored in 2’s complement form where the leftmost bit is the sign bit)

```cpp
#include <iostream>
using namespace std;

int main() {

	unsigned int x = 1;
	signed int a = 1;
	cout<<"Signed Result "<< ~a <<endl ;
	cout<<"Unsigned Result "<< ~x ;
	return 0;
}
```
**Output:** 

Signed Result -2 
Unsigned Result 4294967294d

----
----
----


# Bitwise Hacks for Competitive Programming

It is recommended to refer [Interesting facts about Bitwise Operators](https://www.geeksforgeeks.org/interesting-facts-bitwise-operators-c/) as a prerequisite.  
**1. How to set a bit in the number ‘num’ :**  
If we want to set a bit at nth position in number ‘num’ ,it can be done using ‘OR’ operator( | ).   
 

-   First we left shift ‘1’ to n position via (1<<n)
-   Then, use ‘OR’ operator to set bit at that position.’OR’ operator is used because it will set the bit even if the bit is unset previously in binary representation of number ‘num’.

```cpp
#include<iostream>
using namespace std;
// num is the number and pos is the position
// at which we want to set the bit.
void set(int & num,int pos)
{
	// First step is shift '1', second step is bitwise OR
	num |= (1 << pos);
}
int main()
{
	int num = 4, pos = 1;
	set(num, pos);
	cout << (int)(num) << endl;
	return 0;
}
```
Output:   
6

We have passed the parameter by ‘call by reference’ to make permanent changes in the number.  
**2. How to unset/clear a bit at n’th position in the number ‘num’ :**


Suppose we want to unset a bit at nth position in number ‘num’ then we have to do this with the help of ‘AND’ (&) operator.

-   First we left shift ‘1’ to n position via (1<<n) than we use bitwise NOT operator ‘~’ to unset this shifted ‘1’.
-   Now after clearing this left shifted ‘1’ i.e making it to ‘0’ we will ‘AND'(&) with the number ‘num’ that will unset bit at nth position position.


```c
#include <iostream>
using namespace std;
// First step is to get a number that has all 1's except the given position.
void unset(int &num,int pos)
{
	//Second step is to bitwise and this number with given number
	num &= (~(1 << pos));
}
int main()
{
	int num = 7;
	int pos = 1;
	unset(num, pos);
	cout << num << endl;
	return 0;
}

```
Output:   
5

**3.  Toggling a bit at nth position :**  
Toggling means to turn bit ‘on'(1) if it was ‘off'(0) and to turn ‘off'(0) if it was ‘on'(1) previously.We will be using ‘XOR’ operator here which is this ‘^’. The reason behind ‘XOR’ operator is because of its properties.   
 

-   Properties of ‘XOR’ operator. 
    -   1^1 = 0
    -   0^0 = 0
    -   1^0 = 1
    -   0^1 = 1
-   If two bits are different then ‘XOR’ operator returns a set bit(1) else it returns an unset bit(0).

```c
#include <iostream>
using namespace std;
// First step is to shift 1,Second step is to XOR with given number
void toggle(int &num,int pos)
{
	num ^= (1 << pos);
}
int main()
{
	int num = 4;
	int pos = 1;
	toggle(num, pos);
	cout << num << endl;
	return 0;
}
```
Output: 
6

**4. Checking if bit at nth position is set or unset:**

It is quite easily doable using ‘AND’ operator.

-   Left shift ‘1’ to given position and then ‘AND'(‘&’).

```c
#include <iostream>
using namespace std;

bool at_position(int num,int pos)
{
	bool bit = num & (1<<pos);
	return bit;
}

int main()
{
	int num = 5;
	int pos = 0;
	bool bit = at_position(num, pos);
	cout << bit << endl;
	return 0;
}
```
Output:
1

Observe that we have first left shifted ‘1’ and then used ‘AND’ operator to get bit at that position. So if there is ‘1’ at position ‘pos’ in ‘num’, then after ‘AND’ our variable ‘bit’ will store ‘1’ else if there is ‘0’ at position ‘pos’ in the number ‘num’ than after ‘AND’ our variable bit will store ‘0’.

**Some more quick hacks:**   
 

-   **Inverting every bit of a number/1’s complement:**   
     

If we want to invert every bit of a number i.e change bit ‘0’ to ‘1’ and bit ‘1’ to ‘0’.We can do this with the help of ‘~’ operator. For example : if number is num=00101100 (binary representation) so ‘~num’ will be ‘11010011’.

_This is also the ‘1s complement of number’._

```c
#include <iostream>
using namespace std;
int main()
{
	int num = 4;

	// Inverting every bit of number num
	cout << (~num);
	return 0;
}
```
Output:
 -5

-   **Two’s complement of the number:** 2’s complement of a number is 1’s complement + 1.

So formally we can have 2’s complement by finding 1s complement and adding 1 to the result i.e (~num+1) or what else we can do is using ‘-‘ operator.

```c
#include <iostream>
using namespace std;
int main()
{
	int num = 4;
	int twos_complement = -num;
	cout << "This is two's complement " << twos_complement << endl;
	cout << "This is also two's complement " << (~num+1) << endl;
	return 0;
}
```
Output:
This is two's complement -4
This is also two's complement -4

-   **Stripping off the lowest set bit :**

In many situations we want to strip off the lowest set bit for example in Binary Indexed tree data structure, counting number of set bit in a number.

We do something like this:   
 

```
X = X & (X-1)
```

But how does it even work ?  
Let us see this by taking an example, let X = 1100.  
(X-1)  inverts all the bits till it encounter lowest set ‘1’ and it also invert that lowest set ‘1’.  
X-1 becomes 1011. After ‘ANDing’ X with X-1 we get lowest set bit stripped.


```cpp
#include <iostream>
using namespace std;
void strip_last_set_bit(int &num)
{
	num = num & (num-1);
}
int main()
{
	int num = 7;
	strip_last_set_bit(num);
	cout << num << endl;
	return 0;
}
```
Output:   
6

-   **Getting lowest set bit of a number:**

This is done by using expression ‘X &(-X)’Let us see this by taking an example:Let X = 00101100. So ~X(1’s complement) will be ‘11010011’ and 2’s complement will be (~X+1 or -X) i.e  ‘11010100’.So if we ‘AND’ original number ‘X’ with its two’s complement which is ‘-X’, we get lowest set bit.   
 

00101100
& 11010100

-----------
00000100


```cpp
#include <iostream>
using namespace std;
int lowest_set_bit(int num)
{
	int ret = num & (-num);
	return ret;
}
int main()
{
	int num = 10;
	int ans = lowest_set_bit(num);
	cout << ans << endl;
	return 0;
}
```
Output:   
2

**Division by 2 and Multiplication by 2 are very frequently that too in loops in Competitive Programming so using Bitwise operators can help in speeding up the code.**

**Divide by 2 using right shift operator:**

00001100 >> 1 (00001100 is 12)

--
00000110 (00000110 is 6)


```cpp
#include <iostream>
using namespace std;
int main()
{
	int num = 12;
	int ans = num>>1;
	cout << ans << endl;
	return 0;
}
```
**Output**
6

**Multiply by 2 using left shift operator:**

```
00001100 << 1 (00001100 is 12)

------------
00011000 (00000110 is 24)
```

```cpp
#include <iostream>
using namespace std;
int main()
{
	int num = 12;
	int ans = num<<1;
	cout << ans << endl;
	return 0;
}
```
**Output**
24





-----------
--------
---------
---------




# Bit Tricks for Competitive Programming

We have considered the below mentioned facts –   
 
-   0 based indexing of bits from right to left.
-   Setting i-th bit means, turning i-th bit to 1
-   Clearing i-th bit means, turning i-th bit to 0


### **1) Clear all bits from LSB to ith bit**

```
mask = ~((1 << i+1 ) - 1);
x &= mask;
```

**Logic:** To clear all bits from LSB to i-th bit, we have to AND x with mask having LSB to i-th bit 0. To obtain such mask, first left shift 1 i times. Now if we minus 1 from that, all the bits from 0 to i-1 become 1 and remaining bits become 0. Now we can simply take complement of mask to get all first i bits to 0 and remaining to 1.   
Example-   
x = 29 (00011101) and we want to clear LSB to 3rd bit, total 4 bits   
mask -> 1 << 4 -> 16(00010000)   
mask -> 16 – 1 -> 15(00001111)   
mask -> ~mask -> 11110000   
x & mask -> 16 (00010000)


### **2) Clearing all bits from MSB to i-th bit**
```
mask = (1 << i) - 1;
x &= mask;
```

**Logic:** To clear all bits from MSB to i-th bit, we have to AND x with mask having MSB to i-th bit 0. To obtain such mask, first left shift 1 i times. Now if we minus 1 from that, all the bits from 0 to i-1 become 1 and remaining bits become 0.   
Example-   
x = 215 (11010111) and we want to clear MSB to 4th bit, total 4 bits   
mask -> 1 << 4 -> 16(00010000)   
mask -> 16 – 1 -> 15(00001111)   
x & mask -> 7(00000111)

### **3) Divide by 2**
```
x >>= 1;
```
**Logic:** When we do arithmetic right shift, every bit is shifted to right and blank position is substituted with sign bit of number, 0 in case of positive and 1 in case of negative number. Since every bit is a power of 2, with each shift we are reducing the value of each bit by factor of 2 which is equivalent to division of x by 2.   
Example-   
x = 18(00010010)   
x >> 1 = 9 (00001001)

### **4) Multiplying by 2**
```
x <<= 1;
```
**Logic:** When we do arithmetic left shift, every bit is shifted to left and blank position is substituted with 0 . Since every bit is a power of 2, with each shift we are increasing the value of each bit by a factor of 2 which is equivalent to multiplication of x by 2.   
Example-   
x = 18(00010010)   
x << 1 = 36 (00100100)

### **5) Upper case English alphabet to lower case**
```
ch |= ' ';
```

**Logic:** The bit representation of upper case and lower case English alphabets are –

A -> 01000001          a -> 01100001
B -> 01000010          b -> 01100010
C -> 01000011          c -> 01100011
  .                                       .
  .                                       .
Z -> 01011010          z -> 01111010

As we can see if we set 5th bit of upper case characters, it will be converted into lower case character. We have to prepare a mask having 5th bit 1 and other 0 (00100000). This mask is bit representation of space character (‘ ‘). The character ‘ch’ then ORed with mask.  
Example-   
ch = ‘A’ (01000001)   
mask = ‘ ‘ (00100000)   
ch | mask = ‘a’ (01100001)   
Please refer [Case conversion (Lower to Upper and Vice Versa)](https://www.geeksforgeeks.org/case-conversion-lower-upper-vice-versa-string-using-bitwise-operators-cc/) for details.



### **6) Lower case English alphabet to upper case**


```
ch &= '_’ ;
```

**Logic:** The bit representation of upper case and lower case English alphabets are –

A -> 01000001                a -> 01100001
B -> 01000010                b -> 01100010
C -> 01000011                c -> 01100011
.                                                .
.                                                .
Z -> 01011010                z -> 01111010

As we can see if we clear 5th bit of lower case characters, it will be converted into upper case character. We have to prepare a mask having 5th bit 0 and other 1 (10111111). This mask is bit representation of underscore character (‘_‘). The character ‘ch’ then AND with mask.   
Example-   
ch = ‘a’ (01100001)   
mask = ‘_ ‘ (11011111)   
ch & mask = ‘A’ (01000001)



### **7) Count set bits in integer**

```cpp
int countSetBits(int x)
{
	int count = 0;
	while (x)
	{
		x &= (x-1);
		count++;
	}
	return count;
}

```
**Logic:** This is [**Brian Kernighan’s** algorithm](https://www.geeksforgeeks.org/count-set-bits-in-an-integer/).



### **8) Find log base 2 of 32 bit integer**

```
int log2(int x)
{
	int res = 0;
	while (x >>= 1)
		res++;
	return res;
}

```


**Logic:** We right shift x repeatedly until it becomes 0, meanwhile we keep count on the shift operation. This count value is the log2(x).  


### **9) Checking if given 32 bit integer is power of 2**

```
int isPowerof2(int x)
{
	return (x && !(x & x-1));
}

```

**Logic:** All the power of 2 have only single bit set e.g. 16 (00010000). If we minus 1 from this, all the bits from LSB to set bit get toggled, i.e., 16-1 = 15 (00001111). Now if we AND x with (x-1) and the result is 0 then we can say that x is power of 2 otherwise not. We have to take extra care when x = 0.  
Example   
x = 16(000100000)   
x – 1 = 15(00001111)   
x & (x-1) = 0   
so 16 is power of 2



























































