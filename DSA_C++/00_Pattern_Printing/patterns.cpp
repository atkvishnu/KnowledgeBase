// HOW TO APPROACH PATTERN PRINTING PROBLEMS:

// 1. no. of lines = no. of rows = no. of times outer loop will run

// 2. Identify for every row number:
//    - How many columns are there
//    - Types of elements in columns

// 3. What do you need to print??

// Example:
//      columns ->
// r  *
// o  * *
// w  * * *
// |  * * * *
// v

// Total = 4 rows

// 1st row -> 1 col
// 2nd row -> 2 cols
// 3rd row -> 3 cols
// 4th row -> 4 cols



#include <iostream> 

using namespace std; 

// patter0 -> triangle
void pattern0(int n)
{
    for(int row = 0; row < n; row++){
        //for every row run the column
        for(int col=0; col < row+1; col++){
            cout << "* ";
        }
        //when one row is printed we need to add a new line
        cout << "\n";
    }
}

// pattern1 -> square
void pattern1(int n)
{
    for(int row = 0; row < n; row++){
        //for every row run the column
        for(int col = 0; col < n; col++){
            cout << "* ";
        }
        //when one row is printed we need to add a new line
        cout << "\n";
    }
}

// pattern2 -> inverseTriangle
void pattern2(int n)
{
    for(int row = 0; row < n; row++){         //0   1   2   3
        //for every row run the column
        for(int col=0; col < n-row; col++){     //0->(4-0=4), 0->(4-1=3), 0->(4-2=2), 0->(4-3=1)
            cout << "* ";
        }
        //when one row is printed we need to add a new line
        cout << "\n";
    }
}

void pattern3(int n)
{
    for(int row = 0; row < n; row++)
    {
        //for every row run the column
        for(int col=0; col < row+1; col++)
        {
            cout << col+1 << " ";
        }
        //when one row is printed we need to add a new line
        cout << "\n";
    }
}

void pattern4(int n)
{
    for(int row = 0; row < n; row++)
    {
        //for every row run the column
        for(int col=0; col < row+1; col++)
        {
            cout << "* ";
        }
        //when one row is printed we need to add a new line
        cout << "\n";
    }
    for(int row = 0; row < n-1; row++)
    {
        for(int col = 0; col < n-row-1; col++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

void pattern4(int n)
{
    for(int row = 0; row < 2*n; row++)
    {
        //for every row run the column
        for(int col=0; col < row+1; col++)
        {
            cout << "* ";
        }
        //when one row is printed we need to add a new line
        cout << "\n";
    }
}

int main()
{
    cout << '\n';

    pattern0(4);
    cout << '\n';

    pattern1(4);
    cout << '\n';
    
    pattern2(4);
    cout << '\n';

    pattern3(5);
    cout << '\n';

    pattern4(5);
    cout << '\n';

    
    return 0;
}