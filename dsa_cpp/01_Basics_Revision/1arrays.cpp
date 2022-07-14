#include <iostream> 
using namespace std; 

int main()
{
    int A[5];

    // A[0] = 5;
    // A[1] = 10;
    // A[2] = 15;
    // A[3] = 20;       //sizeof(int) -> 4bytes Therefore, 4*5=20
    // A[4] = 25;

    // //accessing the array
    // for (int i = 0; i < 5; i++) {
    //     cout << A[i] << " ";
    // }

    // cout << sizeof(A) << endl;
    // cout << A[1] << endl;
    // printf("%d\n",A[2]);    //C code can be used inside a c++ program | if compiler gives error include stdio.h

    int B[10] = {2,4,7,8,9,10};   //an array can be initialized without mentioning the array size inside [--]
    cout << B[8] << ", " << B[9] << endl;

    for (int x: B) {                    //we can access an array using a for-each loop
        cout << x << endl;
    }


}