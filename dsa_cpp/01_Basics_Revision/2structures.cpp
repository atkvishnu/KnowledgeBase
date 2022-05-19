#include <iostream> 
#include <stdio.h>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
    char x;
};

// struct Rectangle 
// {
//     int length;
//     int breadth;
// } r1, r2, r3;   //This is declaration + initialization. These variables will be global variables!

// struct Rectangle r1, r2, r3;        //we can declare this outside the int main too. This will be global and it will be available for all the program!

int main()
{
    // struct Rectangle r1; //declaration
    struct Rectangle r1 = {10,5};    // Declaration + Initialization
    
    r1.length = 15; //changing length
    r1.breadth = 10;    //changing breadth

    cout << sizeof(r1)<<endl;   // here padding is taking place! because char takes only 1 byte of memory, but computer allocates extra 3 bytes( 4 in total ). This is called PADDING!
    // printf("%lu\n", sizeof(r1));     //%lu is long unsigned because %d will give warnings
    
    //Accessing the members of the structure
    cout << r1.length << ", " << r1.breadth << endl;



     
    return 0;
}