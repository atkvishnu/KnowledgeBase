// Capacity

// multiset::empty
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;

  mymultiset.insert(10);
  mymultiset.insert(20);
  mymultiset.insert(10);

  std::cout << "mymultiset contains:";
  while (!mymultiset.empty())
  {
     std::cout << ' ' << *mymultiset.begin();		
     mymultiset.erase(mymultiset.begin());
  }
  std::cout << '\n';
  return 0;
}
// Output:
// mymultiset contains: 10 10 20

// multiset::size
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.insert(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (5);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.erase (5);
  std::cout << "3. size: " << myints.size() << '\n';

  return 0;
}
// Output:
// 0. size: 0
// 1. size: 10
// 2. size: 11
// 3. size: 9