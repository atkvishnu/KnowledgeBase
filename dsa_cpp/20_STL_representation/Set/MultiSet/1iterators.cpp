// Iterators

// multiset::begin/end
#include <iostream>
#include <set>

int main ()
{
  int myints[] = {42,71,71,71,12};
  std::multiset<int> mymultiset (myints,myints+5);

  std::multiset<int>::iterator it;

// begin() and end()
  std::cout << "mymultiset contains:";
  for (std::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

//-----------------------------------------------
// rbegin & rend
  int myints[] = {77,16,2,30,30};
  std::multiset<int> mymultiset (myints,myints+5);

  std::cout << "mymultiset contains:";
  for (std::multiset<int>::reverse_iterator rit=mymultiset.rbegin(); rit!=mymultiset.rend(); ++rit)
    std::cout << ' ' << *rit;

//-----------------------------------------------
// cbegin & cend
	std::multiset<int> mymultiset = {10,20,30,20,10};

	std::cout << "mymultiset contains:";
	for (auto it=mymultiset.cbegin(); it != mymultiset.cend(); ++it)
			std::cout << ' ' << *it;

	std::cout << '\n';

//-----------------------------------------------
// crbegin & crend

  std::multiset<int> mymultiset = {10,20,30,20,10};

  std::cout << "mymultiset backwards:";
  for (auto rit=mymultiset.crbegin(); rit != mymultiset.crend(); ++rit)
    std::cout << ' ' << *rit;

  std::cout << '\n';



//-----------------------------------------------


  return 0;
}