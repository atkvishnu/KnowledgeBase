#include <iostream> 
#include <stdio.h>
#include <stdlib.h>

using namespace std; 

struct Rectangle {
    int length;
    int breadth;
};

// //1. Creating a static object in stack
// int main()
// {
//     // struct Rectangle r={10,5};  //This is valid in both C and C++ compiler | in C program struct is mandatory AND in C++ struct isn't mandatory!
//     Rectangle r = {10,5};   //This is only valid in C++ compiler

//     cout << r.length << ", " << r.breadth << endl << endl;  //when we have a normal variable then we access it using a dot operator!

//     Rectangle *p = &r;      //When we have a pointer, then we access the props. of the structure using -> (Arrow)
//     cout << p->length << endl;
//     cout << p->breadth << endl;
    
//     return 0;
// }

//2. Creating a dynamic object structure in Heap (Dynamic allocation of Rectangle structure)
int main()
{
    Rectangle *p;
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));       //C method
    p = new Rectangle;          //C++ method
    p -> length = 15;
    p->breadth = 10;
    cout << p->length << endl;
    cout << p->breadth << endl;
}