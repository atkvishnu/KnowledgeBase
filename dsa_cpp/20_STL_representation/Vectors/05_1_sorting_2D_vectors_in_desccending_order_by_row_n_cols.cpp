// Case 3: To sort a particular row of 2D vector in descending order


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

// 	sort(vect[0].rbegin(), vect[0].rend());

// 	cout << "After sorting: " << endl;
// 	for(int i = 0; i < m; i++){
// 		for(int j = 0; j < n; j++) {
// 			cout << vect[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// 	return 0;
// }



// Case 4: To sort the entire 2D vector on basis of a particular column in descending order

// {3, 5, 1},
// {4, 8, 6},
// {7, 2, 9};

// After sorting this matrix by second column, we get

// {4, 8, 6} // Row with greatest value in second column
// {3, 5, 1} // Row with second greatest value in second column
// {7, 2, 9}

#include <algorithm>	// for sort()
#include <vector>
#include <iostream>

using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2){
	return v1[1] > v2[1];
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