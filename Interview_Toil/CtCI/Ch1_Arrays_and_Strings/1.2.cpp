/*
Question: Check Permutation
 Given two strings, write a method to decide if one is a permutation of the other.
*/

/*
Hints:
- Describe what it means for 2 strings to be permutations of each other. Now, look at that definition you provided. Can you check the strings against that definition?
- There is one solution that is O(N log N) time. Another solution uses some space, but is O(N) time.
- Could a hash table be useful?
- Two strings that are permutations should have the same character, but in different orders. Can you make the orders the same?
*/

#include <bits/stdc++.h>
using namespace std;


// prints vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
    for(auto element: vector) {
        os << element << " ";
    }
    return os;
}



bool perm1(string str1, string str2){
    set<char> set1;
    set<char> set2;

    for (int i = 0; i < str1.length()-1; ++i)
    {
        set1.insert(str1[i]);
    }

    for (int i = 0; i < str2.length()-1; ++i)
    {
        set2.insert(str2[i]);
    }

    if(set1 == set2) return true;
    else return false;
}


bool perm2(string str1, string str2) {
    vector<int> hash_table(128, 0);
    vector<int> hash_table2(128, 0);


    // cout << hash_table << endl;

    for (int i = 0; i < str1.length()-1; ++i)
    {
        hash_table[str1[i]]++;
    }

    for (int i = 0; i < str2.length()-1; ++i)
    {
        hash_table2[str2[i]]++;
    }

    // cout << hash_table << endl;

    if(hash_table == hash_table2) {
        return true;
    } else {
        return false;
    }
}


bool perm3(string str1, string str2){
    sort(str1.begin(), str1.begin());
    sort(str2.begin(), str2.begin());
    if(str1==str2){
        return true;
    } else {
        return false;
    }
}




int main(){
    string str1 = "testest";
    // string str2 = "estxest";
    string str2 = "testest";


    if(perm3(str1, str2)){
        cout << "Yes, they are perms." << endl;
    } else {
        cout << "No, they are not perms." << endl;
    }
    // perm2(str1, str2);

}
