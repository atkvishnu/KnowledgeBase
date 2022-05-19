// std::multiset::find

// Searches the container for an element equivalent to val and returns an iterator to it if found, otherwise it returns an iterator to multiset::end.

// Notice that this function returns an iterator to a single element (of the possibly multiple equivalent elements). To obtain the entire range of equivalent elements, see multiset::equal_range.

// Two elements of a multiset are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the elements are passed as arguments).


// multiset::find
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;
  std::multiset<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; i++) mymultiset.insert(i*10);   // 10 20 30 40 50

  it=mymultiset.find(20);
  mymultiset.erase (it);
  mymultiset.erase (mymultiset.find(40));

  std::cout << "mymultiset contains:";
  for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

// Output:
// mymultiset contains: 10 30 50

//----------------------------------------------------


// std::multiset::count

// Count elements with a specific key
// Searches the container for elements equivalent to val and returns the number of matches.

// Two elements of a multiset are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the elements are passed as arguments).


// multiset::count
#include <iostream>
#include <set>

int main ()
{
  int myints[]={10,73,12,22,73,73,12};
  std::multiset<int> mymultiset (myints,myints+7);

  std::cout << "73 appears " << mymultiset.count(73) << " times in mymultiset.\n";

  return 0;
}
// Output:
// 73 appears 3 times in mymultiset.


//----------------------------------------------------


// lower_bound && upper_bound

// multiset::lower_bound/upper_bound
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;
  std::multiset<int>::iterator itlow,itup;

  for (int i=1; i<8; i++) mymultiset.insert(i*10); // 10 20 30 40 50 60 70

  itlow = mymultiset.lower_bound (30);             //       ^
  itup = mymultiset.upper_bound (40);              //             ^

  mymultiset.erase(itlow,itup);                    // 10 20 50 60 70

  std::cout << "mymultiset contains:";
  for (std::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}


// Notice that lower_bound(30) returns an iterator to 30, whereas upper_bound(40) returns an iterator to 50.
// mymultiset contains: 10 20 50 60 70

//----------------------------------------------------

// std::multiset::equal_range
// 
// Get range of equal elements
// Returns the bounds of a range that includes all the elements in the container that are equivalent to val.

// If no matches are found, the range returned has a length of zero, with both iterators pointing to the first element that is considered to go after val according to the container's internal comparison object (key_comp).

// Two elements of a multiset are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the elements are passed as arguments).


// multiset::equal_elements
#include <iostream>
#include <set>

typedef std::multiset<int>::iterator It;  // aliasing the iterator type used

int main ()
{
  int myints[]= {77,30,16,2,30,30};
  std::multiset<int> mymultiset (myints, myints+6);  // 2 16 30 30 30 77

  std::pair<It,It> ret = mymultiset.equal_range(30); //      ^        ^

  mymultiset.erase(ret.first,ret.second);

  std::cout << "mymultiset contains:";
  for (It it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

// multiset contains: 2 16 77















