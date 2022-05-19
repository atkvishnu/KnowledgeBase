# The C++ Standard Template Library (STL)

The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized. A working knowledge of [template classes](https://www.geeksforgeeks.org/templates-cpp/) is a prerequisite for working with STL.

**STL has four components**

-   Algorithms
-   Containers
-   Functions
-   Iterators


---
---
-----
---
---


## **Algorithms**

The header algorithm defines a collection of functions especially designed to be used on ranges of elements.They act on containers and provide means for various operations for the contents of the containers.

-   Algorithm
    -   [Sorting](https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/)
    -   [Searching](https://www.geeksforgeeks.org/binary-search-algorithms-the-c-standard-template-library-stl/)
    -   [Important STL Algorithms](https://www.geeksforgeeks.org/c-magicians-stl-algorithms/)
    -   [Useful Array algorithms](https://www.geeksforgeeks.org/useful-array-algorithms-in-c-stl/)
    -   [Partition Operations](https://www.geeksforgeeks.org/stdpartition-in-c-stl/)
-   Numeric
    -   [valarray class](https://www.geeksforgeeks.org/std-valarray-class-c/)


### Sort in C++ Standard Template Library (STL)  [std::sort()]
[Sorting](https://www.geeksforgeeks.org/sorting-algorithms/) is one of the most basic functions applied to data. It means arranging the data in a particular fashion, which can be increasing or decreasing. There is a builtin function in C++ STL by the name of sort().   
This function internally uses IntroSort. In more details it is implemented using hybrid of QuickSort, HeapSort and InsertionSort.By default, it uses QuickSort but if QuickSort is doing unfair partitioning and taking more than N*logN time, it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort. 

The prototype for sort is :

```
sort(startaddress, endaddress)

startaddress: the address of the first element of the array
endaddress: the address of the next contiguous location of the last element of the array.

So actually sort() sorts in the range of [startaddress,endaddress)
```


```cpp
// C++ program to sort an array
#include <algorithm>
#include <iostream>

using namespace std;

void show(int a[], int array_size)
{
	for (int i = 0; i < array_size; ++i)
		cout << a[i] << " ";
}

// Driver code
int main()
{
	int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

	// size of the array
	int asize = sizeof(a) / sizeof(a[0]);
	cout << "The array before sorting is : \n";

	// print the array
	show(a, asize);

	// sort the array
	sort(a, a + asize);

	cout << "\n\nThe array after sorting is :\n";

	// print the array after sorting
	show(a, asize);

	return 0;
}
```
**Output**

The array before sorting is : 
1 5 8 9 6 7 3 4 2 0 

The array after sorting is :
0 1 2 3 4 5 6 7 8 9



**How to sort in descending order?**   
`sort()` takes a `third parameter` that is `used to specify the order in which elements are to be sorted`. We can pass the “greater()” function to sort in descending order. This function does a comparison in a way that puts greater elements before.

```cpp
// C++ program to demonstrate descending order sort using
// greater<>().
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr + n, greater<int>());

	cout << "Array after sorting : \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	return 0;
}
```
**Output:**
Array after sorting : 
9 8 7 6 5 4 3 2 1 0


**How to sort in a** **particular order?**   
We can also write our own comparator function and pass it as a third parameter. This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not.   
For eg: In the code below, suppose intervals {6,8} and {1,9} are passed as arguments in the “compareInterval” function(comparator function). Now as i1.first (=6) > i2.first (=1), so our function returns “false”, which tells us that “first” argument should not be placed before “second” argument and so sorting will be done in order like {1,9} first and then {6,8} as next.

```cpp
// A C++ program to demonstrate STL sort() using our own comparator
#include <bits/stdc++.h>
using namespace std;

// An interval has a start time and end time
struct Interval {
	int start, end;
};

// Compares two intervals according to staring times.
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

int main()
{
	Interval arr[] = {{6,8}, {1,9}, {2,4}, {4,7}};
	int n = sizeof(arr) / sizeof(arr[0]);

	// sort the intervals in increasing order of start time
	sort(arr, arr + n, compareInterval);

	cout << "Intervals sorted by start time : \n";
	for (int i = 0; i < n; i++)
		cout << "[" << arr[i].start << "," << arr[i].end << "] ";

	return 0;
}

```

**Output:** 

Intervals sorted by start time : 
[1,9] [2,4] [4,7] [6,8]


```ad-complexity

The **time complexity** of std::sort() is:  
1. Best Case – O(N log N)  
2. Average Case – O(N log N)  
3. Worst Case – O(N log N)

**Space Complexity** – It may use O( log N) auxiliary space.

```

---
---

### Binary Search in C++ Standard Template Library (STL)
[Binary search](https://www.geeksforgeeks.org/binary-search/) is a widely used searching algorithm that requires the array to be sorted before search is applied. The main idea behind this algorithm is to keep dividing the array in half (divide and conquer) until the element is found, or all the elements are exhausted.  
It works by comparing the middle item of the array with our target, if it matches, it returns true otherwise if the middle term is greater than the target, the search is performed in the left sub-array.   
If the middle term is less than the target, the search is performed in the right sub-array.

The prototype for binary search is :

```
binary_search(startaddress, endaddress, valuetofind)

Parameters :
startaddress: the address of the first element of the array.
endaddress: the address of the next contiguous location of the last element of the array.
valuetofind: the target value which we have to search for.

Returns :
true if an element equal to valuetofind is found, else false.
```

```cpp
// CPP program to implement
// Binary Search in
// Standard Template Library (STL)
#include <algorithm>
#include <iostream>

using namespace std;

void show(int a[], int arraysize)
{
	for (int i = 0; i < arraysize; ++i)
		cout << a[i] << ",";
}

int main()
{
	int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int asize = sizeof(a) / sizeof(a[0]);
	cout << "\nThe array is : \n";
	show(a, asize);

	cout << "\n\nLet's say we want to search for ";
	cout << "\n2 in the array So, we first sort the array";
	sort(a, a + asize);
	cout << "\n\nThe array after sorting is : \n";
	show(a, asize);
	cout << "\n\nNow, we do the binary search";
	if (binary_search(a, a + 10, 2))
		cout << "\nElement found in the array";
	else
		cout << "\nElement not found in the array";

	cout << "\n\nNow, say we want to search for 10";
	if (binary_search(a, a + 10, 10))
		cout << "\nElement found in the array";
	else
		cout << "\nElement not found in the array";

	return 0;
}


```

**Output**

The array is : 
1,5,8,9,6,7,3,4,2,0,

Let's say we want to search for 
2 in the array So, we first sort the array

The array after sorting is : 
0,1,2,3,4,5,6,7,8,9,

Now, we do the binary search
Element found in the array

Now, say we want to search for 10
Element not found in the array


-----
### std::bsearch in C++

std::bsearch searches for an element in a sorted array. Finds an element equal to element pointed to by key in an array pointed to by ptr.  
If the array contains several elements that comp would indicate as equal to the element searched for, then it is unspecified which element the function will return as the result.  
```
**Syntax :**

void* bsearch( const void* key, const void* ptr, std::size_t count, std::size_t size, * comp );

**Parameters :**
key     -    element to be found
ptr     -    pointer to the array to examine
count   -    number of element in the array
size    -    size of each element in the array in bytes
comp    -    comparison function which returns ?a negative integer value if the 				first argument is less than the second, a positive integer value if the first argument is greater than the second and zero if the arguments are equal.

**Return value :**
Pointer to the found element or null pointer if the element has not been found.
```

**Implementing the binary predicate comp :**

```cpp
// Binary predicate which returns 0 if numbers found equal
int comp(int* a, int* b)
{

	if (*a < *b)
		return -1;

	else if (*a > *b)
		return 1;

	// elements found equal
	else
		return 0;
}

```

**Implementation**

```cpp
// CPP program to implement
// std::bsearch
#include <bits/stdc++.h>

// Binary predicate
int compare(const void* ap, const void* bp)
{
	// Typecasting
	const int* a = (int*)ap;
	const int* b = (int*)bp;

	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

// Driver code
int main()
{
	// Given array
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	// Size of array
	int ARR_SIZE = sizeof(arr) / sizeof(arr[0]);

	// Element to be found
	int key1 = 4;

	// Calling std::bsearch
	// Typecasting the returned pointer to int
	int* p1 = (int*)std::bsearch(&key1, arr, ARR_SIZE, sizeof(arr[0]), compare);

	// If non-zero value is returned, key is found
	if (p1)
		std::cout << key1 << " found at position " << (p1 - arr) << '\n';
	else
		std::cout << key1 << " not found\n";

	// Element to be found
	int key2 = 9;

	// Calling std::bsearch
	// Typecasting the returned pointer to int
	int* p2 = (int*)std::bsearch(&key2, arr, ARR_SIZE, sizeof(arr[0]), compare);

	// If non-zero value is returned, key is found
	if (p2)
		std::cout << key2 << " found at position " << (p2 - arr) << '\n';
	else
		std::cout << key2 << " not found\n";
}

```
Output:

4 found at position 3
9 not found


**Where to use :**Binary search can be used on sorted data where a key is to be found. It can be used in cases like computing frequency of a key in a sorted list.

**Why Binary Search?**  
Binary search is much more effective than linear search because it halves the search space at each step. This is not significant for our array of length 9. Here, linear search takes at most 9 steps and binary search takes at most 4 steps. But consider an array with 1000 elements, here linear search takes at most 1000 steps, while binary search takes at most 10 steps.  
For 1 billion elements, binary search will find our key in at most 30 steps.


-----------------
--------
--------
---
---

## **Containers**

Containers or container classes store objects and data. There are in total seven standard “first-class” container classes and three container adaptor classes and only seven header files that provide access to these containers or container adaptors.

-   Sequence Containers: implement data structures which can be accessed in a sequential manner.
    -   [vector](https://www.geeksforgeeks.org/vector-in-cpp-stl/)
    -   [list](https://www.geeksforgeeks.org/list-cpp-stl/)
    -   [deque](https://www.geeksforgeeks.org/deque-cpp-stl/)
    -   [arrays](https://www.geeksforgeeks.org/array-class-c/)
    -   [forward_list](https://www.geeksforgeeks.org/forward-list-c-set-1-introduction-important-functions/)( Introduced in C++11)
-   Container Adaptors : provide a different interface for sequential containers.
    -   [queue](https://www.geeksforgeeks.org/queue-cpp-stl/)
    -   [priority_queue](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/)
    -   [stack](https://www.geeksforgeeks.org/stack-in-cpp-stl/)
-   Associative Containers : implement sorted data structures that can be quickly searched (O(log n) complexity).
    -   [set](https://www.geeksforgeeks.org/set-in-cpp-stl/)
    -   [multiset](https://www.geeksforgeeks.org/multiset-in-cpp-stl/)
    -   [map](https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/)
    -   [multimap](https://www.geeksforgeeks.org/multimap-associative-containers-the-c-standard-template-library-stl/)
-   Unordered Associative Containers : implement unordered data structures that can be quickly searched
    
    -   [unordered_set](https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/) (Introduced in C++11)
    -   [unordered_multiset](https://www.geeksforgeeks.org/unordered_multiset-and-its-uses/) (Introduced in C++11)
    -   [unordered_map](https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/) (Introduced in C++11)
    -   [unordered_multimap](https://www.geeksforgeeks.org/unordered_multimap-and-its-application/) (Introduced in C++11)
    
    ![](https://media.geeksforgeeks.org/wp-content/uploads/20191111161536/Screenshot-from-2019-11-11-16-13-18.png)
    
    **Flowchart of Adaptive Containers and Unordered Containers**
    
    ![](https://media.geeksforgeeks.org/wp-content/uploads/20191111161627/Screenshot-from-2019-11-11-16-15-07.png)
    
    **Flowchart of Sequence conatiners and ordered containers**
 
 ---
 
 ### Pair in C++ Standard Template Library (STL)
 
 ```
 ```
 
 The pair container is a simple container defined in `<utility>` header consisting of two data elements or objects. 

-   The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
	
-   Pair is used to combine together two values which may be different in type. Pair provides a way to store two heterogeneous objects as a single unit.
	
-   Pair can be assigned, copied and compared. The array of objects allocated in a map or hash_map are of type ‘pair’ by default in which all the ‘first’ elements are unique keys associated with their ‘second’ value objects.
	
-   To access the elements, we use variable name followed by dot operator followed by the keyword first or second.

**Syntax :**

```
pair (data_type1, data_type2) Pair_name
``` 
 
```cpp
// CPP program to illustrate pair STL
#include <iostream>
#include <utility>
using namespace std;

int main()
{
	pair<int, char> PAIR1;

	PAIR1.first = 100;
	PAIR1.second = 'G';

	cout << PAIR1.first << " ";
	cout << PAIR1.second << endl;

	return 0;
}
```
 **Output**
100 G
 
 **Initializing a pair**

We can also initialize a pair. 

**Syntax :**

```
pair (data_type1, data_type2) Pair_name (value1, value2) ;
``` 
 
 Different ways to initialize pair: 

```
pair  g1;         //default
pair  g2(1, 'a');  //initialized,  different data type
pair  g3(1, 10);   //initialized,  same data type
pair  g4(g3);    //copy of g3
```

Another way to initialize a pair is by using the make_pair() function. 

```
g2 = make_pair(1, 'a');
```
Another valid syntax to declare pair is:

```
g2 = {1, 'a'};
``` 
 
```cpp
// CPP program to illustrate Initializing of pair STL
#include <iostream>
#include <utility>
using namespace std;

int main()
{
	pair<string, double> PAIR2("GeeksForGeeks", 1.23);

	cout << PAIR2.first << " ";
	cout << PAIR2.second << endl;

	return 0;
}
```
 **Output**

GeeksForGeeks 1.23
 
**Note:** If not initialized, the first value of the pair gets automatically initialized.
 
```cpp
// CPP program to illustrate auto-initializing of pair STL
#include <iostream>
#include <utility>

using namespace std;

int main()
{
	pair<int, double> PAIR1;
	pair<string, char> PAIR2;

	// it is initialised to 0
	cout << PAIR1.first;

	// it is initialised to 0
	cout << PAIR1.second;

	cout << " ";

	// // it prints nothing i.e NULL
	cout << PAIR2.first;
	
	// it prints nothing i.e NULL
	cout << PAIR2.second;

	return 0;
}
```
 **Output:** 

00
 
 **Member Functions**

1.  **make_pair()** : This template function allows to create a value pair without writing the types explicitly.   
    Syntax :

```
Pair_name = make_pair (value1,value2);
``` 
 
```cpp
#include <iostream>
#include <utility>
using namespace std;

int main()
{
	pair <int, char> PAIR1 ;
	pair <string, double> PAIR2 ("GeeksForGeeks", 1.23) ;
	pair <string, double> PAIR3 ;

	PAIR1.first = 100;
	PAIR1.second = 'G' ;

	PAIR3 = make_pair ("GeeksForGeeks is Best",4.56);

	cout << PAIR1.first << " " ;
	cout << PAIR1.second << endl ;

	cout << PAIR2.first << " " ;
	cout << PAIR2.second << endl ;

	cout << PAIR3.first << " " ;
	cout << PAIR3.second << endl ;

	return 0;
}
```
 
 **Output:** 

100 G
GeeksForGeeks 1.23
GeeksForGeeks is Best 4.56
 
 
 **operators(=, ==, !=, >=, <=) :** We can use operators with pairs as well. 

-   **using equal(=) :** It assigns new object for a pair object.   
    Syntax :

pair& operator= (const pair& pr);

-   This Assigns pr as the new content for the pair object. The first value is assigned the first value of pr and the second value is assigned the second value of pr .
-   **Comparison (==) operator with pair :** For given two pairs say pair1 and pair2, the comparison operator compares the first value and second value of those two pairs i.e. if pair1.first is equal to pair2.first or not AND if pair1.second is equal to pair2.second or not .
-   **Not equal (!=) operator with pair :** For given two pairs say pair1 and pair2, the != operator compares the first values of those two pairs i.e. if pair1.first is equal to pair2.first or not, if they are equal then it checks the second values of both.
-   **Logical( >=, <= )operators with pair :** For given two pairs say pair1 and pair2, the =, >, can be used with pairs as well. It returns 0 or 1 by only comparing the first value of the pair.  
    For pairs like p1=(1,20) and p2=(1,10)   
    p2<p1 should give 0 (as it compares 1st element only & they are equal so its definitely not less), but that isn’t true. Here the pair compares the second element and if it satisfies then returns 1   
    (this is only the case when the first element gets equal while using a relational operator > or < only, otherwise these operators work as mentioned above)  
     

**swap :** This function swaps the contents of one pair object with the contents of another pair object. The pairs must be of same type.   
Syntax :

pair1.swap(pair2) ;

For two given pairs say pair1 and pair2 of same type, swap function will swap the pair1.first with pair2.first and pair1.second with pair2.second.

```cpp
#include <iostream>
#include<utility>

using namespace std;

int main()
{
	pair<char, int>pair1 = make_pair('A', 1);
	pair<char, int>pair2 = make_pair('B', 2);

	cout << "Before swapping:\n " ;
	cout << "Contents of pair1 = "
		<< pair1.first << " " << pair1.second ;
	cout << "Contents of pair2 = "
		<< pair2.first << " " << pair2.second ;
	pair1.swap(pair2);

	cout << "\nAfter swapping:\n ";
	cout << "Contents of pair1 = "
		<< pair1.first << " " << pair1.second ;
	cout << "Contents of pair2 = "
		<< pair2.first << " " << pair2.second ;

	return 0;
}
```
**Output**: 

Before swapping:
Contents of pair1 = (A, 1)
Contents of pair2 = (B, 2)

After swapping:
Contents of pair1 = (B, 2)
Contents of pair2 = (A, 1)

**tie() :** This function works the same as in [tuples](https://www.geeksforgeeks.org/tuples-in-c/). It creates a tuple of lvalue references to its arguments i.e., to unpack the tuple (or here pair) values into separate variables. Just like in tuples, here are also two variants of tie, with and without “ignore”. “ignore” keyword ignores a particular tuple element from getting unpacked.   
However, tuples can have multiple arguments but pairs only have two arguments. So, in case of pair of pairs, unpacking needs to be explicitly handled.   
**Syntax :** 

tie(int &, int &) = pair1;

```cpp
// CPP code to illustrate tie() in pairs
#include <bits/stdc++.h>
using namespace std;

int main()
{
	pair<int, int> pair1 = { 1, 2 };
	int a, b;
	tie(a, b) = pair1;
	cout << a << " " << b << "\n";

	pair<int, int> pair2 = { 3, 4 };
	tie(a, ignore) = pair2;

	// prints old value of b
	cout << a << " " << b << "\n";

	// Illustrating pair of pairs
	pair<int, pair<int, char> > pair3
				= { 3, { 4, 'a' } };
	int x, y;
	char z;
	
	// tie(x,y,z) = pair3; Gives compilation error
	// tie(x, tie(y,z)) = pair3; Gives compilation error
	// Each pair needs to be explicitly handled
	x = pair3.first;
	tie(y, z) = pair3.second;
	cout << x << " " << y << " " << z << "\n";
	
}
```
**Output :** 

1 2
3 2
3 4 a

```cpp
//CPP program to illustrate pair in STL
#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main()
{
	pair <string, int> g1;
	pair <string, int> g2("Quiz", 3);
	pair <string, int> g3(g2);
	pair <int, int> g4(5, 10);

	g1 = make_pair(string("Geeks"), 1);
	g2.first = ".com";
	g2.second = 2;

	cout << "This is pair g" << g1.second << " with "
		<< "value " << g1.first << "." << endl << endl;

	cout << "This is pair g" << g3.second
		<< " with value " << g3.first
		<< "This pair was initialized as a copy of "
		<< "pair g2" << endl << endl;

	cout << "This is pair g" << g2.second
		<< " with value " << g2.first
		<< "\nThe values of this pair were"
		<< " changed after initialization."
		<< endl << endl;

	cout << "This is pair g4 with values "
		<< g4.first << " and " << g4.second
		<< " made for showing addition. \nThe "
		<< "sum of the values in this pair is "
		<< g4.first+g4.second
		<< "." << endl << endl;

	cout << "We can concatenate the values of"
		<< " the pairs g1, g2 and g3 : "
		<< g1.first + g3.first + g2.first
		<< endl << endl;

	cout << "We can also swap pairs "
		<< "(but type of pairs should be same) : "
		<< endl;
	cout << "Before swapping, " << "g1 has "
		<< g1.first
		<< " and g2 has " << g2.first << endl;
	swap(g1, g2);
	cout << "After swapping, "
		<< "g1 has " << g1.first << " and g2 has "
		<< g2.first;

	return 0;
}
```


**Output:** 

This is pair g1 with value Geeks.
This is pair g3 with value Quiz
This pair was initialized as a copy of pair g2
This is pair g2 with value .com
The values of this pair were changed 
after initialization.
This is pair g4 with values 5 and 10 made 
for showing addition. 
The sum of the values in this pair is 15.
We can concatenate the values of the pairs g1, 
g2 and g3 : GeeksQuiz.com
We can also swap pairs (but type of pairs should be same) : 
Before swapping, g1 has Geeks and g2 has .com
After swapping, g1 has .com and g2 has Geeks

---

### Vector in C++ STL

Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

Certain functions associated with the vector are:  
**Iterators**

1.  [begin()](https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/) – Returns an iterator pointing to the first element in the vector
2.  [end()](https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/) – Returns an iterator pointing to the theoretical element that follows the last element in the vector
3.  [rbegin()](https://www.geeksforgeeks.org/vector-rbegin-and-rend-function-in-c-stl/) – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
4.  [rend()](https://www.geeksforgeeks.org/vector-rbegin-and-rend-function-in-c-stl/) – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
5.  [cbegin()](https://www.geeksforgeeks.org/vector-cbegin-vector-cend-c-stl/) – Returns a constant iterator pointing to the first element in the vector.
6.  [cend()](https://www.geeksforgeeks.org/vector-cbegin-vector-cend-c-stl/) – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
7.  [crbegin()](https://www.geeksforgeeks.org/vectorcrend-vectorcrbegin-examples/) – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
8.  [crend()](https://www.geeksforgeeks.org/vectorcrend-vectorcrbegin-examples/) – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

```cpp
// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> g1;

	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Output of begin and end: ";
	for (auto i = g1.begin(); i != g1.end(); ++i)
		cout << *i << " ";

	cout << "\nOutput of cbegin and cend: ";
	for (auto i = g1.cbegin(); i != g1.cend(); ++i)
		cout << *i << " ";

	cout << "\nOutput of rbegin and rend: ";
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		cout << *ir << " ";

	cout << "\nOutput of crbegin and crend : ";
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
		cout << *ir << " ";

	return 0;
}
```
**Output:**
Output of begin and end: 1 2 3 4 5 
Output of cbegin and cend: 1 2 3 4 5 
Output of rbegin and rend: 5 4 3 2 1 
Output of crbegin and crend : 5 4 3 2 1


**Capacity**
1.  [size()](https://www.geeksforgeeks.org/vectorempty-vectorsize-c-stl/) – Returns the number of elements in the vector.
2.  [max_size()](https://www.geeksforgeeks.org/vector-max_size-function-in-c-stl/) – Returns the maximum number of elements that the vector can hold.
3.  [capacity()](https://www.geeksforgeeks.org/vector-capacity-function-in-c-stl/) – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
4.  [resize(n)](https://www.geeksforgeeks.org/vector-resize-c-stl/) – Resizes the container so that it contains ‘n’ elements.
5.  [empty()](https://www.geeksforgeeks.org/vectorempty-vectorsize-c-stl/) – Returns whether the container is empty.
6.  [shrink_to_fit()](https://www.geeksforgeeks.org/vector-shrink_to_fit-function-in-c-stl/) – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
7.  [reserve()](https://www.geeksforgeeks.org/using-stdvectorreserve-whenever-possible/) – Requests that the vector capacity be at least enough to contain n elements.

```cpp
// C++ program to illustrate the capacity function in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> g1;

	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Size : " << g1.size();
	cout << "\nCapacity : " << g1.capacity();
	cout << "\nMax_Size : " << g1.max_size();

	// resizes the vector size to 4
	g1.resize(4);

	// prints the vector size after resize()
	cout << "\nSize : " << g1.size();

	// checks if the vector is empty or not
	if (g1.empty() == false)
		cout << "\nVector is not empty";
	else
		cout << "\nVector is empty";

	// Shrinks the vector
	g1.shrink_to_fit();
	cout << "\nVector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
		cout << *it << " ";

	return 0;
}
```

**Output:**

Size : 5
Capacity : 8
Max_Size : 4611686018427387903
Size : 4
Vector is not empty
Vector elements are: 1 2 3 4


**Element access:**

1.  [reference operator [g]](https://www.geeksforgeeks.org/vectoroperator-vectoroperator-c-stl/) – Returns a reference to the element at position ‘g’ in the vector
2.  [at(g)](https://www.geeksforgeeks.org/vectorat-vectorswap-c-stl/) – Returns a reference to the element at position ‘g’ in the vector
3.  [front()](https://www.geeksforgeeks.org/vectorfront-vectorback-c-stl/) – Returns a reference to the first element in the vector
4.  [back()](https://www.geeksforgeeks.org/vectorfront-vectorback-c-stl/) – Returns a reference to the last element in the vector
5.  [data()](https://www.geeksforgeeks.org/vector-data-function-in-c-stl/) – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

```cpp
// C++ program to illustrate the element accesser in vector
#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> g1;

	for (int i = 1; i <= 10; i++)
		g1.push_back(i * 10);

	cout << "\nReference operator [g] : g1[2] = " << g1[2];

	cout << "\nat : g1.at(4) = " << g1.at(4);

	cout << "\nfront() : g1.front() = " << g1.front();

	cout << "\nback() : g1.back() = " << g1.back();

	// pointer to the first element
	int* pos = g1.data();

	cout << "\nThe first element is " << *pos;
	return 0;
}
```

**Output:**

Reference operator [g] : g1[2] = 30
at : g1.at(4) = 50
front() : g1.front() = 10
back() : g1.back() = 100
The first element is 10

**Modifiers:**

1.  [assign()](https://www.geeksforgeeks.org/vector-assign-in-c-stl/) – It assigns new value to the vector elements by replacing old ones
2.  [push_back()](https://www.geeksforgeeks.org/vectorpush_back-vectorpop_back-c-stl/) – It push the elements into a vector from the back
3.  [pop_back()](https://www.geeksforgeeks.org/vectorpush_back-vectorpop_back-c-stl/) – It is used to pop or remove elements from a vector from the back.
4.  [insert()](https://www.geeksforgeeks.org/vector-insert-function-in-c-stl/) – It inserts new elements before the element at the specified position
5.  [erase()](https://www.geeksforgeeks.org/vectorclear-vectorerase-c-stl/) – It is used to remove elements from a container from the specified position or range.
6.  [swap()](https://www.geeksforgeeks.org/vectorat-vectorswap-c-stl/) – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
7.  [clear()](https://www.geeksforgeeks.org/vectorclear-vectorerase-c-stl/) – It is used to remove all the elements of the vector container
8.  [emplace()](https://www.geeksforgeeks.org/vector-emplace-function-in-c-stl/) – It extends the container by inserting new element at position
9.  [emplace_back()](https://www.geeksforgeeks.org/vectoremplace_back-c-stl/) – It is used to insert a new element into the vector container, the new element is added to the end of the vector

```cpp
// C++ program to illustrate the Modifiers in vector
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
	// Assign vector
	vector<int> v;

	// fill the array with 10 five times
	v.assign(5, 10);

	cout << "The vector elements are: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	// inserts 15 to the last position
	v.push_back(15);
	int n = v.size();
	cout << "\nThe last element is: " << v[n - 1];

	// removes last element
	v.pop_back();

	// prints the vector
	cout << "\nThe vector elements are: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	// inserts 5 at the beginning
	v.insert(v.begin(), 5);

	cout << "\nThe first element is: " << v[0];

	// removes the first element
	v.erase(v.begin());

	cout << "\nThe first element is: " << v[0];

	// inserts at the beginning
	v.emplace(v.begin(), 5);
	cout << "\nThe first element is: " << v[0];

	// Inserts 20 at the end
	v.emplace_back(20);
	n = v.size();
	cout << "\nThe last element is: " << v[n - 1];

	// erases the vector
	v.clear();
	cout << "\nVector size after erase(): " << v.size();

	// two vector to perform swap
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	cout << "\n\nVector 1: ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\nVector 2: ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	// Swaps v1 and v2
	v1.swap(v2);

	cout << "\nAfter Swap \nVector 1: ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\nVector 2: ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
}
```

**Output:**

The vector elements are: 10 10 10 10 10 
The last element is: 15
The vector elements are: 10 10 10 10 10 
The first element is: 5
The first element is: 10
The first element is: 5
The last element is: 20
Vector size after erase(): 0

Vector 1: 1 2 
Vector 2: 3 4 
After Swap 
Vector 1: 3 4 
Vector 2: 1 2








































 
 
------
-----
--------


## **Functions**

The STL includes classes that overload the function call operator. Instances of such classes are called function objects or functors. Functors allow the working of the associated function to be customized with the help of parameters to be passed.

-   [Functors](https://www.geeksforgeeks.org/functors-in-cpp/)

**Iterators**

As the name suggests, iterators are used for working upon a sequence of values. They are the major feature that allow generality in STL.

-   [Iterators](https://www.geeksforgeeks.org/iterators-c-stl/)

**Utility Library**

Defined in header <utility>.

-   [pair](https://www.geeksforgeeks.org/pair-in-cpp-stl/)










































































































































