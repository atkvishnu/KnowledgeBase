//Q -> Multiple missing elements in a sorted array
// A[] = [6,7,8,9,11,12,15,16,17,18,19]
// i      0,1,2,3, 4, 5, 6, 7, 8, 9,10

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int main()
{
    int A[] = {6,7,8,9,11,12,15,16,17,18,19};               //missing elems - 10,13,14
    int l =  6;
    int h = 19;
    int n = 11;

    int diff = l - 0;

    for(int i = 0; i<n;i++)
    {
        if(A[i]-i!=diff)
        {
            while(diff<A[i]-i)
            {
                cout << "Missing number is: " << i+diff << endl;
                diff++;
            }
        }
    }

    return 0;
}

// Time Complexity: O(n)
// Only major time consumer is for loop!
// while loop won't take that much time, even if array size is humoungous!