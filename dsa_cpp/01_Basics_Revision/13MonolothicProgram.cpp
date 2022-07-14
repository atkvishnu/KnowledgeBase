// 1st STYLE OF PROGRAMMING
// MONOLITHIC STYLE OF PROGRAMMING

// CALCULATING THE AREA AND PERIMETER OF A RECTANGLE
// LENGTH AND BREADTH WILL BE TAKEN AS INPUT FROM THE USER
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int main()
{
    int length = 0; int breadth = 0;        //Initializing variables as 0 before declaring is a good practice!

    printf("Enter the length and breadth: ");
    cin >> length >> breadth;

    int area = length * breadth;
    int peri = 2*(length+breadth);

    printf("Area = %d \n Perimeter = %d \n", area, peri);

    return 0;
}