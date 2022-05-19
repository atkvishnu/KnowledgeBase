// Q2-> Elements are not n natural numbers 
// They can start from anywhere, one lement is missing
// Given A[first], A[last], number of elements

//A[i]  //6->7->8->9->10->11->13->14->15->16->17
//i     //0->1->2->3-> 4-> 5->6 -> 7->8 -> 9->10
//A[i]-i//6  6  6  6  6    6  7   7   7    7   7

// We subtract A[i]-i

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int main()
{
    int A[] = {6,7,8,9,10,11,13,14,15,16,17};
    int l = 6;
    int h = 17;
    int n = 11;
    int diff = l - 0;   //

    for(int i = 0; i<n;i++)
    {
        if((A[i]-i)!=diff)
        {
            cout <<"Missing element: " << i+diff;
            break;
        }
    }
    return 0;
}