// Accessing elements

// reference operator - [], at(), front(), back(), data()


// element accesser in vector
#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> g1;

	for(int i = 1; i <= 10; ++i)
		g1.push_back(i*10);

	cout << "Reference operator [g]: g1[2] = " << g1[2] << endl;

	cout << "at(): g1.at(4) = " << g1.at(4) << endl;

	cout << "front(): " << g1.front() << endl;

	cout << "back(): " << g1.back() << endl;

	int *pos = g1.data()+4;
	cout << "The first ele is: " << *pos;
	return 0;
} 