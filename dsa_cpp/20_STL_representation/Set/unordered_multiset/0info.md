Unordered_multiset: It is an associative container that contains a set of non-unique elements in unsorted order. Following are the properties of Unordered_multiset: 

Elements can be stored in any order. 
Duplicate elements can be stored. 
Hash-table used to store elements. 
We can erase only the element for which the iterator position is given. 
Note: All other properties are similar to the set. 

Syntax:

unordered_multiset<datatype> multisetName;

The following example demonstrates the application of Unordered multiset.


```cpp
// CPP program to demonstrate insert and
// delete in unordered_multiset
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // unordered_multiset declare
    unordered_multiset<int> s;
  
    // Elements added to set
    s.insert(12);
    s.insert(10);
    s.insert(2);
    // duplicate added
    s.insert(10);
    s.insert(90);
    s.insert(85);
    s.insert(45);
  
    // Iterator declared to traverse
    // set elements
    unordered_multiset<int>::iterator it, it1;
    cout << "Unordered-Multiset elements after sort:\n";
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << ' ';
    cout << '\n';
  
    it1 = s.find(10);
  
    // element 10 trained
    s.erase(it1);
  
    cout << "Unordered-Multiset Elements after "
            "erase:\n";
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << ' ';
  
    return 0;
}
```

<!-- Output
Unordered-Multiset elements after sort:
45 10 10 12 2 90 85 
Unordered-Multiset Elements after erase:
45 10 12 2 90 85 
 -->




## Difference between `set`, `multiset`, `unordered_set`, `unordered_multiset`: 

- In simple words, set is a container that stores sorted and unique elements. If unordered is added means elements are not sorted.
- If multiset is added means duplicate elements storage is allowed.







