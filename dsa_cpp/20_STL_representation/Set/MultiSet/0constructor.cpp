// constructing multisets
#include <iostream>
#include <set>

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  std::multiset<int> first;                          // empty multiset of ints

  int myints[]= {10,20,30,20,20};
  std::multiset<int> second (myints,myints+5);       // pointers used as iterators

  std::multiset<int> third (second);                 // a copy of second

  std::multiset<int> fourth (second.begin(), second.end());  // iterator ctor.

  std::multiset<int,classcomp> fifth;                // class as Compare

  bool(*fn_pt)(int,int) = fncomp;
  std::multiset<int,bool(*)(int,int)> sixth (fn_pt); // function pointer as Compare

  return 0;
}




// std::multiset::operator=

// assignment operator with multisets
#include <iostream>
#include <set>

int main ()
{
  int myints[]={ 19,81,36,36,19 };
  std::multiset<int> first (myints,myints+5);   // multiset with 5 ints
  std::multiset<int> second;                    // empty multiset

  second=first;                                 // now second contains the 5 ints
  first=std::multiset<int>();                   // and first is empty

  std::cout << "Size of first: " << first.size() << '\n';
  std::cout << "Size of second: " << second.size() << '\n';
  return 0;
}

// Output:
// Size of first: 0
// Size of second: 5






// // CPP program to demonstrate insert and
// // delete in set
// #include <bits/stdc++.h>
// using namespace std;

// // Driver Code
// int main()
// {
//   // multiset declare
//   multiset<int> s;

//   // Elements added to set
//   s.insert(12);
//   s.insert(10);
//   s.insert(2);
//   // duplicate added
//   s.insert(10);
//   s.insert(90);
//   s.insert(85);
//   s.insert(45);

//   // Iterator declared to traverse
//   // set elements
//   multiset<int>::iterator it, it1, it2;
//   cout << "Multiset elements after sort\n";
//   for (it = s.begin(); it != s.end(); it++)
//     cout << *it << ' ';
//   cout << '\n';

//   it1 = s.find(10);
//   it2 = s.find(90);

//   // elements from 10 to elements before 90
//   // erased
//   s.erase(it1, it2);

//   cout << "Multiset Elements after erase:\n";
//   for (it = s.begin(); it != s.end(); it++)
//     cout << *it << ' ';

//   return 0;
// }
// 
// Output:
// Multiset elements after sort
// 2 10 10 12 45 85 90 
// Multiset Elements after erase:
// 2 90 