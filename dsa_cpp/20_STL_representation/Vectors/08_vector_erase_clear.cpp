// Vector is same as a dynamic array with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.

// vector.clear() : used to remove all the elements of the vector container, thus making it's size = 0.
// Time Complexity: O(N) - all elems are destroyed one by one.

// vector.erase(position)/ vector.erase(startingposition,endingposition) : used to remove elements from a container from the specified position or range.
// 


// vector.clear()
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myvector;

	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);
	myvector.push_back(4);
	myvector.push_back(5);

	cout << "Elements: ";
	for(auto it = myvector.begin(); it != myvector.end(); ++it){
		cout << " " << *it;
	}
	cout << endl;

	myvector.clear();

	cout << "Elements: ";
	for(auto it = myvector.begin(); it != myvector.end(); ++it){
		cout << "Elems: " << *it;
	}
	return 0;
}
*/

// vector.erase()

// Syntax:
// 1. vectorname.erase(position)
// 2. vectorname.erase(startingposition, endingposition)

// Removing elements: at particular position (and) within a range
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myvector {1,2,3,4,5};
	vector<int>::iterator it;

	it = myvector.begin();
	myvector.erase(it);

	for(auto it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;

	return 0;
}
*/

// within a range
/*
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> myvector {1,2,3,4,5};
	vector<int>::iterator it1, it2;

	it1 = myvector.begin();
	it2 = myvector.end();
	it2--;it2--;

	myvector.erase(it1, it2);

	for(auto it = myvector.begin(); it != myvector.end(); ++it)
			cout << " " << *it;

	return 0;
}
*/






// Question:
// Given a list of integers, remove all the even elements from the vector and print the vector. 

// Input  :1, 2, 3, 4, 5, 6, 7, 8, 9
// Output :1 3 5 7 9
// Explanation - 2, 4, 6 and 8 which are even are erased from the vector


// Algorithm 
// 1. Run a loop till the size of the vector. 
// 2. Check if the element at each position is divisible by 2, if yes, remove the element and decrement iterator. 
// 3. Print the final vector.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myvector {1,2,3,4,5,6,7,8,9,10};

	for(auto i = myvector.begin(); i != myvector.end(); ++i) {
		if(*i%2 == 0) {
			myvector.erase(i);
			i--;
		}
	}

	for (auto i = myvector.begin(); i != myvector.end(); ++i)
		cout << " " << *i;

	return 0;
}









