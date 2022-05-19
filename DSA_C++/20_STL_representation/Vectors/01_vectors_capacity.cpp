// Vector capacity
// size(), max_size(), capacity(), resize(n), empty(), shrink_to_fit(), reserve() 



#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> g1;

	for(int i = 0; i <= 5; ++i)
		g1.push_back(i);


	cout << "Size: " << g1.size() << endl;
	cout << "Capacity: " << g1.capacity() << endl;
	cout << "Max. size: " << g1.max_size() << endl;


	// resizes the vector size to 4
	g1.resize(4);

	// for (int i = 0; i < 5; ++i)
	// {
	// 	cout << g1[i] << " ";
	// }
	// cout << endl;

	// vector size after resize
	cout << "Size: " << g1.size() << endl;

	// checks if the vector is empty or not
	if(g1.empty() == false)
		cout << "vector is not empty." << endl;
	else
		cout << "Vector is empty." << endl;

	// shrinks the vector
	g1.shrink_to_fit();	

	cout << "Vector elements are: ";
	for(auto it = g1.begin(); it != g1.end(); it++)
		cout << *it << " ";
	cout << endl;



}