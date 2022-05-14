// Any object which holds data and behaves like a container, is a container. 
// Similarly, any iterator which sweeps through the elements in a container is an iterator.


// If an iterator can be used to access elements of a data container, then what about streams?

// In keeping with the design, Streams too are data containers and so C++ provides us with iterators to iterate over the elements present in any stream. 
// These iterators are called Stream Iterators.

// To use these iterators the iterator header file must be included. #include<iterator>


// Stream iterators are either input stream iterator or output stream iterator.
// The classes for these iterators are istream_iterator and ostream_iterator. 
// These iterators behave like input iterators and output iterators respectively . 




// istream_iterator

// Class Definition for istream_iterator 

// namespace std {
//     template < typename T, typename charT=char, typename traits=char_traits <charT> >
//     class istream_iterator;
// }

// Syntax : 
// istream_iterator<T>(stream)
// T:      Template parameter for specifying type of data
// stream: The object representing the stream
// ostream_iterator<T>(stream, delim).
// stream: The object representing the stream.
// T:      Template Parameter for data type in the stream
// delim:  An optional char sequence that is used to separate the data items while displaying them.

// Note :  
// Using an iterator we can only access elements of one type only.
// istream_iterator has a special state end of stream iterator which is acquired when the end of the stream is reached or when an input operation fails. The end of stream iterator is returned by the default constructor.
// ostream_iterator

// Class Definition for ostream_iterator  

// namespace std {
//     template < typename T, typename charT=char, typename traits=char_traits <charT> >
//     class ostream_iterator;
// }

// Syntax :  
// OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result);

// first: Input Iterator to the first element in source from where elements need to be copied.
// last:  Input Iterator to the last element in source till where elements need to be copied.
// result: Output iterator to the first element in the destination container to where elements will copied.

// Return Value: Iterator pointing to the last element that was copied to the destination.
// The second and third template arguments have a default values assigned to them. We only need to specify the first template parameter which specifies the type of data present in the stream i.e whether the stream contains integers, floats or strings. 

// Examples :  
// istream_iterator cin_it(cin) is an iterator for the stream cin.
// ostream_iterator cout_it(cout, " ") is an iterator for the stream cout.
// ostream_iterator cout_it(cout) is an iterator for stream cout, with no delimiter.


//  Importance of Stream Iterators

// The advantage of stream iterators is that they provide a common interface to access elements in I/O stream, file streams and also other stream to external physical devices. 

// 1. Once an iterator to the respective stream has been obtained the code that follows is nearly same form all types of streams.
// 2. Thus tasks like reading from an input stream and reading from another external stream become similar.
// 3. Stream Iterators allow us access to all the powerful STL algorithms like for_each, replace_if which take an input range to operate on. A particularly useful function is the copy() function. This function is used to copy the elements from one container to another.
// 4. Using the copy() function, we can easily transfer data from a stream to a container and vice-versa. Here are a few example programs to demonstrate working with stream iterators.


/*
// Read a bunch of integers from the input stream and print them to output stream
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	// get input stream and end of stream iterators
	istream_iterator<int> cin_it(cin);
	istream_iterator<int> eos;

	// get output stream iterators
	ostream_iterator<int> cout_it(cout, " ");

	// we have both i/p and o/p iterators, now we can treat them as containers.
	// using copy() fn. we transfer data from one container to another.
	// Copy elems. from i/p to o/p using copy() fn.
	copy(cin_it, eos, cout_it);

	return 0;
}
// Input: 1 2 3 4 5 
// Output: 1 2 3 4 5
*/

/*
// Read a bunch of strings from a file sort them lexicographically and print them to output stream
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Define a vector to store the strings received from input
	vector<string> strings_v;

	// Define the filestream object used to read data from file
	ifstream fin("input.txt");

	// Get i/p stream and end of stream iterators
	istream_iterator<string> fin_it(fin);
	istream_iterator<string> eos;

	// Get o/p stream iterators
	ostream_iterator<string> cout_it(cout, " ");

	// Copy elems. from i/p to vector using copy() fn.
	copy(fin_it, eos, back_inserter(strings_v));

	// sort the vector
	sort(strings_v.begin(), strings_v.end());

	// copy elems. from vector to output
	copy(strings_v.begin(), strings_v.end(), cout_it);

	return 0;
}
// Contents of File "input_file.txt": quick brown fox jumps over the lazy dog
// Output: brown dog fox jumps lazy over quick the 
*/


// Read a bunch of integers from the stream print the sorted order of even integers only
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
using namespace std;
int main()
{
	// Define a vector to store the even integers received from input
    vector<int> vi;

// Get input stream and end of stream iterators
    istream_iterator<int> cin_it(cin);
    istream_iterator<int> eos;
 
    // Get output stream iterators
    ostream_iterator<int> cout_it(cout, " ");
 
    // Copy even integer elements from input to vector using for_each function
    for_each(cin_it, eos, [&](int a) {
        if (a % 2 == 0) {
            // if a is even push it to vector
            vi.push_back(a);
        }
    });
 
    // Sort the vector
    sort(vi.begin(), vi.end());
 
    // Copy elements from vector to output
    copy(vi.begin(), vi.end(), cout_it);

	return 0;
}
// Input: 1 4 3 2 6 8 31 52 
// Output: 2 4 6 8 52 


























































