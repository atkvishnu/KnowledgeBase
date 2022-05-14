// 2nd STYLE OF PROGRAMMING ( WHEN PROGRAMS ARE VERY BIG )

// MODULAR/PROCEDUARAL PROGRAMMING (FUNCTIONS + CLASSES)

// main() is not calculating the values, it's calling the respective functions.
// The responsibility of calculating area and perimeter are given to separate functions.
// This is called modular/procedural programming.

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int area (int length, int breadth)
{
    return length * breadth;
}

int peri(int length, int breadth)
{
    int p;
    p = 2*(length+breadth);

    return p;
}

int main()
{
    int length = 0, breadth = 0;    // In next part we will combine these predefined values into an structure!

    cout << "Enter the length and breadth: ";

    cin >> length >> breadth;

    cout << "The area of the rectangle is: " << area(length,breadth) <<  endl;
    
    cout << "The perimeter of the rectangle is: " << peri(length,breadth) <<  endl;

    return 0;
}