// std::multiset::get_allocator

// Get allocator
// Returns a copy of the allocator object associated with the multiset.
// 
// 
// 
// 
// // multiset::get_allocator
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;
  int * p;
  unsigned int i;

  // allocate an array of 5 elements using myset's allocator:
  p=mymultiset.get_allocator().allocate(5);

  // assign some values to array
  for (i=0; i<5; i++) p[i]=(i+1)*10;

  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';

  mymultiset.get_allocator().deallocate(p,5);

  return 0;
}



// The example shows an elaborate way to allocate memory for an array of ints using the same allocator used by the container.
// Output:
// The allocated array contains: 10 20 30 40 50











