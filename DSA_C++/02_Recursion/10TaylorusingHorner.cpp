#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std; 

double e(int x, int n)
{
    static double s = 1;
    
    if(n==0)
        return s;
    s = 1+x*s/n;
    return e(x,n-1);
}

int main()
{
    cout << e(3,15);
    return 0;
}