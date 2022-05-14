// size() - Returns the number of elements in the set.
// max_size() - Returns the maximum number of elements that the set can hold.
// empty() - Returns whether the set is empty.

// insert(const g) - Adds a new element ‘g’ to the set.
// iterator insert(iterator position, const g) - Adds a new element ‘g’ at the position pointed by the iterator.

// erase(iterator position) - Removes the element at the position pointed by the iterator.
// erase(const g) - Removes the value ‘g’ from the set.

// clear() - Removes all the elements from the set.

// key_comp() / value_comp() - Returns the object that determines how the elements in the set are ordered (‘<‘ by default).

// find(const g) - Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.

// count(const g) - Returns 1 or 0 based on the element ‘g’ is present in the set or not.

// lower_bound(const g) - Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.
// upper_bound(const g) - Returns an iterator to the first element that will go after the element ‘g’ in the set.

// equal_range() - returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k.

// emplace() - insert a new element into the set container, only if the element to be inserted is unique and does not already exist in the set.
// emplace_hint() - Returns an iterator pointing to the position where the insertion is done. If the element passed in the parameter already exists, then it returns an iterator pointing to the position where the existing element is.

// swap() - exchange the contents of two sets but the sets must be of the same type, although sizes may differ.

// operator = : '=' is an operator in C++ STL which copies (or moves) a set to another set and set::operator= is the corresponding operator function.

// get_allocator() - Returns the copy of the allocator object associated with the set.








