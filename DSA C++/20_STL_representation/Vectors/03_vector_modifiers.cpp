// modifiers in vectors

// assign(), push_back(), pull_back(), insert(), erase(), swap(), clear(),
// emplace(), emplace_back()


#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int> v)
{
	cout << "The vector elements are: ";
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}


int main()
{
	vector<int> v;

	// fill the vector with 10 five times
	v.assign(5,10);

	// cout << "The vector elements are: ";
	// for(int i = 0; i < v.size(); i++)
	// 	cout << v[i] << " ";

	printVector(v);

	v.push_back(15);


	printVector(v);
	
	cout << "The last element is: " << v[v.size()-1] << endl;
	
	// pops out of the end
	v.pop_back();

	// inserts 5 at start
	v.insert(v.begin(), 5);
	printVector(v);

	// erases first element
	v.erase(v.begin());
	printVector(v);

	// inserts 20 at end
	v.emplace_back(20);
	printVector(v);

	// erases the vector
	v.clear();
	printVector(v);
	cout << v.size() << endl;


	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	cout << "In Vector 1: ";
	printVector(v1);

	cout << "In Vector 2: ";
	printVector(v2);

	// swaps v1 and v2
	v1.swap(v2);

	cout << "After swap: ";
	printVector(v1);
	printVector(v2);



}