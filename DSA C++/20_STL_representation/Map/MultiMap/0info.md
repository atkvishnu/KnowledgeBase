# std::multimap::multimap








```cpp
// constructing multimaps
#include <iostream>
#include <map>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  std::multimap<char,int> first;

  first.insert(std::pair<char,int>('a',10));
  first.insert(std::pair<char,int>('b',15));
  first.insert(std::pair<char,int>('b',20));
  first.insert(std::pair<char,int>('c',25));

  std::multimap<char,int> second (first.begin(),first.end());

  std::multimap<char,int> third (second);

  std::multimap<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  std::multimap<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as comp

  return 0;
}
```





### Member functions
(constructor) : Construct multimap (public member function )
(destructor) : Multimap destructor (public member function )
operator= : Copy container content (public member function )



### Iterators:
begin: Return iterator to beginning (public member function )
end: Return iterator to end (public member function )
rbegin: Return reverse iterator to reverse beginning (public member function )
rend: Return reverse iterator to reverse end (public member function )
cbegin: Return const_iterator to beginning (public member function )
cend : Return const_iterator to end (public member function )
crbegin: Return const_reverse_iterator to reverse beginning (public member function )
crend : Return const_reverse_iterator to reverse end (public member function )


### Capacity:
empty : Test whether container is empty (public member function )
size : Return container size (public member function )
max_size : Return maximum size (public member function )


### Modifiers:
insert: Insert element (public member function )
erase: Erase elements (public member function )
swap: Swap content (public member function )
clear: Clear content (public member function )
emplace: Construct and insert element (public member function )
emplace_hint:  Construct and insert element with hint (public member function )


### Observers:
key_comp: Return key comparison object (public member function )
value_comp: Return value comparison object (public member function )


### Operations:
find: Get iterator to element (public member function )
count: Count elements with a specific key (public member function )
lower_bound: Return iterator to lower bound (public member function )
upper_bound: Return iterator to upper bound (public member function )
equal_range: Get range of equal elements (public member function )


### Allocator:
get_allocator: Get allocator (public member function )



