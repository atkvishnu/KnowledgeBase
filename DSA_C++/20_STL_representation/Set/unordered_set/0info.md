They are associative containers that store unique elements in no particular order. Following are the properties of Unordered_sets: 

Elements can be stored in any order. ( no sorted order ) 
Stores only unique values. 
Hash-table used to store elements. 
We can erase only the element for which the iterator position is given. 
Note: All other properties are similar to the set. 

Syntax:

unordered_set<datatype> setname;


The following example demonstrates the application of Unordered set.

```cpp
// CPP program to demonstrate insert and
// delete in unordered_set
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // unordered_set declare
    unordered_set<int> s;
  
    // Elements added to set
    s.insert(12);
    s.insert(10);
    s.insert(2);
    // duplicate added
    s.insert(10);
    s.insert(90);
    s.insert(85);
    s.insert(45);
    s.insert(12);
    s.insert(70);
  
    // Iterator declared to traverse
    // set elements
    unordered_set<int>::iterator it, it1;
    cout << "Unordered_set elements after sort:\n";
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << ' ';
    cout << '\n';
  
    it1 = s.find(10);
  
    // element 10 erased
    s.erase(it1);
    cout << "Unoredered_set Elements after erase:\n";
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << ' ';
  
    return 0;
}
```


<!-- Output
Unordered_set elements after sort:
10 45 12 70 2 90 85 
Unoredered_set Elements after erase:
45 12 70 2 90 85 
 -->





### Member functions
`(constructor)` :Construct unordered_set (public member function )

```cpp
// constructing unordered_sets
#include <iostream>
#include <string>
#include <unordered_set>

template<class T>
T cmerge (T a, T b) { T t(a); t.insert(b.begin(),b.end()); return t; }

int main ()
{
  std::unordered_set<std::string> first;                                // empty
  std::unordered_set<std::string> second ( {"red","green","blue"} );    // init list
  std::unordered_set<std::string> third ( {"orange","pink","yellow"} ); // init list
  std::unordered_set<std::string> fourth ( second );                    // copy
  std::unordered_set<std::string> fifth ( cmerge(third,fourth) );       // move
  std::unordered_set<std::string> sixth ( fifth.begin(), fifth.end() ); // range

  std::cout << "sixth contains:";
  for (const std::string& x: sixth) std::cout << " " << x;
  std::cout << std::endl;

  return 0;
}
```
<!-- Possible output:
sixth contains: pink yellow red green orange blue
 -->

`(destructor)` :Destroy unordered set (public member function)
`operator=` :Assign content (public member function )

### Capacity
`empty`: Test whether container is empty (public member function)
`size`: Return container size (public member function)
`max_size`: Return maximum size (public member function)

### Iterators
`begin`: Return iterator to beginning (public member type)
`end`: Return iterator to end (public member type)
`cbegin`: Return const_iterator to beginning (public member function)
`cend`: Return const_iterator to end (public member function)

### Element lookup
`find`: Get iterator to element (public member function)
`count`: Count elements with a specific key (public member function)
`equal_range`: Get range of elements with a specific key (public member function)

### Modifiers
`emplace`: Construct and insert element (public member function )
`emplace_hint`: Construct and insert element with hint (public member function)
`insert`: Insert elements (public member function )
`erase`: Erase elements (public member function )
`clear`: Clear content (public member function)
`swap`: Swap content (public member function)

### Buckets
`bucket_count`: Return number of buckets (public member function)
`max_bucket_count`: Return maximum number of buckets (public member function)
`bucket_size`: Return bucket size (public member type)
`bucket`: Locate element's bucket (public member function)

### Hash policy
`load_factor`: Return load factor (public member function)
`max_load_factor`: Get or set maximum load factor (public member function)
`rehash`: Set number of buckets (public member function )
`reserve`: Request a capacity change (public member function)

### Observers
`hash_function`: Get hash function (public member type )
`key_eq`: Get key equivalence predicate (public member type)
`get_allocator`: Get allocator (public member function)


### Non-member function overloads
`operators (unordered_set)`: Relational operators for unordered_set (function template )
`swap (unordered_set)`: Exchanges contents of two unordered_set containers (function template )




