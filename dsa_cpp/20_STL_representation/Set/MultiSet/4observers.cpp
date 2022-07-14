/*
 * Observers:
 - key_comp : Return comparison object (public member function )
 - value_comp : Return comparison object (public member function )
 */

// std::multiset::key_comp
// key_compare key_comp() const;
// Return comparison object
// Returns a copy of the comparison object used by the container.

// By default, this is a less object, which returns the same as operator<.


// This object determines the order of the elements in the container: it is a function pointer or a function object that takes two arguments of the same type as the container elements, and returns true if the first argument is considered to go before the second in the strict weak ordering it defines, and false otherwise.

// Two elements of a multiset are considered equivalent if key_comp returns false reflexively (i.e., no matter the order in which the elements are passed as arguments).

// In multiset containers, the keys to sort the elements are the values themselves, therefore key_comp and its sibling member function value_comp are equivalent.


// multiset::key_comp
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;

  for (int i=0; i<5; i++) mymultiset.insert(i);

  std::multiset<int>::key_compare mycomp = mymultiset.key_comp();

  std::cout << "mymultiset contains:";

  int highest = *mymultiset.rbegin();

  std::multiset<int>::iterator it = mymultiset.begin();
  do {
    std::cout << ' ' << *it;
  } while ( mycomp(*it++,highest) );

  std::cout << '\n';

  return 0;
}
// Output:
// mymultiset contains: 0 1 2 3 4
// 
// ----------------------------------------------------

/*
 std::multiset::value_comp

Return comparison object
Returns a copy of the comparison object used by the container.

By default, this is a less object, which returns the same as operator<.

This object determines the order of the elements in the container: it is a function pointer or a function object that takes two arguments of the same type as the container elements, and returns true if the first argument is considered to go before the second in the strict weak ordering it defines, and false otherwise.

Two elements of a multiset are considered equivalent if value_comp returns false reflexively (i.e., no matter the order in which the elements are passed as arguments).

In multiset containers, the keys to sort the elements are the values themselves, therefore value_comp and its sibling member function key_comp are equivalent.
 */
// multiset::value_comp
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;

  std::multiset<int>::value_compare mycomp = mymultiset.value_comp();

  for (int i=0; i<7; i++) mymultiset.insert(i);

  std::cout << "mymultiset contains:";

  int highest = *mymultiset.rbegin();
  std::multiset<int>::iterator it = mymultiset.begin();
  do {
    std::cout << ' ' << *it;
  } while ( mycomp(*it++,highest) );

  std::cout << '\n';

  return 0;
}

// Output:
// mymultiset contains: 0 1 2 3 4 5 6
