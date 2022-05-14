/*
Question: Rotate Matrix
 Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.
 Can you do this in place?
*/

/*
Hints:
- Try thinking about it layer by layer. Can you rotate a specific layer?
- Rotating a specific layer would just mean swapping the values in four arrays. If you were asked to swap the values in two arrays, could you do this? Can you then extend it to four arrays?
*/

/*
Stratagies:
- clockwise: (i->j) , (j->n-i-1)
- anti-clockwise: (i->n-j-1), (j->i)
*/


#include <bits/stdc++.h>
using namespace std;


void print_matrix(vector<vector<int>> &m)
{
    for(vector<int> &row : m)
    {
        for (int &cell : row){
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void rotate_matrix_clockwise(vector<vector<int>> &m){
    int n = m.size();
    // cout << n << endl;
    // vector<vector<int>> newVec = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    vector<vector<int>> newVec(n, vector<int>(n));  // made dynamically zero.... KIM: initializing vector of vectors to a value(0)
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            newVec[j][n-i-1] = m[i][j];
        }
    }
    print_matrix(m);
    print_matrix(newVec);
}

void rotate_matrix_anti_clockwise(vector<vector<int>> &m){
    int n = m.size();
    // cout << n << endl;
    // vector<vector<int>> newVec = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    vector<vector<int>> newVec(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            newVec[n-j-1][i] = m[i][j];
        }
    }
    print_matrix(m);
    print_matrix(newVec);
}


void rotateInPlace_anti_clockwise(vector<vector<int>> &m){     // layer rotation****
    int n = m.size();
    print_matrix(m);
    for (int i = 0; i < n/2; ++i)       // (0,1)
    {
        for (int j = i; j < n-i-1; ++j)     // ((i=0) to 3, (i=1) to 2)
        {
            int temp = m[i][j];
            m[i][j] = m[j][n-i-1];
            m[j][n-i-1] = m[n-i-1][n-j-1];
            m[n-i-1][n-j-1] = m[n-j-1][i];
            m[n-j-1][i] = temp;
        }
    }
    print_matrix(m);
}


void rotateInPlace_clockwise(vector<vector<int>> &m){     // layer rotation****
    int n = m.size();
    print_matrix(m);
    for (int i = 0; i < n/2; ++i)       // (0,1)
    {
        for (int j = i; j < n-i-1; ++j)     // ((i=0) to 3, (i=1) to 2)
        {
            // int temp = m[i][j];      // to-do
            // m[i][j] = m[j][n-i-1];
            // m[j][n-i-1] = m[n-i-1][n-j-1];
            // m[n-i-1][n-j-1] = m[n-j-1][i];
            // m[n-j-1][i] = temp;
        }
    }
    print_matrix(m);
}


int main()
{
    vector<vector<int>> m = {{1,2,3,1},{4,5,6,1},{7,8,9,1},{10,11,12,13}};
    cout << "Clockwise rotation: " << endl;
    rotate_matrix_clockwise(m);
    cout << "Anti-Clockwise rotation: " << endl;
    rotate_matrix_anti_clockwise(m);
    cout << "Rotate In-place Anti-Clockwise rotation: " << endl;
    rotateInPlace_anti_clockwise(m);

}

