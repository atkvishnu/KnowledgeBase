// 3. CALL BY REFERENCE
// ONLY AVAILABLE IN C++
// USE CAUTIOUSLY!
// MECHANISM AND WORKING IS SAME AS CALL BY ADDRESS!

// In C++, the concept of reference is same as nickname of a variable!

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

void swap(int &x, int &y)           // Formal parameters should have amperstand(&)! Therefore x directly represents num1 and y directly represents num2
//x is not a pointer. x is num1. Refer to references concept in C++.
//This swap function may become inline function. It depends on the compiler! It depends on how a compiler implements references!
{
    int temp;
    temp = x;          //*x will access num1 AND *y will access num2
    x = y;
    y = temp;
}


int main()
{
    int num1 = 10, num2 = 15;       //The pointers will be indirectly accessing these values (from num1 and num2)

    swap(num1, num2);             // When we call the function, we pass the address of the "Actual parameters"! The address of actual parameters are passed and they are taken in the Formal parameters(which are pointers).

    cout << "First number " << num1 << endl;
    cout << "Second number " << num2 << endl;

    return 0;
}