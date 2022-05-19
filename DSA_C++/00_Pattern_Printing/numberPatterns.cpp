// Print a pattern without using any loop

//Given a number n, print following a pattern without using any loop.

// Input: n = 16
// Output: 16, 11, 6, 1, -4, 1, 6, 11, 16

// Input: n = 10
// Output: 10, 5, 0, 5, 10

// We first reduce 5 one by one until we reach a negative or 0. 
// After we reach 0 or negative, we one add 5 until we reach n.

#include <iostream>
using namespace std;
 
// Recursive function to print the pattern.
// n indicates input value
// m indicates current value to be printed
// flag indicates whether we need to add 5 or
// subtract 5. Initially flag is true.
void printPattern(int n, int m, bool flag)
{
    // Print m.
    cout << m << " ";
     
    // If we are moving back toward the n and
    // we have reached there, then we are done
    if (flag == false && n ==m)
        return;
     
    // If we are moving toward 0 or negative.
    if (flag)
    {
    // If m is greater, then 5, recur with true flag
    if (m-5 > 0)
        printPattern(n, m-5, true);
    else // recur with false flag
        printPattern(n, m-5, false);
    }
    else // If flag is false.
        printPattern(n, m+5, false);
}
 
// Recursive function to print the pattern
// variance where m is the input int32 value
void PrintPattern(int m)
{
    if (m > 0)
    {
        cout << m << '\n';
        PrintPattern(m - 5);
    }
 
    cout << m << '\n';
}
 
// Driver Program
int main()
{
    int n = 16;
    //printPattern(n, n, true);
    PrintPattern(n);
    return 0;
}