/**
 * @Question   2. First Factorial
 *
 * @brief      // For this challenge you will be determining the factorial for a given number.
 *
 * @author     atkumarvishnu
 * @date       17-03-2022
 */

#include <iostream>
using namespace std;

// Method 1: Recursion
// works when num<40
unsigned long long FirstFactorial(long long num) {

	if(num==0) return 1;
	return num*FirstFactorial(num-1);
}


int main() 
{
	cout << FirstFactorial(40);
	return 0;
}