// Sorting 2D Vector (By row and column)

// 2D Vector is a "Vector of Vector".
// In C++, 2D Vectors are used for creating matrices, tables, or any other structures, dynamically.


// Program to create a 2D vector
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	vector<vector<int>> vect{{1,2,3},{4,5,6},{7,8,9}};

// 	for(int i = 0; i < vect.size(); i++) {
// 		for(int j = 0; j < vect[i].size(); j++) {
// 			cout << vect[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// 	return 0;
// }



// Ways to sort a 2D vector

// Case 1: To sort a particular row of 2D vector
// This type of sorting arranges a selected row of 2D vector in ascending order. 
// This is achieved by using sort() and passing iterators of 1D vector as its arguments.

// #include <algorithm>
// #include <vector>
// #include <iostream>

// using namespace std;

// int main()
// {
// 	vector<vector<int>> vect{{3,5,1},{4,8,6},{7,2,9}};

// 	int m = vect.size();	// no. of rows
// 	int n = vect[0].size();	// no. of cols

// 	cout << "Before sort: " << endl;
// 	for(int i = 0; i < m; i++){
// 		for(int j = 0; j < n; j++) {
// 			cout << vect[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// 	sort(vect[0].begin(), vect[0].end());

// 	cout << "After sorting: " << endl;
// 	for(int i = 0; i < m; i++){
// 		for(int j = 0; j < n; j++) {
// 			cout << vect[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// 	return 0;
// }


// Case 2: To sort the entire 2D vector on basis of a particular column
// In this type of sorting 2D vactor is entirely sorted on basis of a chosen column.
// Ex. If the chosen col. is 2nd, the row with the smallest value in the 2nd col.
// becomes the 1st row, the 2nd smallest value becomes the 2nd row, ....

// {3,5,1},
// {4,8,6},
// {7,2,9}

// {7,2,9},		// Row with smallest value in 2nd col.
// {3,5,1},		// Row with smallest value in 2nd col.
// {4,8,6}

// This is achieved by passing a third argument in sort() as a call to the user-defined explicit function.

#include <algorithm>	// for sort()
#include <vector>
#include <iostream>

using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2){
	return v1[1] < v2[1];
}


int main()
{
	vector<vector<int>> vect{{3,5,1},{4,8,6},{7,2,9}};

	int m = vect.size();	// no. of rows
	int n = vect[0].size();	// no. of cols

	cout << "Before sort: " << endl;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++) {
			cout << vect[i][j] << " ";
		}
		cout << endl;
	}

	sort(vect.begin(), vect.end(), sortcol);

	cout << "After sorting: " << endl;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++) {
			cout << vect[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}






























