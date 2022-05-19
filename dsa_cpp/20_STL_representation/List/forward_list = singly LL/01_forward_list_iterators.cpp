// ITERATORS: 
// begin(), end(),    cbegin(), cend()      , before_begin(), cbefore_begin()
// cbegin, cend, cbefore_begin -> gives us constant iterators


// forward_list::cbefore_begin()

// returns a constant random access iterator which points to the position before the first element of the forward_list. 
// The iterator obtained by this function can be used to iterate in the container but cannot be used to modify the content of the object to which it is pointing, even if the object itself is not constant.

#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
    // initialising the forward list
    forward_list<int> fl = { 20, 30, 40, 50 };
  
    // performing cbefore_begin function
    auto it = fl.cbefore_begin();
  
    // inserting element before the first element
    fl.insert_after(it, 10);
  
    cout << "Element of the list are:" << endl;
  
    // loop to print the elements of the list
    for (auto it = fl.begin(); it != fl.end(); ++it)
        cout << *it << " ";
  
    return 0;
}
*/

// forward_list::before_begin()


// returns an iterator that points to the position before the first element of the forward_list. 
// Forward list in STL is a singly linked list implementation. 
// This function comes under the <forward_list> header file.


int main()
{
    // initialising the forward list
    forward_list<int> fl = { 20, 30, 40, 50 };
 
    // performing before_begin function
    auto it = fl.before_begin();
 
    // inserting element before the first element
    fl.insert_after(it, 10);
 
    cout << "Element of the list are:" << endl;
 
    // loop to print the elements of the list
    for (auto it = fl.begin(); it != fl.end(); ++it)
        cout << *it << " ";
 
    return 0;
}









