#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

// struct Rectangle
// {
//     int length;
//     int breadth;
// };

//------------------------------------------------------------------------------------------------
// **1. CALL BY VALUE**

// void fun(struct Rectangle r1)
// {
//     r1.length = 20;
//     cout << "Length " << r1.length << endl << "Breadth " << r1.breadth << endl;
// }


// int main()
// {
//     struct Rectangle r = {10,5};
//     fun(r);
//     printf("Length %d \nBreadth %d \n", r.length,r.breadth);

//     return 0;
// }

//------------------------------------------------------------------------------------------------
// **2. CALL BY VALUE**
// void fun(struct Rectangle *p)
// {
//     p->length = 20;
//     cout << "Length " << p->length << endl << "Breadth " << p->breadth << endl;
// }   //Call by value will change the actual parameters also!


// int main()
// {
//     struct Rectangle r = {10,5};
//     fun(&r);
//     printf("Length %d \nBreadth %d \n", r.length,r.breadth);

//     return 0;
// }

//------------------------------------------------------------------------------------------------
// 3. CREATING A VARIABLE OF TYPE STRUCTURE ON HEAP INSIDE A FUNCTION AND RETURN IT'S ADDRESS

// This function will return a pointer of type rectangle
// struct Rectangle *fun()
// {
//     struct Rectangle *p;    //It will create an object of type rectangle on heap using a pointer.
//     p = new Rectangle;
//     // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

//     p -> length = 15;       // assigning length and breadths
//     p -> breadth = 7;

//     return p;           // Returning the address of that structure!
// }       //address of the structure is returned by this function


// int main()
// {
//     struct Rectangle *ptr= fun();       // The object is not created by the main function, it's created by the fun function. fun() is returning a pointer to the structure.

//     cout << "Length " << ptr -> length << endl << "Breadth " << ptr -> breadth << endl;

//     return 0;
// }


//------------------------------------------------------------------------------------------------
//4. ARRAY INSIDE A STRUCTURE!
struct Test
{
    int A[5];
    int n;
};

void fun(struct Test t1, int n)
{
    t1.A[0] = 10;
    t1.A[1] = 15;
    for (int i = 0; i<n;i++)
    cout << "From fun -> " << t1.A[i] << " \n";
}

int main()
{
    struct Test t = {{2,4,6,8,10},5};
    
    fun(t,t.n);

    for(int j = 0; j < t.n; j++)
    cout << "From main() -> " << t.A[j] << endl;
}