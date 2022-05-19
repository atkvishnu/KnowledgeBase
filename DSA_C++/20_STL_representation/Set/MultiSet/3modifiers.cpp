// multiset::insert (C++98)
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;
  std::multiset<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; i++) mymultiset.insert(i*10);  // 10 20 30 40 50

  it=mymultiset.insert(25);

  it=mymultiset.insert (it,27);    // max efficiency inserting
  it=mymultiset.insert (it,29);    // max efficiency inserting
  it=mymultiset.insert (it,24);    // no max efficiency inserting (24<29)

  int myints[]= {5,10,15};
  mymultiset.insert (myints,myints+3);

  std::cout << "mymultiset contains:";
  for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;            // myset contains: 5 10 10 15 20 24 25 27 29 30 40 50
  std::cout << '\n';

  return 0;
}



// ---------------------------------------------------------------------
// erasing from multiset
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;
  std::multiset<int>::iterator it;

  // insert some values:
  mymultiset.insert (40);                            // 40
  for (int i=1; i<7; i++) mymultiset.insert(i*10);   // 10 20 30 40 40 50 60

  it=mymultiset.begin();
  it++;                                              //    ^

  mymultiset.erase (it);                             // 10 30 40 40 50 60

  mymultiset.erase (40);                             // 10 30 50 60

  it=mymultiset.find (50);
  mymultiset.erase ( it, mymultiset.end() );         // 10 30

  std::cout << "mymultiset contains:";
  for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
// Output:
// mymultiset contains: 10 30
// ---------------------------------------------------------------------

// swap multisets
#include <iostream>
#include <set>

main ()
{
  int myints[]={19,72,4,36,20,20};
  std::multiset<int> first (myints,myints+3);     // 4,19,72
  std::multiset<int> second (myints+3,myints+6);  // 20,20,36

  first.swap(second);

  std::cout << "first contains:";
  for (std::multiset<int>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (std::multiset<int>::iterator it=second.begin(); it!=second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
// Output:
// first contains: 20 20 36
// second contains: 4 19 72
// ---------------------------------------------------------------------

// multiset::clear
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;

  mymultiset.insert (11);
  mymultiset.insert (42);
  mymultiset.insert (11);

  std::cout << "mymultiset contains:";
  for (std::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mymultiset.clear();
  mymultiset.insert (200);
  mymultiset.insert (100);

  std::cout << "mymultiset contains:";
  for (std::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
// Output:
// mymultiset contains: 11 11 42
// myset contains: 100 200


// ---------------------------------------------------------------------
// Inserts a new element in the multiset. This new element is constructed in place using args as the arguments for its construction.
// multiset::emplace
#include <iostream>
#include <set>
#include <string>

int main ()
{
  std::multiset<std::string> mymultiset;

  mymultiset.emplace("foo");
  mymultiset.emplace("bar");
  mymultiset.emplace("foo");

  std::cout << "mymultiset contains:";
  for (const std::string& x: mymultiset)
    std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}

// Output:
// mymultiset contains: bar foo foo

// ---------------------------------------------------------------------
// multiset::emplace_hint
#include <iostream>
#include <set>
#include <string>

int main ()
{
  std::multiset<std::string> mymultiset;
  auto it = mymultiset.cbegin();

  mymultiset.emplace_hint (it,"apple");
  it = mymultiset.emplace_hint (mymultiset.cend(),"orange");
  it = mymultiset.emplace_hint (it,"melon");
  mymultiset.emplace_hint (it,"melon");

  std::cout << "mymultiset contains:";
  for (const std::string& x: mymultiset)
    std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
// Output:
// mymultiset contains: apple melon melon orange

