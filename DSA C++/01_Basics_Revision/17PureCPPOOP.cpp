#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 


class Rectangle{
private:
    int length;
    int breadth;

public:

    Rectangle()             //This is a default constructor
    {
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b)     //This is a parameterized method
    {
        length = l;
        breadth = b;
    }
    int area() {                // This is the actual method (facilitators)
        return length * breadth;
    }
    int perimeter() {           // This is the actual method (facilitators)
        return 2*(length+breadth);
    }
    void setLength(int l)       //mutator fn.
    {
        length = l;
    }
    void setBreadth(int b)       //mutator fn.
    {
        breadth = b;
    }
    int getLength()             //accessor fn.
    {
        return length;
    }
    int getBreadth()              //accessor fn.
    {
        return breadth;
    }
    ~Rectangle()
    {
        cout << "Destructor " << endl;      //At the end of the main fn., the destructor will be automatically called because the object is going outside the scope.
    }
};

// Rectangle :: Rectangle(int l, int b)
// {
//     length = l;
//     breadth = b;
// }

// int Rectangle :: area()
// {
//     return length * breadth;
// }

// int Rectangle :: perimeter()
// {
//     return 2*(length + breadth);
// }



int main()
{
    Rectangle r (10,5);

    cout << "Area " << r.area() << endl;
    cout << "Perimeter " << r.perimeter() << endl;

    r.setLength(20);

    cout << "New Area " << r.area() << endl;
    cout << "New Perimeter " << r.perimeter() << endl;

    return 0;
}