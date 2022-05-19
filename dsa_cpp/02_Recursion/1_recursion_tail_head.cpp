//TAIL and HEAD recursive functions
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

// This is an example of a tail function
void fun(int n) // This function is recursive because it's calling itself with a reduced value of n. (It's a tail function)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n-1);
    }
}

// // This is an example of a head function
// void fun(int n) // This function is recursive because it's calling itself with a reduced value of n. (It's a head function)
// {
//     if (n > 0)
//     {
//         fun(n-1);
//         printf("%d ", n);
//     }
// } 

int main()
{
    int x = 3;

    fun(x);
    return 0;
}