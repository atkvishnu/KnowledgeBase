// Vectors are sequence containers that have dynamic size. 
// In other words, vectors are dynamic arrays. 
// Just like arrays, vector elements are placed in contiguous storage location 
// so they can be accessed and traversed using iterators. 
// To traverse the vector we need the position of the first and last element 
// in the vector which we can get through begin() and end() or we can use indexing from 0 to size().

// vector<int> a;                                       // empty vector of ints
// vector<int> b (5, 10);                                // five ints with value 10
// vector<int> c (b.begin(),b.end());                     // iterating through second
// vector<int> d (c);                                   // copy of c


// Some of the member functions of vectors are:

// begin(): Returns an iterator pointing to the first element of the vector. Its time complexity is O(1).
// end(): Returns an iterator pointing to a position which is next to the last element of the vector. Its time complexity is O(1).
// rbegin()/ rend()/ cbegin()/ cend()/ crbegin()/ crend()

// size(): Returns the number of elements in the vector. Its time complexity is O(1).
// empty(): Returns a boolean value, true if the vector is empty and false if the vector is not empty. Its time complexity is O(1).
// resize(): Resizes the vector to the new length which can be less than or greater than the current length. Its time complexity is O(N) where N is the size of the resized vector.
// max_size()/ capacity()/ shrink_to_fit()/ reserve()


// at(): Returns the reference to the element at a particular position (can also be done using ‘[ ]’ operator). Its time complexity is O(1).
// back(): Returns the reference to the last element. Its time complexity is O(1).
// front(): Returns the reference to the first element. Its time complexity is O(1).
// data(): Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
// reference operator[g]: arr[1]

// clear(): Deletes all the elements from the vector and assign an empty vector. Its time complexity is O(N) where N is the size of the vector.
// erase(): Deletes a single element or a range of elements. Its time complexity is O(N + M) where N is the number of the elements erased and M is the number of the elements moved.
// insert(): Inserts new elements into the vector at a particular position. ts time complexity is O(N + M) where N is the number of elements inserted and M is the number of the elements moved .
// pop_back(): Removes the last element from the vector. Its time complexity is O(1).
// push_back(): Inserts a new element at the end of the vector. Its time complexity is O(1).
// emplace(): extends the container by inserting new elements at position
// emplace_back(): used to insert a new element into the vector container, the new element is added to the end of the vector.
// swap(): used to swap contents of one vector with another vector of same type.
// assign(): assigns new value to the vector elements by replacing old ones


#include <iostream>
#include <vector>

using namespace std;

// Traversing a vector
void traverse(vector<int> v)
{
	vector <int>::iterator it;
	// I
	for(it = v.begin(); it!= v.end(); ++it)
		cout << *it << " ";
	cout << endl;
	// II
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	// III
	for(int i = 0;i < v.size();++i)
        cout << v.at(i) << ' ';
   	cout << endl;
}



int main() {
	vector <int> v;
	vector <int>::iterator it;
	v.push_back(5);

	while(v.back() > 0)
		v.push_back(v.back() - 1);

	traverse(v);

	while(!v.empty())
	{
		cout << v.back() << " ";
		v.pop_back();
	}
	cout << endl;
	traverse(v);
	return 0;

}








