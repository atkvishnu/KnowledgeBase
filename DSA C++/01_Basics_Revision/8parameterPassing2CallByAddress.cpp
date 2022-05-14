//2. CALL BY ADDRESS
// This swap function is using Call by Address

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

void swap(int *x, int *y)           // Formal parameters should be of type pointers!
{
    int temp;
    temp = *x;          //*x will access num1 AND *y will access num2
    *x = *y;
    *y = temp;
}


int main()
{
    int num1 = 10, num2 = 15;       //The pointers will be indirectly accessing these values (from num1 and num2)

    swap(&num1, &num2);             // When we call the function, we pass the address of the "Actual parameters"! The address of actual parameters are passed and they are taken in the Formal parameters(which are pointers).

    cout << "First number " << num1 << endl;
    cout << "Second number " << num2 << endl;

    return 0;
}

//When and how to use?
//Swap function is modifying the actual parameters, it's not returning anything, Whatever the results of swap fn., they are directly reflected inside actual parameters. 
//In some situation, it may return somethings!
//When we want a function to directly work upon the actual parameters, then we should go for call by address!
//In the swap function, 2 parameters are getting modified, but only 1 value can be returned! We want 2 return values from the swap fn., if results are being returned. Therefore, we should use call by Address here!
//If we have some variables and we want the same variable to be modified, then send it as address(i.e., call by address)!
