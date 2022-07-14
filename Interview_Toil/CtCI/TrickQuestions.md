# Implement Your Own sizeof

```cpp
#include<stdio.h>

#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

int main()
{
	double x;
	printf("%ld", my_sizeof(x));
	getchar();
	return 0;
}
```


`type` is like a local variable to the macro. 
`&type` gives the address of the variable (double x) declared in the program and incrementing it with 1 gives the address where the next variable of type x can be stored (here addr_of(x) + 8, for the size of a double is 8B).  
The difference gives the result that how many variables of type of x can be stored in that amount of memory which will obviously be 1 for the type x (for incrementing it with 1 and taking the difference is what we’ve done). Typecasting it into char* and taking the difference will tell us how many variables of type char can be stored in the given memory space (the difference). Since each char requires the only 1B of memory, therefore (amount of memory)/1 will give the number of bytes between two successive memory locations of the type of the variable passed on to the macro and hence the amount of memory that the variable of type x requires.  
But you won’t be able to pass any literal to this macro and know their size.

You can also implement using the function instead of a macro, but function implementation cannot be done in C as C doesn’t support function overloading and sizeof() is supposed to receive parameters of all data types.

Note that the above implementation assumes that the size of character is one byte.

**Time Complexity:** O(1)  
**Space Complexity:** O(1)

---
---
---

# How to Change the Output of printf() in main() in C without touching main()?

To change the output of printf() in main(), we can use **Macro Arguments.**

**#define macro** can be used for this task. This macro is defined inside the function. Although, **#define** can be used without declaring it in the function, in that case always the printf() will be changed. **The function needs to be called first to change the output of printf() in main().**


```c
// C Program to demonstrate changing the output of printf()
// in main()
#include <tdio.h>

void fun()
{
	// Add something here so that the printf in main prints
	// 10
}

// Driver Code
int main()
{
	int i = 10;
	fun();
	i = 20;
	printf("%d", i);
	return 0;
}
```
It is not allowed to change main(). Only fun() can be changed. Now, consider the following program using Macro Arguments,

```c
// C Program to demonstrate the use of macro arguments to
// change the output of printf()
#include <stdio.h>

void fun()
{
#define printf(x, y) printf(x, 10);
}

// Driver Code
int main()
{
	int i = 10;
	fun();
	i = 20;
	printf("%d", i);
	return 0;
}
```
**Output**

10























