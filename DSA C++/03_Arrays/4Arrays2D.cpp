#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 




int main()
{
    // 2D Array named A is made in stack
    int A[3][4] = {{1,2,3,4}, {2,4,6,8}, {1,3,5,7}};



    // 2D Array named B is made using pointers(*)   // it's partially made in heap
    int *B[3];      //in stack
    B[0] = (int *)malloc(4*sizeof(int));                    //in heap
    B[1] = (int *)malloc(4*sizeof(int));                    //in heap
    B[2] = (int *)malloc(4*sizeof(int));                    //in heap
    B[0][0] = 0;
    B[0][1] = 1;
    B[0][2] = 2;
    B[0][3] = 3;



    // 2D Array named C is made using pointer of pointers(**)   // it's completely made in heap
    int **C;        //in stack

    C = (int **)malloc(3*sizeof(int *));        //C style   //in heap
    C[0] = (int *)malloc(4*sizeof(int));                    //in heap
    C[1] = new int[4];                          //C++ style //in heap
    C[2] = new int[4];                                      //in heap

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4;j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}