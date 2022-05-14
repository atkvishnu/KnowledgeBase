// front(): fetches the first element of a vector container
// Syntax: vectorname.front();
// Returns: Direct reference to the first element of the vector container.

#include <iostream>
#include <vector>
using namespace std;

/*
int main()
{
	vector<int> myvector {10,2,6,4,8};

	// addresses
	// cout << &myvector[0] << endl;
	// cout << &myvector.front();
	cout << myvector.front();

	return 0;
}
*/




// vector::back() : fetches the last element of a vector container.
// Syntax: vactorname.back();
/*
int main()
{
	vector<int> myvector {10,2,6,4,8};

	// addresses
	// cout << &myvector[0] << endl;
	// cout << &myvector.front();
	cout << myvector.back();

	return 0;
}
*/









// Difference between front(), back() and begin, end() function

// begin() and end() function return an iterator(like a pointer) 
// initialized to the first or the last element of the container 
// that can be used to iterate through the collection, 
// while front() and back() function just return a reference to the 
// first or the last element of the container.





// Question: Given an empty vector of integers, add numbers to the 
// vector, then print the difference between the first and the last 
// element.

int main()
{
	vector<int> myvector {};

	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);
	myvector.push_back(4);
	myvector.push_back(5);
	myvector.push_back(6);

	cout << myvector.front() - myvector.back();


	return 0;
}






















