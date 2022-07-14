#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

int power(int m, int n)
{
    if(n==0)
        return 1;
    return power(m,n-1)*m;
}


//This takes less number of multiplication than normal recursion
int power1( int m, int n)
{
    if(n==0)
        return 1;
    if(n%2 == 0)
        return power1(m*m,n/2);
    else
        return m*(power1(m*m,(n-1)/2));
}

int main()
{
    cout << power(2,4)<<" ";
    cout << power1(2,3);
    return 0;
}