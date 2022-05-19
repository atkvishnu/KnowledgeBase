// # Vector of Vectors in C++ STL with Examples

// Vectors are known as dynamic arrays with the ability to resize itself automatically when an element is
// inserted or deleted, with their storage being handled automatically by the container.

// Vector of Vectors is a two-dimensional vector with a variable number of rows where each row is vector.
// Each index of vector stores a vector which can be traversed and accessed using iterators. It is
// similar to an Array of Vectors but with dynamic properties.

// Syntax:
// vector<vector<data_type>> vec;

// Example:
// vector<vector<int>> vec{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9, 4 }}; 
// where vec is the vector of vectors with different number of elements in different rows

// # Insertion in Vector of Vectors

// Elements can be inserted into a vector using the push_back() function of C++ STL.
// Below example demonstrates the insertion operation in a vector of vectors. The code 
// creates a 2D vector by using the push_back() function and then displays the matrix.

// Syntax:
// vector_name.push_back(value)
// where value refers to the element to be added in the back of the vector

// Example 1:
// v2 = {1, 2, 3}
// v1.push_back(v2);
// This function pushes vector v2 into vector of vectors v1. Therefore v1 becomes { {1, 2, 3} }.

// Example 2:

// v2 = {4, 5, 6}
// v1.push_back(v2);
// This function pushes vector v2 into existing vector of vectors v1 and v1 becomes v1 = { {1, 2, 3}, {4, 5, 6} }

// Below is the example to demonstrate insertion into a vector of vectors.


// C++ program to demonstrate insertion
// into a vector of vectors
  
// #include <iostream>
// #include <vector>
// using namespace std;
  
// // Defining the rows and columns of
// // vector of vectors
// #define ROW 4
// #define COL 5
  
// int main()
// {
//     // Initializing the vector of vectors
//     vector<vector<int> > vec;
  
//     // Elements to insert in column
//     int num = 10;
  
//     // Inserting elements into vector
//     for (int i = 0; i < ROW; i++) {
//         // Vector to store column elements
//         vector<int> v1;
  
//         for (int j = 0; j < COL; j++) {
//             v1.push_back(num);
//             num += 5;
//         }
  
//         // Pushing back above 1D vector
//         // to create the 2D vector
//         vec.push_back(v1);
//     }
  
//     // Displaying the 2D vector
//     for (int i = 0; i < vec.size(); i++) {
//         for (int j = 0; j < vec[i].size(); j++)
//             cout << vec[i][j] << " ";
//         cout << endl;
//     }
//     return 0;
// }








// Removal or Deletion in a Vector of Vectors

// Elements can be removed from a vector of vectors using the pop_back() function of C++ STL.

// Below example demonstrates the removal operation in a vector of vectors. The code removes elements from a 2D vector by using the pop_back() function and then displays the matrix.
// Syntax:

// vector_name[row_position].pop_back()
// Example 1: Let the vector of vectors be vector v = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }

// v[2].pop_back()
// This function removes element 9 from the last row vector. Therefore v becomes { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8 } }.





// Example 2:

// v[1].pop_back()
// This function removes element 6 from the last second row vector. Therefore v becomes { { 1, 2, 3 }, { 4, 5 }, { 7, 8 } }.

// Below is the example to demonstrate removal from a vector of vectors.


// // C++ program to demonstrate removal
// // from a vector of vectors
  
// #include <iostream>
// #include <vector>
// using namespace std;
  
// // Driver Method
// int main()
// {
//     // Initializing 2D vector "vect" with
//     // sample values
//     vector<vector<int>> vec{{1,2,3},{4,5,6},{7,8,9}};
  
//     // Removing elements from the
//     // last row of the vector
//     vec[2].pop_back();
//     vec[1].pop_back();
  
//     // Displaying the 2D vector
//     for (int i = 0; i < 3; i++) {
//         for (
//             auto it = vec[i].begin();
//             it != vec[i].end(); it++)
//             cout << *it << " ";
//         cout << endl;
//     }
//     return 0;
// }


// Traversal of a Vector of Vectors
// The vector of vectors can be traversed using the iterators in C++. The following code demonstrates the
// traversal of a 2D vector.

// Syntax:
// for i in [0, n){
//     for (iterator it = v[i].begin();it != v[i].end(); it++) 
//    {
//         // Operations to be done For example to print
//         print(*it)
//     }
// }

// C++ code to demonstrate traversal of a 2D vector
#include <iostream>
#include <vector>

using namespace std;

// Driver Method
int main() {
    // Initializing 2D vector "vect" with
    // sample values
    vector<vector<int>>vec {{1,2,3}, {4,5,6}, {7,8,9}};

    // Displaying the 2D vector
    for (int i = 0; i < 3; i++) {
        for (auto it = vec[i].begin(); it != vec[i].end(); it++)
            cout << * it << " ";
        cout << endl;
    }

    return 0;
}