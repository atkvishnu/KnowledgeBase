/*
Question: Palindrome Permutation
 Given a string, write a function to check if it is a permutation of a palindrome.
 A palindrome is a word/phrase that is the same forward and backward.
 A permutation is a rearrangement of letters.
 The palindrome doesn't need to be limited to just dictionary words!
*/

/*
Example:
Input: Tact Coa
Output: True (permutations: "taco cat", "atco cta", etc.)
*/

/*
Hints:
- You do not have to -- and should not -- generate all permyutations. This would be very inefficient.
- What characteristics would a string that is a permuation of a palindrome have?
- Try a Hash table? You should be able to get this down to O(N) time.
- Can you reduce the space usage by using a bit vector?
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
    for(auto element: vector) {
        os << element << " ";
    }
    return os;
}




bool isPermutationOfPallindrome1(string &str) {     // O(N/2)

    set<char> set1;
    set<char> set2;

    for (int i = 0; i < str.length()/2; ++i){   // O(N/2)
        set1.insert(str[i]);
    }
    for (int i = str.length()/2; i < str.length(); ++i){  // O(N/2)
        set2.insert(str[i]);
    }

    if(set1.size()==set2.size()) {
        return true;
    } else {
        return false;
    }
}


bool isPermutationOfPallindrome2(string &str) {         //        --O(N)
    transform(str.begin(), str.end(), str.begin(), ::tolower);  // to lowercase     --O(N)

    vector<int> hash_table(128, 0);
    for (int i = 0; i < str.length(); ++i)                                //        --O(N)
    {
        hash_table[(int)str[i]]++;
    }
    // cout << hash_table << endl;

    int counter = 0;    // counter for middle element (max. allowed 1)
    for (int i = 97; i < hash_table.size(); ++i)                    
    {
        if(hash_table[i]%2!=0){ // if elements odd then increment counter 
            counter+=1;
        }
    }
    if(counter > 1){    // if there is only 1 element with odd count (middle element), then it's a palindrome. Because (elements of LHS = elements on RHS)
        return false;
    } else {            // if counter is more than 1, then it's not a palindrome.
        return true;
    }
}


bool isPermutationOfPallindrome3(string &str) {         //bitset occupies 1/8th space as compared to hash_table made out of vector/array because it stores only bits (bit = 1/8*char)!

    bitset<26> frequency_table;
    for(char c: str){
        char cl = tolower(c);
        int cNum = (int)cl-96;  // range: 1-26  // -96 because bitset is starting 1, not 0. else it would have been -97.
        if(cNum >=0 && cNum<=25){
            frequency_table.flip(cNum);     // bitset starts from right towards left. Starting index is 1!
        }
    }
    int countOdd = 0;
    for (int i = 0; i < frequency_table.size(); ++i)
    {
        if(frequency_table.test(i)){
            countOdd++;
        }
    }
    if(countOdd > 1){
        return false;
    } else {
        return true;
    }
}








int main()
{
    
    std::string str("Tact Coa");
    std::cout << "Does \"" << str << "\"  has a string whose permutation is a palindrome? "
              << "( 1 for true, 0 for false ) : ";
    std::cout << "Approach 1:" << isPermutationOfPallindrome1( str ) << std::endl;
    std::cout << "Approach 2:" << isPermutationOfPallindrome2( str ) << std::endl;
    std::cout << "Approach 3:" << isPermutationOfPallindrome3( str ) << std::endl;


    std::string str1("A big Cat");
    std::cout << "Does \"" << str1 << "\" has a string whose permutation is a palindrome? "
              << "( 1 for true, 0 for false ) : ";
    std::cout << "Approach 1:" << isPermutationOfPallindrome1( str1 ) << std::endl;
    std::cout << "Approach 2:" << isPermutationOfPallindrome2( str1 ) << std::endl;
    std::cout << "Approach 3:" << isPermutationOfPallindrome3( str1 ) << std::endl;


    std::string str2("Aba cbc");
    std::cout << "Does \"" << str2 << "\" has a string whose permutation is a palindrome? "
              << "( 1 for true, 0 for false ) : ";
    std::cout << "Approach 1:" << isPermutationOfPallindrome1( str2 ) << std::endl;
    std::cout << "Approach 2:" << isPermutationOfPallindrome2( str2 ) << std::endl;
    std::cout << "Approach 3:" << isPermutationOfPallindrome3( str2 ) << std::endl;
    

    return 0;
}