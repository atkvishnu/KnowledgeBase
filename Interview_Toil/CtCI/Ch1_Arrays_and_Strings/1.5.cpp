/*
Question: One Away
 There are 3 types of edits that can be performed on strings: insert a character, remove a character, OR, replace a character.
 Given two strings, write a function to check if they are one edit(or zero edits) away.
*/

/*
Example:
Input        -> Output 
pale, ple    -> true
pales, pale  -> true
pale, bale   -> true
pale, bake   -> false
*/

/*
Hints:
- Start with the easy thing. Can you check each of the conditions separately?
- What is the relationship b/w the "insert character" option and "remove character" option? Do these need to be 2 separate checks?
- Can you do all the three checks in a single pass?
*/

/*
Stratagies:
- Can use 2 pointers, one on each string and parse to check 3rd condn., 1st and 2nd condn. can be checked by difference in length of 2 strings
* insert  : size++
* remove  : size--
* replace : use 2 pointers
*/


#include <bits/stdc++.h>
using namespace std;


int oneAway(string &str1, string &str2){
    int len1 = str1.length();
    int len2 = str2.length();

    if((abs(len1-len2) > 1)){       // check 1 and 2
        return false;
        exit(1);
    }

    string greater = len1 >= len2 ? str1 : str2;
    string lesser = len1 < len2 ? str1 : str2;

    int i, j;
    bool flag = false;
    for (i = 0, j = 0; i < len1 && j < len2;){     // check 3
        if(greater[i]!=lesser[j]){
            if(flag){
                return false;
            } 
            flag = true;
            if(len1 == len2)
                i++,j++;
            else
                i++;        //move lesser pointer if its a match, dont move it in case of first mismatch
        } 
        else {
            i++, j++;       
        }
    }
    return true;
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;        // pale ple(true); pales pale(true); pale bale(true); pale bake(false)
    if(oneAway(str1, str2)){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}