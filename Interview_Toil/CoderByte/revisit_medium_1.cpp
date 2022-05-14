/*
 * Have the function WordSplit(strArr) read the array of strings stored in strArr, which will contain 2 elements: the first element will be a sequence of characters, and the second element will be a long string of comma-separated words, in alphabetical order, that represents a dictionary of some arbitrary length. 
 * For example: strArr can be: ["hellocat", "apple,bat,cat,goodbye,hello,yellow,why"]. Your goal is to determine if the first element in the input can be split into two words, where both words exist in the dictionary that is provided in the second input. In this example, the first element can be split into two words: hello and cat because both of those words are in the dictionary.
 * Your program should return the two words that exist in the dictionary separated by a comma. So for the example above, your program should return hello,cat. There will only be one correct way to split the first element of characters into two words. If there is no way to split string into two words that exist in the dictionary, return the string not possible. 
 * The first element itself will never exist in the dictionary as a real word.
 */

#include <bits/stdc++.h>
using namespace std;

string WordSplit(string strArr[], int arrLength) {

  string target = strArr[0];
  string str1, str2, out;
  bool flag;

  // Loop to analyze each word separated by a comma in the second element/dictionary
  for(int x = 0; x < strArr[1].length(); x++) {
    flag = true;

    // Condition to check for first half
    // We also reset out comparison word/first half in the case we have not found one yet
    if(strArr[1][x] == ',' || x==strArr[1].length()-1) 
    {

      // In case we are working with the last split word in our dictionary
      // Add that last character to our split word
      if(x==strArr[1].length() - 1) {
        str1 += strArr[1][x];
      }
      // Loop to compare the first half with our target world
      for(int y = 0; y < str1.length(); y++) {
        if(target[y] != str1[y]) {
          flag = false;
        }
      }
      // Reset the word if not found
      if(!flag) {
        str1 = "";
      } else {
        int index = str1.length();    // Keeps track of where we need to continue for comparing the second half
        
        // Checks for the second half
        for(int z = 0; z < strArr[1].length(); z++) {

          // Similar condition for when analyzing the first half
          // The commas signify a new split word we can evaluate
          if(strArr[1][z] == ',' || z == strArr[1].length()-1) {
            if(z == strArr[1].length() - 1) {
              str2 += strArr[1][z];
            }

            // Comparing for the second half
            // Assuming the second half exist but we failed, this implies we evaluated the wrong first half
            // The other scenario is that no second half is found at all
            int size;

            // Condition to check if the second half will be a valid case with current first half
            // For example if the length of the 2 split words surpasses the target word ignore that case 
            if(target.length() - index == str2.length()) {
              size = str2.length();
            } else {
              str2 = "";
              continue;
            }
            for(int i = index, k = 0; i < size; i++, k++) {
              if(target[i] != str2[k]) {
                flag = false;
              }
            }
            if(!flag) {
              str2 = "";
            } else {
              // Check that our 2 split words match the target
              out = str1 + str2;
              if(out == target) {
                out = str1 + "," + str2;
                return out;
              } else {
                str2 = "";
              }
            }
          } else {
            str2 += strArr[1][z];
          }
        }
        str1 = "";  // Reset in the case the second half failed
      }
    } else {    // Continue to extract characters before reaching the next comma or the end
      str1 += strArr[1][x];
    }
  }

  return "not possible";
}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << WordSplit(A, arrLength);
  return 0;
    
}