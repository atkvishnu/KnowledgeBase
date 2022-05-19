#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

// KIM(VVI) // Arrays are always passed by address, they are never passed by value OR reference.
// For taking A as an parameter we have to use square brackets OR a star(*)!
// The A[ ] in fun function is a pointer to the main A[ ]. These two A[ ] are different! Both belong to different functions i.e., main and fun

void fun(int *A, int n){     //this parameter is an pointer
    // cout << sizeof(A) << "  " << sizeof(int) << endl;      // 4  4
    // cout << sizeof(A)/sizeof(int) << endl;                 // 1 (4/4) 
    //sizeof(int) because it is of type integer!
    // This will give us the size of the array
    // BUT the output was 1. This is not giving us the size of the array, because the size of the array is 5 integers.
    // The A[ ] here is an pointer, therefore it will have the same size as int. i.e., 4
    
    //for-each loop will not work inside this function because A is a pointer here, and for-each loop won't work on a pointer. We can use for-each loop on an array, but not on a pointer!
    // for(int x:A)
    // cout << x << endl;
    A[0] = 100;     //this will change the main array
    for(int i=0;i<n;i++)
    cout << A[i] << endl;
}


int main()
{
    int A[ ] = {2,4,6,8,10};
    int n = 5;
    fun(A,n);
    cout << endl;
    // cout << sizeof(A) << "  " << sizeof(int) << endl;   // 20  4
    // cout << sizeof(A)/sizeof(int) << endl << endl;      // 5(20/4)
    for(int x : A)  //for-each loop
    {
        cout << x << " ";
    }
    return 0;
}