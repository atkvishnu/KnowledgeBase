/*
Input Format

Input consists of the following space-separated values: int, long, char, float, and double, respectively.

Output Format

Print each element on a new line in the same order it was received as input.
Note that the floating point value should be correct up to 3 decimal places and the double to 9 decimal places.

Sample Input

3 12345678912345 a 334.23 14049.30493
Sample Output

3
12345678912345
a
334.230
14049.304930000
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Complete the code.
    int i;
    long l;
    char ch;
    float f;
    double d;
    cin >> i >> l >> ch >> f >> d;
    cout << i << endl
         << l << endl
         << ch << endl;
    cout << fixed << setprecision(9) << f << endl; // floating point value should be correct up to 3 decimal places
    cout << fixed << setprecision(3) << d;         // double to 9 decimal places.
    return 0;
}