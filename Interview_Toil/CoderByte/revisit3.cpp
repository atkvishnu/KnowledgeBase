/*
 Have the function PolynomialExpansion(str) take str which will be a string representing a polynomial containing only (+/-) integers, a letter, parenthesis, and the symbol "^", and return it in expanded form. For example: if str is "(2x^2+4)(6x^3+3)", then the output should be "12x^5+24x^3+6x^2+12". Both the input and output should contain no spaces. The input will only contain one letter, such as "x", "y", "b", etc. There will only be four parenthesis in the input and your output should contain no parenthesis. The output should be returned with the highest exponential element first down to the lowest.

More generally, the form of str will be: ([+/-]{num}[{letter}[{^}[+/-]{num}]]...[[+/-]{num}]...)(copy) where "[]" represents optional features, "{}" represents mandatory features, "num" represents integers and "letter" represents letters such as "x".

 */


#include <bits/stdc++.h>using namespace std;



string PolynomialExpansion(string str) {

  // vector<int> v1, v2;
  // for(int i = 0; i < str.length(); i++) {
  //   if(str[i]=='(') {
  //     v1.push_back(i);
  //   } else if (str[i] == ')') {
  //     v2.push_back(i);
  //   }
  // }

  // int i = 0;
  // int j = 0;
  // vector<string> vec_str;
  // for(int k = v1[i], l = v2[j]; k > v1.size(), l > v2.size(); k++, l++) {
  //   vec_str.push_back(str[])
  // }
  multimap<int, int> vals;
  int i = 0;
  int j = 1;
  int len = str.length();
  int coeff;
  int pow;
  pair<int, int> node;
  vector<int> coeff1;
  vector<int> pow1;
  vector<pair<int,int>> eq;
  for(int i = 0; i < str.length; i++) {
    if(str[i]=='x' && str[i+1]!='^') {
      node.first = str[i-1];
      node.second = 1;
      eq.push_back(node);
    } else if(str[i]=='x' && str[i+1]=='-') {
      node.first = -str[i+2];
      node.second = str[i-1];
      eq.push_back(node);
    } else if (str[i] == '+')
  }


  // code goes here  
  return str;

}

int main(void) { 
   
  // keep this function call here
  cout << PolynomialExpansion(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}