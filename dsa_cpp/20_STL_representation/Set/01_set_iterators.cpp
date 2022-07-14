/*
 *
 * They are associative containers that store unique elements following a specific order. 
 * 
 * Following are the properties of sets:
 *
 * - Stores the values in sorted order. 
 * - Stores only unique values. 
 * - Elements can only be inserted or deleted but cannot be modified. 
 * - We can erase more than 1 element by giving the start iterator and end iterator position. 
 * - Traversal using iterators. 
 * - Sets are implemented as Binary Search Tree.
 *
 */



/* Syntax:
 * set<datatype> setname;
 */

// ITERATORS:

// begin(), end()
// begin(): Returns an iterator to the first element of the set. 
// Its time complexity is O(1).
// end(): Returns an iterator pointing to a position which is next to the last element. 
// Its time complexity is O(1).

// rbegin(), rend()
// crbegin(), crend()
// cbegin(), cend()
// lower_bound(const g) - Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.
// upper_bound(const g) - Returns an iterator to the first element that will go after the element ‘g’ in the set.
// find(const g) - Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
// equal_range() - returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k.



#include <iostream>
#include <iterator>
#include <set>

using namespace std;


void printSet_begin_end(set<int> SET)
{
	set<int>::iterator it;
	// begin(), end()
	for(it = SET.begin(); it != SET.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

void printSet_rbegin_rend(set<int> SET)
{
	set<int>::reverse_iterator rit;
	// rbegin(), rend()
	for(rit = SET.rbegin(); rit != SET.rend(); ++rit)
		cout << *rit << " ";
	cout << endl;
}

// crbegin() - returns a constant iterator pointing to the last element in the container.
// crend() - returns a constant iterator pointing to the position just before the first element in the container.
// These iterators cannot be used to modify the elements in the set container.
void printSet_crbegin_crend(set<int> SET){
	for(auto it = SET.crbegin(); it != SET.crend(); ++it)
		cout << *it << " ";
	cout << endl;
}

// cbegin() - returns a constant iterator pointing to the first element in the container.
// cend() - returns a constant iterator pointing to the position past the last element in the container.
// The iterator cannot be used to modify the elements in the set container.
template<class T>
void printSet_cbegin_cend(set<T> SET){
	for(auto it = SET.cbegin(); it != SET.cend(); ++it)
		cout << *it << " ";
	cout << endl;
}


/*
int main()
{
	set<int> set1 = {1,2,3,4,5};
	set<char> set2 = {'a','c','g','z'};
	printSet_begin_end(set1);

	int arr[] = {4,3,2,1,5};
	set<int> s(arr, arr+5);
	printSet_rbegin_rend(s);

	printSet_crbegin_crend(s);
	printSet_cbegin_cend(set2);

	return 0;
}
*/


int main()
{
    // empty set container
	// The std::greater is a functional object which is used for performing comparisons. It is defined as a Function object class for the greater-than inequality comparison.
    // other fns: less<>, equal_to<>, not_equal_to<>, greater_equal<>, less_equal<> 
    set<int, greater<int> > s1;
 
    // insert elements in random order
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);
 
    // only one 50 will be added to the set
    s1.insert(50);
    s1.insert(10);
 
    // printing set s1
    set<int,greater<int>>::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
 
    // assigning the elements from s1 to s2
    set<int> s2(s1.begin(), s1.end());
 
    // print all elements of the set s2
    cout << "\nThe set s2 after assign from s1 is : \n";
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
 
    // remove all elements up to 30 in s2
    cout << "\ns2 after removal of elements less than 30: \n";
    s2.erase(s2.begin(), s2.find(30));
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
 
    // remove element with value 50 in s2
    int num;
    num = s2.erase(50);
    cout << "\ns2.erase(50) : ";
    cout << num << " removed\n";
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
 
    cout << endl;
 
    // lower bound and upper bound for set s1
    cout << "s1.lower_bound(40) : " << *s1.lower_bound(40) << endl;
    cout << "s1.upper_bound(40) : " << *s1.upper_bound(40) << endl;
 
    // lower bound and upper bound for set s2
    cout << "s2.lower_bound(40) : " << *s2.lower_bound(40) << endl;
    cout << "s2.upper_bound(40) : "<< *s2.upper_bound(40) << endl;
 
    return 0;
}









