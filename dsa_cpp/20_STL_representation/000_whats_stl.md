The STL is a very powerful library in C++. 
It is strongly built on the principles of template programming. 
The STL library has three main components : 

1. Containers: These classes define the data structures which are used to contain the data. 
			   The data may be stored in linked lists, or trees or arrays. 
			   The containers provided in the STL are vector, dequeue, list, forward list, set, multiset, map and multimap.

2. Algorithms: The STL library also provides us functions to process the data stored in containers. 
               These functions are provided in the algorithm header file. `#include <algorithm>`

3. Iterators: Iterators are the link between the Containers and the Algorithms. 
              They are the common interface to these classes. 
              An Iterator is an object which can be used to iterator over the elements in a container. 
              Thus iterators are used by Algorithms to modify the containers. 
 
All three components are so designed that they confirm to the principles of data abstraction. 

**Thus any object which holds data and behaves like a container, is a *container*.**
**Similarly, any iterator which sweeps through the elements in a container is an iterator.**

