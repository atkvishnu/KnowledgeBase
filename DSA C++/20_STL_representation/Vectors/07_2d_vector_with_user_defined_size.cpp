// In a 2D vector, every element is a vector.
// Example:
// vector<vector<int>> vect
// {
// 	{1,2,3},
// 	{4,5,6},
// 	{7,8,9},
// }

// Accessing these elements:

// Method 1: for loop
// for(int i = 0; i < vect.size(); i++) {
// 	for (int j = 0; j < vect[i].size(); ++j)
// 	{
// 		cout << vect[i][j] << " ";
// 	}
// 	cout << "\n";
// }

// Method 2: for-each loop (read colon(:) as "in")
// for(vector<int> vect1D: vect){
// 	for(int x: vect1D) {
// 		cout << x << " ";
// 	}
// 	cout << "\n";
// }

// NOTE:
// Each elements inside the 2D vector can have different number of values. 
// Ex:
// {
// 	{1,2},
// 	{4,5,6},
// 	{7,8,9,10}
// }





// Question: Define the 2D vector with different sizes of columns
// Examples:
// Input : Number of rows : 5 
//         Number of columns in rows : 
//         2 3 4 5 1
// Output : 1 2
//          1 2 3
//          1 2 3 4
//          1 2 3 4 5 
//          1

// Input : Number of rows : 3
//         Number of columns in rows : 
//         3 2 1

// Output : 1 2 3
//          1 2
//          1

// 1st method:
// We first declare an integer variable named “row” and then an array named “column” which is going to hold the value of the size of each row. 
// After that we proceed to initialize the memory of every row by the size of column.
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int row = 5;
	int column[] = {2,3,4,5,1};

	// created a 2D vector and assigned it a capacity of "row" = 5 units
	vector<vector<int>> vec(row);

	for (int i = 0; i < row; i++)
	{
		int col = column[i];
		vec[i] = vector<int>(col);	// i'th row = size of column

		for(int j = 0; j < col; j++) {
			vec[i][j] = j + 1;
		}
	}

	for(int i = 0; i < row; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }   
        cout << endl;
    }

	return 0;
}
*/



// 2nd method:
// initializing a 2D vector of “n” rows and “m” columns, with a value 0.
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 3;
    int m = 4;

    vector<vector<int>> vec(n, vector<int> (m,0));

	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Output
// 0 0 0 0 
// 0 0 0 0 
// 0 0 0 0 
*/

// Method 3: 
// creating a 2D vector of “n” rows and “m” columns and input values. 

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 4;
    int m = 5;

    vector<vector<int>> vec(n, vector<int> (m));

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		// int n;
    		// cin >> n;
    		// vec[i][j] = n;	// provide i/p in "input.txt"
    		vec[i][j] = j + i + 1;
    	}
    }

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		cout << vec[i][j] << " ";
    	}
    	cout << "\n";
    }
}