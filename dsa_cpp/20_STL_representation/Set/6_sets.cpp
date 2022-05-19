// Sets are ASSOCIATIVE containers which store only unique values and permit easy look ups. 
// The values in the sets are stored in some specific order (like ascending or descending). 

// Elements can only be inserted or deleted, but cannot be modified. 

// We can access and traverse set elements using iterators just like vectors.


// set<int> s1;                               // Empty Set

// int a[]= {1, 2, 3, 4, 5, 5};

// set<int> s2 (a, a + 6);                    // s2 = {1, 2, 3, 4, 5}
// set<int> s3 (s2);                          // Copy of s2
// set<int> s4 (s3.begin(), s3.end());         // Set created using iterators

/*
 *-------------------------------------------------------------------------
 * ITERATORS:
 * begin(), end()
 * begin(): Returns an iterator to the first element of the set. 
 * Its time complexity is O(1).
 * end(): Returns an iterator pointing to a position which is next to the last element. 
 * Its time complexity is O(1).
 * rbegin(), rend()
 * crbegin(), crend()
 * cbegin(), cend()
 *-------------------------------------------------------------------------
 */


// Some of the member functions of set are:



// clear(): Deletes all the elements in the set and the set will be empty. 
// time complexity is O(N) where N is the size of the set.

// count(const g): Returns 1 or 0 if the element is in the set or not respectively. 
// Returns 1 or 0 based on the element ‘g’ is present in the set or not.
// time complexity is O(logN) where N is the size of the set.

// empty(): Returns true if the set is empty and false if the set has at least one element. 
// time complexity is O(1).


// erase(): Deletes a particular element or a range of elements from the set. 
// time complexity is O(N) where N is the number of element deleted.

// find(const g): Searches for a particular element and returns the iterator pointing to the element if the element is found otherwise it will return the iterator returned by end(). 
// Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
// time complexity is O(logN) where N is the size of the set.

// insert(g): insert a new element "g". 
// time complexity is O(logN) where N is the size of the set.

// size(): Returns the size of the set or the number of elements in the set. 
// time complexity is O(1).

// max_size() : Returns the maximum number of elements that the set can hold.




#include <iostream>
#include <set>

using namespace std;


void printSet(set<int> s)
{
	set <int>::iterator it;
	for(it = s.begin(); it != s.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	set<int> s;
	int A[] = {3,5,2,1,5,6,4,1,1,1};
	for(int i = 0; i < 10; ++i)
		s.insert(A[i]);
	printSet(s);
	return 0;
}
