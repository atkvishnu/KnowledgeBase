// 2nd STYLE OF PROGRAMMING ( WHEN PROGRAMS ARE VERY BIG )

// MODULAR/PROCEDUARAL PROGRAMMING (FUNCTIONS + CLASSES)

// main() is not calculating the values, it's calling the respective functions.
// The responsibility of calculating area and perimeter are given to separate functions.
// This is called modular/procedural programming.

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

class Rectangle                 // because we wrote a class here, all the members are private if not stated otherwise //if struct is here, then all the members are public 
{
    
private:
    int length;
    int breadth;

public:
    void initialize(int l, int b)
    {
        length = l;
        breadth = b;
    }


    int area ()
    {
        return length * breadth;
    }

    int peri()        //Project is a C++ type, so it doesn't strictly require (struct Rectangle r) only (Rectangle r) will suffice!
    {
        int p;
        p = 2*(length+breadth);

        return p;
    }
};

int main()
{
    // XX int length = 0, breadth = 0;    // In next part we will combine these predefined values into an structure!

    Rectangle r;
    cout << "Enter the length and breadth: ";
    
    int l,b;
    cin >> l >> b;
    


    r.initialize(l, b);
    // cout << "The area of the rectangle is: " << area(length,breadth) <<  endl;
    // Previously we were passing 2 parameters, but now those 2 parameters are put in a box and they are sent together
    cout << "The area of the rectangle is: " << r.area() <<  endl;   //Now we are passing the complete box, which contains both the length and breadth
    //These both paramater passing is Call by value
    cout << "The perimeter of the rectangle is: " << r.peri() <<  endl;

    return 0;
}

//If the struct is converted to class then it's a pure c++ style program.
// struct -> C -> Everything is public
// class  -> C++    -> Everything is private if not stated otherwise