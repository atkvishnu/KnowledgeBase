// This question was asked by ContextLogic.

// Implement division of two positive integers without using the division, multiplication, or modulus 
// operators. Return the quotient as an integer, ignoring the remainder.

#include <bits/stdc++.h>
using namespace std;

int division(int num1, int num2)
{
   if (num1 == 0)
       return 0;
   if (num2 == 0)
     return INT_MAX;
 
   bool negResult = false;
 
   // Handling negative numbers
   if (num1 < 0)
   {
       num1 = -num1 ;
       if (num2 < 0)
           num2 = - num2 ;
       else
           negResult = true;
   }
   else if (num2 < 0)
   {
       num2 = - num2 ;
       negResult = true;
   }
 
   // if num1 is greater than equal to num2
   // subtract num2 from num1 and increase
   // quotient by one.
   int quotient = 0;
   while (num1 >= num2)
   {
       num1 = num1 - num2 ;
       quotient++ ;
   }
 
   // checking if neg equals to 1 then making
   // quotient negative
   if (negResult)
        quotient = - quotient ;
   return quotient ;
}
 
// Driver program
int main()
{
    int num1 = 13, num2 = 2 ;
    cout << division(num1, num2); ;
    return 0;
}