// 2D vector with different number of cols
// #include <vector>
// #include <iostream>

// using namespace std;

// int main()
// {
// 	vector<vector<int>> vect{{1,2},{3,4,5},{6}};

// 	for (int i = 0; i < vect.size(); ++i){
// 		for (int j = 0; j < vect[i].size(); ++j)
// 		{	
// 			cout << vect[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}
// }

// Case 5: Sorting the 2D Vector on basis of no. of columns in row in ascending order.
// In this type of sorting, 2D vector is sorted on basis of no. of cols. in ascending order.
// The Matrix before sorting is:
// 1 2 
// 3 4 5 
// 6 
// The Matrix after sorting is:
// 6 
// 1 2 
// 3 4 5 


// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// bool sizecom(const vector<int>& v1, const vector<int>& v2)
// {
// 	return v1.size() < v2.size();
// }


// int main()
// {
// 	vector<vector<int>> vect{{1,2},{3,4,5},{6}};

// 	cout << "The Matrix before sorting is:\n";
// 	for (int i = 0; i < vect.size(); ++i){
// 		for (int j = 0; j < vect[i].size(); ++j)
// 		{	
// 			cout << vect[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}

// 	sort(vect.begin(), vect.end(), sizecom);	// 3rd parameter of sort fn. always takes a boolean val.


// 	cout << "The Matrix after sorting is:\n";
// 	for (int i = 0; i < vect.size(); ++i){
// 		for (int j = 0; j < vect[i].size(); ++j)
// 		{	
// 			cout << vect[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}

// 	return 0;
// }


// Case 6: Sorting the 2D Vector on basis of no. of columns in row in descending order.
// The Matrix before sorting is:
// 1 2 
// 3 4 5 
// 6 
// The Matrix after sorting is:
// 3 4 5 
// 1 2 
// 6 

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool sizecom(const vector<int>& v1, const vector<int>& v2)
{
	return v1.size() > v2.size();
}


int main()
{
	vector<vector<int>> vect{{1,2},{3,4,5},{6}};

	cout << "The Matrix before sorting is:\n";
	for (int i = 0; i < vect.size(); ++i){
		for (int j = 0; j < vect[i].size(); ++j)
		{	
			cout << vect[i][j] << " ";
		}
		cout << "\n";
	}

	sort(vect.begin(), vect.end(), sizecom);	// 3rd parameter of sort fn. always takes a boolean val.


	cout << "The Matrix after sorting is:\n";
	for (int i = 0; i < vect.size(); ++i){
		for (int j = 0; j < vect[i].size(); ++j)
		{	
			cout << vect[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}