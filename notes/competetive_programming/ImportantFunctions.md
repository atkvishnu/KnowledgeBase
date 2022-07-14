# A one liner C function to round floating point numbers

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


---
---
---

# How to count set bits in a floating point number in C?

[[https://www.geeksforgeeks.org/count-set-bits-floating-point-number/?ref=lbp]]


---
---
---

















