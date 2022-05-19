// When we pass a array to a fn., a pointer is actually passed.

// When we pass a vector to a fn., we have 2 ways:
// 1. Pass by value
// 2. Pass by reference.

// When a vector is passed to a fn., a copy of the vector is created.
// This new copy of the vector is then used in the fn., any changes made to the vector in the fn., doesn't effect the original vector.

// Passing by value keeps the original vector unchanged and doesn’t modify the 
// original values of the vector. However, the passing by value might also 
// take a lot of time in cases of large vectors. 
// So, it is a good idea to pass by reference.

// Note: If we do not want a function to modify a vector, we can pass it as a `const` reference also.

// 1. Pass by value
// changes made inside the function are not reflected outside because the function has a copy.
/*
#include <bits/stdc++.h>
using namespace std;

// the vect here is a copy of vect in main()
void func(vector<int> vect) {vect.push_back(30);}

int main()
{
	vector<int> vect;
	vect.push_back(10);
	vect.push_back(20);

	func(vect);

	// vect remains unchanged after fn. call
	for(int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";

	return 0;
}
*/

// 2. Pass by reference
/*
#include <bits/stdc++.h>

using namespace std;

// vect is passed as a reference and changes made here reflect in main()
void func(vector<int> &vect) {vect.push_back(30);}

int main()
{
	vector<int> vect;
	vect.push_back(10);
	vect.push_back(20);

	func(vect);

	for (int i = 0; i < vect.size(); ++i)
		cout << vect[i] << " ";

	return 0;
}
*/
// Passing by reference saves a lot of time and makes the implementation of the code faster.


// Note: If we do not want a function to modify a vector, 
// we can pass it as a `const` reference also.

#include <bits/stdc++.h>
using namespace std;

// vect is passed as a reference and changes made here reflect in main()
void func(const vector<int> &vect) {
	// Uncommenting this line result in error
	// vect.push_back(30);

	for (int i = 0; i < vect.size(); ++i)
		cout << vect[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> vect;
	vect.push_back(10);
	vect.push_back(20);

	func(vect);

	for (int i = 0; i < vect.size(); ++i)
		cout << vect[i] << " ";

	return 0;
}











