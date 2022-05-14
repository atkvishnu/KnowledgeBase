/*
Question: Zero Matrix
 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
*/

/*
Hints:
- 17 - If you just cleared the row and columns as you found 0's, you'd likely  wind up clearing the whole matrix. Try finding the cells with zeroes first before making any changes to the matrix.
- 74 - Can you use O(N) additional space instead of O(N^2)? What information do you really need from the list of cells that are zero?
- 102 - You probably need some data storage to maintain a list of the rows and columns that need to be zeroes. Can you reduce the additional space usage to O(1) by using the matrix itself for data storage?
*/

/*
Stratagies:
- 1. Check if there is any zero in first row (set a flag `firstRow`), start parsing through the 2nd row (set another flag for `nullifyThisRow`), if a 0 is encountered the flag is made true and that column is made 0 before coming out of the 2nd for loop, if the `nullifyThisRow` flag is true, then make that row also 0.
     Now check the first row again, if there are any zeroes encountered, then make that column zero!
     Now finally if the `firstRow` flag is true, then set the first row as 0.


- 2. take 2 sets/vectors (rowSet/colSet) to keep track of i and j indexes (where 0 exists). Parse through the sets, and make the respective rows/cols 0's.
     - in `1.8.2.cpp`
*/


#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Prints a matrix.
 *
 * @param      matrix  The matrix
 */
void printMatrix(vector<vector<int>> &matrix){
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


/**
 * @brief      Makes a row zero.
 *
 * @param      matrix  The matrix
 * @param[in]  rowNo   The row no
 */
void makeRowZero(vector<vector<int>> &matrix, int rowNo){
    for (int j = 0; j < matrix.size(); ++j)
    {
        matrix[rowNo][j] = 0;
    }
}


/**
 * @brief      Makes a col zero.
 *
 * @param      matrix  The matrix
 * @param[in]  colNo   The col no
 */
void makeColZero(vector<vector<int>> &matrix, int colNo){
    for (int i = 0; i < matrix[0].size(); ++i)
    {
        matrix[i][colNo] = 0;
    }
}


/**
 * @brief      Makes the rows and column 0 if a 0 is encountered.
 *
 * @param      matrix - The matrix
 */
void makeZero1(vector<vector<int>> &matrix){
    
    // checking if there is a zero in first row,
    // if there is set `firstRow` flag as true.
    bool firstRow = false;
    for (int i = 0; i < matrix[0].size(); ++i)
    {
        if(matrix[0][i] == 0){
            firstRow = true;
            break;
        }
    }


    // start parsing from second row (rest of the matrix)
    for (int i = 1; i < matrix.size(); ++i)
    {
        bool nullifyThisRow = false;
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j] = 0;
                nullifyThisRow = true;
                // makeRowZero(matrix, i);  // this won't work because if a zero is encountered anywhere in the first row then the entire matrix will be made zero.
                // makeColZero(matrix, j);
            }
            // column will be made null if a zero is encountered, and, the nullifyThisRow flag is also set to true
        }
        if(nullifyThisRow){     // if this is true, this row(i) will be made 0
            makeRowZero(matrix, i);
        }
    }

    // Now checking for zeroes in first row, and making that column 0. (this is done before making the first row 0's because if the first row was made 0 earlier then we wouldn't be able to manipulate the column.)
    for (int j = 0; j < matrix[0].size(); ++j)
    {
        if(matrix[0][j]==0){
            makeColZero(matrix, j);
        }
    }

    // finally, if `firstRow` flag is 0 then make 1st row 0.
    if(firstRow){
        makeRowZero(matrix, 0);
    }
}


int main(){
    int M, N;
    cout << "Enter number of rows:";
    cin >> M;
    cout << "Enter number of cols:";
    cin >> N;
    // int ** matrix = new int*[M];
    // for ( int i =0; i < M; ++i ) {
    //     matrix[i] = new int[N];
    // }
    vector<vector<int>> matrix(M, vector<int>(N));
    cout << "Provide M x N matrix: \n";
    for ( int i = 0; i < M; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix Before:\n";
    printMatrix(matrix);
    makeZero1(matrix);
    cout << "Matrix After:\n";
    printMatrix(matrix);

    return 0;
}


