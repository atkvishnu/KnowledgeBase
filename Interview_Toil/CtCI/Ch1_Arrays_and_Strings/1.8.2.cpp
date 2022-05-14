
#include <bits/stdc++.h>
using namespace std;



/**
 * @brief      Prints a set.
 *
 * @param[in]  s - The set
 */
void printSet(set<int> s){
    cout << "Set: "; 
    for(auto it = s.begin(); it!=s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


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
 * @brief      Counts the number of zeroes.
 *
 * @param      rowToNull  set (passed by address because we have to update the sets)
 * @param      colToNull  set
 * @param      matrix     The matrix
 */
void countZeroes(set<int> &rowToNull, set<int> &colToNull, vector<vector<int>> &matrix){
    int rowCount = matrix.size();
    int colCount = matrix[0].size();

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowToNull.insert(i);
                colToNull.insert(j);
            }
        }
    }
}

/**
 * @brief      Makes rows and cols zeroes if a 0 is encountered 
 *
 * @param      matrix  The matrix
 */
void makeZero2(vector<vector<int>> &matrix){
    
    int rowCount = matrix.size();
    int colCount = matrix[0].size();
    
    set<int> rowToNull, colToNull;

    countZeroes(rowToNull, colToNull, matrix);


    for(int rowNo: rowToNull){
        matrix[rowNo].assign(colCount, 0);
    }

    for(int colNo: colToNull){
        for (int i = 0; i < rowCount; ++i)
        {
            matrix[i][colNo] = 0;
        }
    }
    printMatrix(matrix);
}


int main(){
    int M, N;
    cout << "Enter number of rows: ";
    cin >> M;
    cout << "Enter number of cols: ";
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

    cout << "Before: \n";
    printMatrix(matrix);
    cout << "Using STL Set: \n";
    makeZero2(matrix);
}