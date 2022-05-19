// empty() : is used to check if the vector container is empty or not.

// Syntax: vectorname.empty()
// No parameters are passed.
// Returns: True - empty/ False - not empty

#include <iostream>
#include <vector>
using namespace std;

/*
int main()
{
	vector<int> myvector{};
	
	if(myvector.empty())
		cout << "True";
	else
		cout << "False";

	return 0;
}
*/

// Question: Given a list of integers, find the sum of all integers.
/*
int main()
{
	int sum = 0;
	vector<int> myvector {1,5,2,9,6,3};

	while(!myvector.empty()){
		sum += myvector.back();
		myvector.pop_back();
	}
	cout << sum;
	return 0;
}
*/


// vector::size() - is used to return the size of the vector container
// or the number of elements in the vector container.
// Syntax: vectorname.size()
/*
int main()
{
	vector<int> myvector {1,2,3,4,5,6,7,8,98};
	cout << myvector.size();
	return 0;
}
*/



// *************empty() is preferred over size() because:*************


// 1. empty() function does not use any comparison operators, thus it is more convenient to use
// 2. empty() function is implemented in constant time, regardless of container type, whereas some implementations of size() function require O(n) time complexity such as list::size().



// Question: Given a list of integers, find the sum of all the integers. 
int main()
{
	int sum = 0;
	vector<int> myvector {1,3,5,7,9,11};

	while(myvector.size() > 0) {
		sum += myvector.back();
		myvector.pop_back();
	}
	cout << sum;
	return 0;
}













