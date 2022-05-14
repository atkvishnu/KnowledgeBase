// The last program works fine and prints the desired output but it uses extra variables. 
// We can use two print statements. 
// First one before the recursive call that prints all decreasing sequence. 
// The second one after the recursive call to print increasing sequence.

// C++ program to print pattern that first reduces 5 one by one, then adds 5. Without any loop an extra variable.

#include <iostream>
using namespace std;
 
// Recursive function to print the pattern without any extra variable
void printPattern(int n)
{
    // Base case (When n becomes 0 or negative)
    if (n ==0 || n<0)
    {
        cout << n << " ";
        return;
    }
     
    // prints decreasing order
    cout << n << " ";
    printPattern(n-5); 
 
    // prints increasing order
    cout << n << " ";
}

int main()
{
    int n = 16;
    printPattern(n);
    return 0;
}