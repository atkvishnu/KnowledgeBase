// CREATING AN ARRAY INSIDE A FUNCTION AND RETURNING ITS ADDRESS

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

// Here we could have used [ ] but it's not supported in every compiler because it's the old syntax of doing that, that's why we should use *.
// This function will create an array and return it's pointer (represented by the * in [int * fun()])!
int * fun(int size)
{
    int *p;
    // p = (int *)malloc(size*sizeof(int));
    p = new int[size];                  //creating the array in heap

    for(int i=0;i<size;i++)             //initializing all the elements inside the array
    p[i] = i+1;
    
    return p;                           //returning pointer of that type array -> which is taken in ptr, and main function is using this array
}


int main()
{
    int *ptr, sz = 7;

    ptr = fun(sz);                  //after this line fn. fun will be deleted from the stack frame of main fn.

    for(int i=0;i<sz;i++)
    cout << ptr[i] << endl;         //using the pointer ptr we are printing the array
    // Inside the main function there is no array! So where is the array coming from? Function fun is creating the array of the given size i.e., sz = 5 It's coming from the heap!
    // This is the benefit of dynamic memory! Array is created in the heap, it's created inside the function fun, but even main fn. can access it bcoz. main fn. is getting it's pointer!

    // Therefore, if we create anything in heap, then it can be accessed anywhere in the program if pointer is available on it!

    return 0;
}