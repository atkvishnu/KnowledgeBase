// Pyramid pattern

// Suppose we have a matrix of order 4x7

//   1 2 3 4 5 6 7
// 1 . . . * . . .
// 2 . . * * * . .
// 3 . * * * * * .
// 4 * * * * * * *

// r and i are initialized to 1 globally

// i increments from 1 to n*(2n-1) 

// print * only if:   mod( (i-(2n-1)*(r-1))-n ) < row
// otherwise print "<space>"

// In each row ... 1 to 2n-1, here from 1 to 7
// I have used i-(2n-1)*(r-1) to create 1-7 series. And we do r+=1 after each row.

// if | i-(2n-1)*(r-1) -n | < r , only then print *

// In C, we don't have a method to take mod of a negative number, therefore, sqrt(pow(x,2)), will return the mod value...


#include <bits/stdc++.h> 

using namespace std; 

int i = 1, r = 1, n;

void pattern()
{

    ((int)sqrt(pow((i-(2*n-1)*(r-1)-n),2))<r) ? cout << "*" : cout << " ";

    if(((i-2*n-1)*(r-1))%(2*n-1)==0)
        printf("\n", r++);

    if(i++<n*(2*n-1))
        pattern();

}

int main()
{
    cout << "Enter the value: ";
    cin >> n;

    pattern();

    return 0;
}