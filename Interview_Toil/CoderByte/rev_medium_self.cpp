/*
 * Have the function WordSplit(strArr) read the array of strings stored in strArr, which will contain 2 elements: the first element will be a sequence of characters, and the second element will be a long string of comma-separated words, in alphabetical order, that represents a dictionary of some arbitrary length. 
 * For example: strArr can be: ["hellocat", "apple,bat,cat,goodbye,hello,yellow,why"]. Your goal is to determine if the first element in the input can be split into two words, where both words exist in the dictionary that is provided in the second input. In this example, the first element can be split into two words: hello and cat because both of those words are in the dictionary.
 * Your program should return the two words that exist in the dictionary separated by a comma. So for the example above, your program should return hello,cat. There will only be one correct way to split the first element of characters into two words. If there is no way to split string into two words that exist in the dictionary, return the string not possible. 
 * The first element itself will never exist in the dictionary as a real word.
 */


#include <bits/stdc++.h>
using namespace std;


void WordSplit(string strArr[], int arrLength) {

    set<string> wordset;

    stringstream temp(strArr[1]);
    while(temp.good()) {
        string substr;
        getline(temp, substr, ',');
        wordset.insert(substr);
    }


    string target = strArr[0];
    int len1 = strArr[0].length();
    int i = 0;
    string substr1;
    string substr2;
    string result;


    for (int i = 0; i < target.length(); ++i)
    {
        substr1 = target.substr(0,i+1);
        int sublen1 = substr1.length();

        substr2 = target.substr(i+1,len1);
        int sublen2 = substr2.length();
        
        int diff = sublen1-sublen2;

        // cout << substr1 << " " << substr2 << endl;
        for(auto i: wordset) {
            if(substr1 == i && diff>=0) {
                result += i;
                result += ' ';
            } else if (substr2 == i && diff>=0) {
                result += i;
                result += ' ';
            }
        }
    }

    cout << result;
}



int main(void) { 
   
  // keep this function call here
  // string A[] = coderbyteInternalStdinFunction(stdin);
  string A[] = {"hellocat", "apple,bat,cat,goodbye,hello,yellow,why"};
  int arrLength = sizeof(A) / sizeof(*A);
  // cout << WordSplit(A, arrLength);
  WordSplit(A, arrLength);
  return 0;
    
}
