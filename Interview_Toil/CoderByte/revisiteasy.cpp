/*
Have the function AlphabetSearching(str) take the str parameter being passed and return the string true if every single letter of the English alphabet exists in the string, otherwise return the string false. For example: if str is "zacxyjbbkfgtbhdaielqrm45pnsowtuv" then your program should return the string true because every character in the alphabet exists in this string even though some characters appear more than once.

 */


#include <bits/stdc++.h>
using namespace std;


string AlphabetSearching(string str) {
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  vector<int> a(26, 0);
  for(char c: str) {
    int num = (int)c;
    if(num > 96 && num < 123) {   // optimization
      a[97-num]++;
    }
  }
  int count = 0;
  for(int i = 0; i < 26; i++) {
    if(a[i]==0) {
      count++;
    }
  }  
  if(count == 0) {
    return "true";
    // cout << "true";
  } else {
    return "false";
    // cout << "false";
  }
}







int main(void) { 

  // string str;
  // cin >> str;
  // AlphabetSearching("zacxyjbbkfgtbhdaielqrm45pnsowtuv");   
  // keep this function call here
  cout << AlphabetSearching("zacxyjbbkfgtbhdaielqrm45pnsowtuv");
  return 0;
    
}