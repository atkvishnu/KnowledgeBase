# Ceil and Floor functions in C++

In mathematics and computer science, the floor and ceiling functions map a real number to the greatest preceding or the least succeeding integer, respectively.

**floor(x) :** Returns the largest integer that is smaller than or equal to x (i.e : rounds downs the nearest integer).

```
// Here x is the floating point value.
// Returns the largest integer smaller
// than or equal to x
double floor(double x)
```

Examples of Floor:

Input : 2.5
Output : 2

Input : -2.1
Output : -3

Input : 2.9
Output : 2

```cpp
// C++ program to demonstrate floor function
#include <iostream>
#include <cmath>
using namespace std;

// Driver function
int main()
{
	// using floor function which return
	// floor of input value
	cout << "Floor is : " << floor(2.3) << endl;
	cout << "Floor is : " << floor(-2.3) << endl;

	return 0;
}

```

Output:
Floor is : 2
Floor is : -3

**ceil(x) :** Returns the smallest integer that is greater than or equal to x (i.e : rounds up the nearest integer).

```
// Here x is the floating point value.
// Returns the smallest integer greater than or equal to x
double ceiling(double x)
```

Examples of Ceil:

```
Input : 2.5
Output : 3

Input : -2.1
Output : -2

Input : 2.9
Output : 3
```

```cpp
// C++ program to demonstrate ceil function
#include <iostream>
#include <cmath>
using namespace std;

// Driver function
int main()
{
	// using ceil function which return
	// floor of input value
	cout << " Ceil is : " << ceil(2.3) << endl;
	cout << " Ceil is : " << ceil(-2.3) << endl;

	return 0;
}

```

Output:
Ceil is : 3
Ceil is : -2

---

---

---

# Finding Floor and Ceil of a Sorted Array using C++ STL

Given a sorted array, the task is to find the [floor and ceil](https://www.geeksforgeeks.org/ceil-floor-functions-cpp/) of given numbers using STL.

**Examples:**   
**Input:** arr[] = {1, 2, 4, 7, 11, 12, 23, 30, 32},
values[] = { 1, 3, 5, 7, 20, 24 }
**Output:** Floor Values: 1 2 4 7 12 23
Ceil values: 1 4 7 7 23 30

**In case of floor()**: [lower_bound()](https://www.geeksforgeeks.org/lower_bound-in-cpp/) method os STL will be used to find the lower bound. This returns an iterator pointing to the first element in the range [first,last) which does not compare less than the target.

**In case of ceil()**: [upper_bound()](https://www.geeksforgeeks.org/stdupper_bound-in-cpp/) method os STL will be used to find the upper bound. This method returns an iterator pointing to the first element in the range [first,last) which compares greater than a target.  
**Implementation:**

```cpp
// C++ program to find the floor and ceil
// of a given numbers in a sorted array

#include <bits/stdc++.h>
using namespace std;

// Function to find floor of list of values using lower_bound in STL
void printFloor(int arr[], int n1,
				int findFloor[], int n2)
{
	// Find and print the Floor Values
	int low;

	cout << "Floor : ";
	for (int i = 0; i < n2; i++) {

		low = (lower_bound(arr, arr + n1,findFloor[i])- arr);

		if (arr[low] > findFloor[i])
			cout << arr[low - 1] << " ";
		else
			cout << arr[low] << " ";
	}

	cout << endl;
}

// ceil Function to find Ceil of list of values using upper_bound in STL
void printCeil(int arr[], int n1, int findCeil[], int n2)
{
	// Find and print the Ceil Values
	int up;
	cout << "Ceil : ";
	for (int i = 0; i < n2; i++) {
		up = (upper_bound(arr, arr + n1,findCeil[i])- arr);
		if (arr[up] > findCeil[i]
			&& arr[up - 1] == findCeil[i]) {
			cout << arr[up - 1] << " ";
		}
		else
			cout << arr[up] << " ";
	}
	cout << endl;
}

// Driver code
int main()
{
	// Get the sorted array
	int arr[] = { 1, 2, 4, 7, 11, 12, 23, 30, 32 };
	int n1 = sizeof(arr) / sizeof(arr[0]);

	// Print Array
	cout << "Original Array: ";
	for (unsigned int i = 0; i < n1; i++)
		cout << " " << arr[i];
	cout << "\n";

	// Given values whose floor and ceil
	// values are needed to find
	int find[] = { 1, 3, 5, 7, 20, 24 };
	int n2 = sizeof(find) / sizeof(find[0]);

	// Print Values whose floor
	// and ceil is to be found
	cout << "Values: ";
	for (unsigned int i = 0; i < n2; i++)
		cout << find[i] << " ";
	cout << "\n";

	// Print Floor Values
	printFloor(arr, n1, find, n2);

	// Print Ceil Values
	printCeil(arr, n1, find, n2);

	return 0;
}
```

---

# Precision of floating point numbers in C++ (floor(), ceil(), trunc(), round() and setprecision())

Decimal equivalent of 1/3 is 0.33333333333333…. An infinite length number would require infinite memory to store, and we typically have 4 or 8 bytes. Therefore, Floating point numbers store only a certain number of significant digits, and the rest are lost. The **precision** of a floating point number defines how many significant digits it can represent without information loss. When outputting floating point numbers, cout has a default precision of 6 and it truncates anything after that.

Given below are few libraries and methods which are used to provide precision to floating point numbers in C++:

1. **floor():**

Floor rounds off the given value to the closest integer which is less than the given value.

```cpp
// C++ program to demonstrate working of floor()
// in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
	double x =1.411, y =1.500, z =1.711;
	cout << floor(x) << endl;
	cout << floor(y) << endl;
	cout << floor(z) << endl;

	double a =-1.411, b =-1.500, c =-1.611;
	cout << floor(a) << endl;
	cout << floor(b) << endl;
	cout << floor(c) << endl;
	return 0;
}

```

Output:
1
1
1
-2
-2
-2

2. **ceil():**

Ceil rounds off the given value to the closest integer which is more than the given value.

```cpp
// C++ program to demonstrate working of ceil() in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
	double x = 1.411, y = 1.500, z = 1.611;
	cout << ceil(x) << endl;
	cout << ceil(y) << endl;
	cout << ceil(z) << endl;

	double a = -1.411, b = -1.500, c = -1.611;
	cout << ceil(a) << endl;
	cout << ceil(b) << endl;
	cout << ceil(c) << endl;
	return 0;
}

```

Output:

2
2
2
-1
-1
-1

3. **trunc():**

Trunc rounds removes digits after decimal point.

```cpp
// C++ program to demonstrate working of trunc()
// in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
	double x = 1.411, y = 1.500, z = 1.611;
	cout << trunc(x) << endl;
	cout << trunc(y) << endl;
	cout << trunc(z) <<endl;

	double a = -1.411, b = -1.500, c = -1.611;
	cout << trunc(a) <<endl;
	cout << trunc(b) <<endl;
	cout << trunc(c) <<endl;
	return 0;
}

```

Output:

1
1
1
-1
-1
-1

4. **round():**

Rounds given number to the closest integer.

```cpp
// C++ program to demonstrate working of round()
// in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
	double x = 1.411, y = 1.500, z = 1.611;

	cout << round(x) << endl;
	cout << round(y) << endl;
	cout << round(z) << endl;

	double a = -1.411, b = -1.500, c = -1.611;
	cout << round(a) << endl;
	cout << round(b) << endl;
	cout << round(c) << endl;
	return 0;
}

```

Output:

1
2
2
-1
-2
-2

5. **setprecision():**

Setprecision when used along with ‘fixed’ provides precision to floating point numbers correct to decimal numbers mentioned in the brackets of the setprecison.

```cpp
// C++ program to demonstrate working of setprecision()
// in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
	double pi = 3.14159, npi = -3.14159;
	cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
	cout << fixed << setprecision(1) << pi <<" "<<npi<<endl;
	cout << fixed << setprecision(2) << pi <<" "<<npi<<endl;
	cout << fixed << setprecision(3) << pi <<" "<<npi<<endl;
	cout << fixed << setprecision(4) << pi <<" "<<npi<<endl;
	cout << fixed << setprecision(5) << pi <<" "<<npi<<endl;
	cout << fixed << setprecision(6) << pi <<" "<<npi<<endl;
}

```

Output:

3 -3
3.1 -3.1
3.14 -3.14
3.142 -3.142
3.1416 -3.1416
3.14159 -3.14159
3.141590 -3.141590

**Note:** When the value mentioned in the setprecision() exceeds the number of floating point digits in the original number then 0 is appended to floating point digit to match the precision mentioned by the user.

There exists other methods too to provide precision to floating point numbers. The above mentioned are few of the most commonly used methods to provide precision to floating point numbers during competitive coding.

---

---

---

# Const member functions in C++

Like member functions and member function arguments, the objects of a class can also be declared as **const**. an object declared as const cannot be modified and hence, can invoke only const member functions as these functions ensure not to modify the object.   
A const object can be created by prefixing the const keyword to the object declaration. Any attempt to change the data member of const objects results in a compile-time error.   
**Syntax:**

```
const Class_Name Object_name;
```

-   When a function is declared as const, it can be called on any type of object, const object as well as non-const objects.
-   Whenever an object is declared as const, it needs to be initialized at the time of declaration. however, the object initialization while declaring is possible only with the help of constructors.

A function becomes const when the const keyword is used in the function’s declaration. The idea of const functions is not to allow them to modify the object on which they are called. It is recommended the practice to make as many functions const as possible so that accidental changes to objects are avoided.  
Following is a simple example of a const function.

```cpp
#include <iostream>
using namespace std;

class Test {
	int value;

public:
	Test(int v = 0) { value = v; }

	int getValue() const { return value; }
};

int main()
{
	Test t(20);
	cout << t.getValue();
	return 0;
}

```

**Output:**

20

When a function is declared as const, it can be called on any type of object. Non-const functions can only be called by non-const objects.   
For example the following program has compiler errors.

```cpp
#include<iostream>
using namespace std;

class Test {
	int value;
public:
	Test(int v = 0) {value = v;}
	int getValue() {return value;}
};

int main() {
	const Test t;
	cout << t.getValue();
	return 0;
}

```

**Output:**

passing 'const Test' as 'this' argument of 'int
Test::getValue()' discards qualifiers

Let’s look at another example:

```cpp
// Demonstration of constant object, show that constant object can only call const member function

#include<iostream>
using namespace std;
class Demo
{
	int value;
	public:
	Demo(int v = 0) {value = v;}
	void showMessage()
	{
		cout<<"Hello World We are Tushar, "
		"Ramswarup, Nilesh and Subhash Inside"
		" showMessage() Function"<<endl;
	}
	void display()const
	{
		cout<<"Hello world I'm Rancho "
		"Baba Inside display() Function"<<endl;
	}
};
int main()
{
	//Constant object are initialised at the time of declaration using constructor
	const Demo d1;
	//d1.showMessage();Error occurred if uncomment.
	d1.display();
	return(0);
}

```

**OUTPUT :** Hello world I'm Rancho Baba Inside display() Function

---

---

---

# std::unique in C++

**std::unique** is used to remove duplicates of any element present consecutively in a range[first, last). It performs this task for all the sub-groups present in the range having the same element present consecutively.

-   It does not delete all the duplicate elements, but it removes duplicacy by just replacing those elements by the next element present in the sequence which is not duplicate to the current element being replaced. All the elements which are replaced are left in an **unspecified state.**
-   Another interesting feature of this function is that **it does not changes the size of the container** after deleting the elements, it just returns a pointer pointing to the new end of the container, and based upon that we have to resize the container, or remove the garbage elements.

**It can be used in two ways as shown below:**

1. **Comparing elements using ==:**

Syntax:

```
**template
ForwardIterator unique (ForwardIterator first, ForwardIterator last);**

**first:** Forward iterator to the first element in the container.
**last:** forward iterator to the last element in the container.

**Return Value:** It returns an iterator to the element that follows
the last element not removed. The range between first and this iterator includes
all the elements in the sequence that were not
duplicates and hence not removed.
```

```cpp
// C++ program to demonstrate the use of std::unique
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 }, i;

	vector<int>::iterator ip;

	// Using std::unique
	ip = std::unique(v.begin(), v.begin() + 12);
	// Now v becomes {1 3 10 1 3 7 8 * * * * *}
	// * means undefined

	// Resizing the vector so as to remove the undefined terms
	v.resize(std::distance(v.begin(), ip));

	// Displaying the vector after applying std::unique
	for (ip = v.begin(); ip != v.end(); ++ip) {
		cout << *ip << " ";
	}

	return 0;
}
```

Output:
1 3 10 1 3 7 8

Here, in this vector, all the sub-groups having consecutive duplicate elements has been reduced to only one element. Note that it doesnot matter whether the same element is present later on as well, only duplicate elements present consecutively are handled by this function.

2. **By comparing using a pre-defined function:**  
   Syntax:

```
template
	ForwardIterator unique (ForwardIterator first, ForwardIterator last,
                         BinaryPredicate Pred);

Here, first and last are the same as previous case.

**Pred:** Binary function that accepts two elements in the range as argument, and returns a value convertible to bool.
The value returned indicates whether both arguments are considered equivalent
(if true, they are equivalent and one of them is removed).
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.

**Return Value:** It returns an iterator to the element that follows the last element not removed.
The range between first and this iterator includes all the elements in the sequence that were not duplicates and hence not removed.
```

```cpp
// C++ program to demonstrate the use of std::unique
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Defining the BinaryFunction
bool Pred(char a, char b)
{
	// Checking if both the arguments are same and equal to 'G' then only they are considered same and duplicates are removed
	if (a == b && a == 'G') {
		return 1;
	} else {
		return 0;
	}
}
int main()
{
	// Declaring a string
	string s = "You arre vvvisiting GGGGFGGGG";

	// Using std::unique to remove the consecutive G in the word
	auto ip = std::unique(s.begin(), s.end(), Pred);

	// Displaying the corrected string
	cout << string(s.begin(), ip);
	return 0;
}
```

Output:

You arre vvvisiting GFG

1.  Here, we have manipulated the binary function in such a way that only if two G are passed as arguments, then only they will be considered as same, and if any other character is present consecutively, then it will remain unaffected, and will not be removed (like r in arre, v in visiting).

#### **Where str::unique can be used ?**

1.  **Remove all the duplicate elements from a container:** Many of you must have searched for std::unique with a view that it will remove all the duplicate elements from the container, and now you might feel a bit disappointed to know that it removes only the consecutive duplicate elements. But, although, **std::unique** cannot do so as per its definition, but applying a bit of logic, we can make that happen. What we need to do is just sort the array before applying std::unique, such that all equal elements become consecutive, and now we have std::unique to remove all the duplicate consecutive elements.

    So, std::unique can also be used to **remove all the duplicate elements from a container.**

```cpp
// C++ program to demonstrate the use of std::unique
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v = { 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8 };

	vector<int>::iterator ip;

	// Sorting the array
	std::sort(v.begin(), v.end());
	// Now v becomes 1 1 2 2 3 3 3 3 7 7 8 10

	// Using std::unique
	ip = std::unique(v.begin(), v.begin() + 12);
	// Now v becomes {1 2 3 7 8 10 * * * * * *}
	// * means undefined

	// Resizing the vector so as to remove the undefined terms
	v.resize(std::distance(v.begin(), ip));

	// Displaying the vector after applying std::unique
	for (ip = v.begin(); ip != v.end(); ++ip) {
		cout << *ip << " ";
	}

	return 0;
}
```

Output:
1 2 3 7 8 10

**Explanation:** Firstly, we sorted the array such that all the equal duplicate elements become consecutive and now applying std::unique to it such that the duplicacy is removed, and in this way we remove all the duplicate elements from a container, whether consecutive or not.

2.  **Count unique elements :** It can also be used if we want to count the total no. of unique elements in a container.

```cpp
// C++ program to demonstrate the use of std::unique
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 };

	vector<int>::iterator ip;

	int count;
	sort(v.begin(), v.end());

	// Using std::unique and std::distance to count
	// unique elements in a container
	count = std::distance(v.begin(),
						std::unique(v.begin(), v.begin() + 12));

	// Displaying the value of count
	cout << "Total no. of unique elements = " << count;

	return 0;
}
```

Output:

Total no. of unique elements = 5

**Explanation:** As we know that std::unique returns an iterator to what should be the new end of the container after removing duplicate elements, so just counting the total no. of elements from beginning till this new end with the help of std::distance, should give us the total no. of unique elements in the container.

---

---

---
