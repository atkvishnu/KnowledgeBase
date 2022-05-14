#include <iostream> 
#include <stdio.h>  //using this library to test functionality of malloc
#include <stdlib.h> //because we are using malloc
using namespace std; 

struct Rectangle {
    int length;
    int breadth;
};


int main()
{
    //1. POINTER TO A VARIABLE a
    // int a = 10;
    // int *p;         //Declaration of pointer is done by using asterisk (*) | asterisk * is used at the time of declaration and dereferencing.
    // p = &a;         //Initialization of pointer to address of a(i.e. &a)

    // cout << "using pointer - " << p << ", " <<  &a << endl;         //this shows that p and &a are same, i.e. address of a ( p == &a), &a is the address of a and p is pointing to a
    // cout << a << ", " << p << ", " << *p << endl; 
    // cout << a << endl;

    //  FOR A DECLARATION AND DEREFRENCING USE A STAR; FOR INITIALIZATION AND POINTER ARITHMETIC DON'T USE A STAR!

    //2. POINTER TO AN ARRAY
    // int A[5] = {2,4,6,8,10};        //array is created inside the stack (anything declared inside a main function is stored in the stack(stack frame of the main function) )
    // int *p;
    // p = A;  // p = A means we are allocating the address of the array to p, because A stores the address of first element of A - which in turn is the address of the array
    // //we can also do
    // // p = &A[0];       //This is also correct
    // //This will be wrong
    // // p = &A;          //This is wrong

    // for (int i = 0; i< 5; i++){
    //     cout <<A[i] << endl;
    //     // cout << p[i] << endl;   //This will also work!
    // }

    //3.CREATING AN ARRAY IN THE HEAP
    // int *p;
    // // p = (int *)malloc(5*sizeof(int));   //malloc fn. will allocate the memory for 5 integers AND it's assigned to an pointer p (THIS IS A C METHOD)
    // // only 'p' is inside the stack BUT the array is inside the HEAP

    // //C++ way
    // p = new int[5]; //acts just like malloc -> this is dynamic allocation of memory

    // //now initializing the values
    // p[0] = 10; p[1] = 15; p[2] = 20; p[3] = 25; p[4] = 30;
    // for(int i = 0; i < 5; i++){
    //     cout << p[i] << endl;
    // }

    // // by using new we allocated new memory in heap
    // // when we are finished using this memory we SHOULD delete that memory or else there will be memory leak
    // delete [ ] p;    //square bracket used because we used an array! -> this is C++ method
    // //C method
    // // free(p);
    // //once the program ends this allocated heap memory will be automatically deleted.
    // //in student programs OR small projects deleting the heap memory is not that important

    //IMPORTANT PROPERTY OF POINTER
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;   //pointer of type structure

    cout << sizeof(p1) <<endl;
    cout << sizeof(p2) <<endl;
    cout << sizeof(p3) <<endl;
    cout << sizeof(p4) <<endl;
    cout << sizeof(p5) <<endl;
    //Whatever the datatype of pointer, the pointer used same amount of memory; every pointer uses same type of memory!
    //size of the pointer is independent of data type of the pointer

    return 0;
}