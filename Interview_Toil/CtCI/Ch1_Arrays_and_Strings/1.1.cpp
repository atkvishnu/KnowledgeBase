/*
Question: Is Unique
 Implement an algorithm to determine if a string has all unique characters.
 What if you cannot use additional data structures?
*/

/*
Hints:
- Try a Hash Table.
- Could a bit vector be useful?
- Can you solve this in O(NlogN) time? What might a solution like that look like?
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



bool usingHashTable(string &str){

    int size = str.length();
    // cout << size << endl;


    vector<bool> hash_table(128);

    for (int i = 0; i < size; ++i){
        // cout << str[i] << endl;
        if(hash_table[(int)str[i]]){
            return false;
        }
        hash_table[(int)str[i]] = true;
    }

    // cout << hash_table << endl;

    return true;

}
// rattlesnake

bool usingBitVector(string str){
    bitset<256> b1;
    for (int i = 0; i < str.length(); ++i)
    {
        if(b1.test(str[i]) > 0){
            return false;
        }
        b1.set(str[i]);
    }
    // cout << b1 << endl;
    return true;
}


bool Optimized(string str){     // O(n*logn)
    sort(str.begin(), str.end());       // O(n*logn) sort from <algorithm>

    bool flag = true;
    for (int i = 0; i < str.size() - 1; ++i){
        if(str[i] == str[i+1]){
            flag = false;
            break;
        }
    }

    return flag;
}

bool withSet(string str){
    set<char> characters;
    for(char c: str){
        characters.insert(c);
    }
    if(str.size() == characters.size()){
        return true;
    } else {
        return false;
    }
}


int main(){
    vector<string> solve = {"abcde", "rishu", "saras", "apple", "paddle", "rattlesnake"};

    // 1.
    for(auto i : solve) {
        cout << i << ": " << usingHashTable(i) << endl;
    }
    cout << "\n";

    // 2.
    for(auto i : solve) {
        cout << i << ": " << usingBitVector(i) << endl;
    }
    cout << "\n";
    

    // 3.
    for(auto i : solve) {
        cout << i << ": " << boolalpha << Optimized(i) << endl;
    }
    cout << "\n";

    // 4.
    for(auto i : solve) {
        cout << i << ": " << boolalpha << withSet(i) << endl;
    }
    cout << "\n";

    return 0;
}