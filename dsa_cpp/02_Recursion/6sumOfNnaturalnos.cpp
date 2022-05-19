#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

// Sum of N natural numbers using recursion
int sum(int n)
{
    if (n == 0)
        return 0;
    return sum(n-1)+n;
}

// Sum of N natural numbers using iterative method (using loops)
int Isum(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        sum += i;
    }
    return sum;
}


int main()
{
    cout << sum(5) << " ";
    cout << Isum(5);
    return 0;
}