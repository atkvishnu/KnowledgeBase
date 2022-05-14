// Q1 ->  Find the missing element in a sorted array
// Array is a sequence of n natural numbers
// We have been given the length of the array.

// NOTE: This is the case where only one element is missing.

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int main()
{
    int A[] = {1,2,3,4,5,6,8,9,10,11,12};

    int lastElement = 12;
    float missingNumber;

    float sum = 0;
    for(int i=0; i<lastElement;i++)
        sum += A[i];
    
    // We know: Sum of n natural numbers: n(n-1)/2
    float sumN = lastElement*(lastElement-1)/2;

    if(sumN!=sum){
        missingNumber = sum - sumN;
        cout << "Missing number is: " << missingNumber;
    }
    else
        cout << "No numbers are missing!"; 

    return 0;
}