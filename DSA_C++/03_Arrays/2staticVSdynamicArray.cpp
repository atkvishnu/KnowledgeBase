#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int main()
{
    int A[5] = {2,4,6,8,10};
    
    int *p; //pointer for array in heap

    p = (int *)malloc(5*sizeof(int));
    //p = new int[5];

    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for(int i=0;i<5;i++)
        printf("%d ", A[i]);
    cout << endl;

    for(int i=0;i<5;i++)
        printf("%d ", p[i]);

    return 0;
}