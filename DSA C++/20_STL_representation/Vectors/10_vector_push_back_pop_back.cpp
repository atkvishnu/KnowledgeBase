// vector.push_back() : used to push elems into a vector from the back.
// The new value is inserted @ end, after the last current and the container size
// is increased by 1.

// Syntax: <vectorname>.push_back(value)


// vector.pop_back() : used to pop/remove elems from a vector from the back.
// value is removed from the vector end, and container size is decreased by 1.
// when value is removed, destructor of the stored object is called, and length of the vector is removed by 1.


// Syntax: <vectorname>.pop_back();

/*
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(auto it = v.begin(); it!=v.end(); it++)
		cout << " " << *it;
	cout << "\n";
}

int main()
{
	vector<int> myvector{1,2,3,4,5};
	myvector.push_back(6);		// push_back

	printVector(myvector);


	myvector.pop_back();		// pop_back

	printVector(myvector);

	return 0;
}
*/



// Question: Count the number of elems in the vector

// Input  : 1, 2, 3, 4, 5, 6
// Output : 6

// Algorithm 
// 1. Add elements to the vector using push_back function 
// 2. Check if the size of the vector is 0, if not, increment the counter variable initialized as 0, and pop the back element. 
// 3. Repeat this step until the size of the vector becomes 0. 
// 4. Print the final value of the variable.  

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count = 0;
	vector<int> myvector;
	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);
	myvector.push_back(4);
	myvector.push_back(5);

	// Method 1: while loop
	// while(!myvector.empty()){
	// 	count+=1;
	// 	myvector.pop_back();
	// }

	// Method 2: for loop
	// for(auto i = myvector.begin(); i != myvector.end(); i++){
	// 	count++;
	// }

	cout << count;

	return 0;
}






