// Pair is a container that can be used to bind together a two values which may be of different types. 
// Pair provides a way to store two heterogeneous objects as a single unit.

// pair <int, char> p1;                    // default
// pair <int, char> p2 (1, ‘a’);           // value inititialization
// pair <int, char> p3 (p2);               // copy of p2

// We can also initialize a pair using make_pair() function. 
// make_pair(x, y) will return a pair with first element set to x and second element set to y.
// p1 = make_pair(2, ‘b’);

// To access the elements we use keywords, `first` and `second` to access the first and second element respectively.
// cout << p2.first << " " << p2.second << endl;

#include <iostream>
#include <utility>

using namespace std;

int main()
{
	pair<int, char> p;
	pair<int, char> p1(2, 'b');

	p = make_pair(1, 'a');

	cout << p.first << " " << p.second << endl;
	cout << p1.first << " " << p1.second << endl;

	return 0;
}