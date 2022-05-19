#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(int x : v)
		cout << x << " ";
}

// 1. Initializing by pushing values one by one
/*
int main()
{
	vector<int> vect;
	vect.push_back(10);
	vect.push_back(20);
	vect.push_back(30);

	printVector(vect);

	return 0;
}
*/

// 2. Specifying size and initializing all values
/*
int main()
{
	int n = 3;

	// creating a vector of size n with all vals as 10
	vector<int> vect(n, 10);

	printVector(vect);

	return 0;
}
*/


// 3. Initializing like arrays

int main() {
	
	vector<int> myvector = {10,20,30,40};
	
	printVector(myvector);
	
	return 0;
}



// 4. Initializing from an array
/*
int main()
{
	int arr[] = {10,20,30};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> myvector(arr, arr+n);	// ???

	printVector(myvector);

	return 0;
}
*/

// 5. Initializing from another vector
/*
int main()
{
	vector<int> vect1{10,20,30,50};
	vector<int> vect2(vect1.begin(), vect1.end());

	printVector(vect2);

	return 0;
}
*/



// 6. Initializing all elements with a particular value

// int main()
// {
// 	vector<int> vect(10);

// 	int value = 58;

// 	fill(vect.begin(), vect.end(), value);

// 	printVector(vect);

// 	return 0;
// }