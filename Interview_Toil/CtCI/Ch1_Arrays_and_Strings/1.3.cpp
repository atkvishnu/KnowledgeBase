/*
Question: URLify
 Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space in the end to hold the characters, and that you are given the "true" length of the string.
 (Note: If implementing in Java, use a character array so that you can perform this operation in place.)
*/

/*
Example:
Input: "Mr    John   Smith       ", 13
Output: "Mr%20John%20Smith"
*/

/*
Hints:
- It's often easiest to modify strings by going from the end of the string to the beginning.
- You might find you need to know the number of spaces. Can you just count them?
*/

#include <bits/stdc++.h>
using namespace std;


void URLify(string &str, int realLen){

    int nSpaces = 0;
    // 1. count the no. of spaces till the realLen of the string
    for(int i = 0; i < realLen; i++){
        if((int)str[i] == 32){
            nSpaces++;
        }
    }

    // 2. modified length of resulting array will be realLen+2*(no. of spaces)
    int modLength = realLen + 2*nSpaces;    // because we need to add 6 spaces, 2 are already present, extra 4 needed
    int i = modLength-1;

    // 3. parsing the string from end, and shifting elements if they are not a <space>, if element is a space "02%" is inserted!
    for (int j = realLen-1; j >= 0; --j){
        if(str[j]!=' '){
            str[i--] = str[j];
        } else {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
    cout << str << endl;
}


int main(){

    string str1 = "Mr John Smith      ";

    URLify(str1, 13);       // Length of str1 without trailing spaces



    return 0;
}






