// 2nd STYLE OF PROGRAMMING ( WHEN PROGRAMS ARE VERY BIG )

// MODULAR/PROCEDUARAL PROGRAMMING (FUNCTIONS + CLASSES)

// main() is not calculating the values, it's calling the respective functions.
// The responsibility of calculating area and perimeter are given to separate functions.
// This is called modular/procedural programming.

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}


int area (struct Rectangle r)
{
    return r.length * r.breadth;
}

int peri(Rectangle r)        //Project is a C++ type, so it doesn't strictly require (struct Rectangle r) only (Rectangle r) will suffice!
{
    int p;
    p = 2*(r.length+r.breadth);

    return p;
}

int main()
{
    // XX int length = 0, breadth = 0;    // In next part we will combine these predefined values into an structure!
    Rectangle  r = {0,0};

    cout << "Enter the length and breadth: ";

    int l,b;
    cin >> l >> b;


    initialize(&r, l, b);
    // cout << "The area of the rectangle is: " << area(length,breadth) <<  endl;
    // Previously we were passing 2 parameters, but now those 2 parameters are put in a box and they are sent together
    cout << "The area of the rectangle is: " << area(r) <<  endl;   //Now we are passing the complete box, which contains both the length and breadth
    //These both paramater passing is Call by value
    cout << "The perimeter of the rectangle is: " << peri(r) <<  endl;

    return 0;
}

//If the struct is converted to class then it's a pure c++ style program.
// struct -> C
// class  -> C++