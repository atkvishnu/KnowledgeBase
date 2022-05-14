/*
 * 1. Have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order. 
 *
 * 
 * Complexity Analysis:
 * 
 * Time Complexity: O(n/2) - because we are traversing the string from both sides till it reaches the mid point
 * Space Complexity: O(1) - because no extra space is required. Swapping is happening in-place!
 * 
 * `n` is the length of the string
 */


#include <iostream>
#include <string>
using namespace std;

void swap(char &a, char &b) {
	char temp;		// extra space: 1 char variable
	temp = a;
	a = b;
	b = temp;
}

string FirstReverse(string str) {
	int i = 0;
	int j = str.length()-1;
	for (i,j; i<j; i++, j--){	// in-place swapping.
		swap(str[i],str[j]);
	}
	// cout << str << endl;
	return str;
}

int main() 
{
	// string str;
	// cin >> str;
	// FirstReverse(str);
	cout << FirstReverse("coderbyte");
	return 0;
}