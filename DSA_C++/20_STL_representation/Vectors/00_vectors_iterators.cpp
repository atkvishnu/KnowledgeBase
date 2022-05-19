// iterators in vector

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> g1;

	for(int i = 1; i <=5; i++)
		g1.push_back(i);

	cout << "begin and end: ";
	for (auto i = g1.begin(); i < g1.end(); ++i)
		cout << *i << " ";

	cout << "cbegin and cend: ";
	for(auto ic = g1.cbegin(); ic != g1.cend(); ++ic)
		cout << *ic << " ";

	cout << "rbegin and rend: ";
	for(auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		cout << *ir << " ";


	cout << "crbegin and crend: ";
	for(auto icr = g1.crbegin(); icr != g1.crend(); ++icr)
		cout << *icr << " ";








	return 0;
}