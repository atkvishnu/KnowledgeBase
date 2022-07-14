# MultiSet (Multiple-key set)

- Syntax:
```cpp
multiset<datatype> multisetName;
```

- They are associative containers that store multiple elements having equivalent values following a specific order. 
- Multisets are containers that store elements following a specific order, and where multiple elements can have equivalent values.
- In a multiset, the value of an element also identifies it (the value is itself the key, of type T). The value of the elements in a multiset cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.

- Internally, the elements in a multiset are always sorted following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).

- multiset containers are generally slower than unordered_multiset containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.

- Multisets are typically implemented as binary search trees.


Following are the properties of multisets:

- Stores elements in sorted order. 
- It allows the storage of multiple elements. 
- We can erase more than 1 element by giving the start iterator and end iterator. 
- Note: All other properties are similar to the set.

## Container properties
- `Associative`: Elements in associative containers are referenced by their key and not by their absolute position in the container.
- `Ordered`: The elements in the container follow a strict order at all times. All inserted elements are given a position in this order.
- `Set`: The value of an element is also the key used to identify it.
- `Multiple` equivalent keys: Multiple elements in the container can have equivalent keys.
- `Allocator-aware`: The container uses an allocator object to dynamically handle its storage needs.


### Member functions

- `(constructor)` Construct multiset (public member function )
- `(destructor)` Multiset destructor (public member function )
- `operator=` Copy container content (public member function )

#### Iterators:
- `begin` : Return iterator to beginning (public member function )
- `end` : Return iterator to end (public member function )
- `rbegin`:  Return reverse iterator to reverse beginning (public member function )
- `rend` : Return reverse iterator to reverse end (public member function )
- `cbegin`:   Return const_iterator to beginning (public member function )
- `cend` :  Return const_iterator to end (public member function )
- `crbegin`:   Return const_reverse_iterator to reverse beginning (public member function )
- `crend` :  Return const_reverse_iterator to reverse end (public member function )

#### Capacity:
 - `empty` : Test whether container is empty (public member function )
 - `size` : Return container size (public member function )
 - `max_size` : Return maximum size (public member function )

#### CModifiers:
- `insert` :  Insert element (public member function )
- `erase` :  Erase elements (public member function )
- `swap` :  Swap content (public member function )
- `clear` :  Clear content (public member function )
- `emplace` :   Construct and insert element (public member function )
- `emplace_hint` :   Construct and insert element with hint (public member function )

- #### :  CObservers:
- `key_comp` : Return comparison object (public member function )
- `value_comp` : Return comparison object (public member function )

#### COperations:
- `find` : Get iterator to element (public member function )
- `count` : Count elements with a specific key (public member function )
- `lower_bound` : Return iterator to lower bound (public member function )
- `upper_bound` : Return iterator to upper bound (public member function )
- `equal_range` : Get range of equal elements (public member function )

#### CAllocator:
- `get_allocator` : Get allocator (public member function )