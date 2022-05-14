/*
 * Question: String Rotation
 * Assume you have a method `isSubstring` which checks if one word is a substring of another. Given two strings, `s1` and `s2`.
 * Write code to check if s2 is a rotation of s1 using only one call to isSubstring.
 */

/*
 * Example:
 * - "waterbottle" is a rotation of "erbottlewat".
 */

/*
Hints:
- 34 - If a string is a rotation of another, then it's a rotation of a particular point. For ex., a rotation of waterbottle at character 3 means cutting waterbottle at character 3 and putting the right half (erbottle) before the left half (wat).
- 88 - We are essentially asking if there's a way of splitting the first string into two parts, x and y, such that the first string is xy and the second string is yx. For ex. - x = wat and y = erbottle. The first string is xy = waterbottle. The second string is yx = erbottlewat.
- 104 - Think about the earlier hint. Then think about what happens when you concatenate `erbottlewat` to itself. You get `erbottlewaterbottlewat`. 
*/

/*
 * Stratagies:
 * lets say s1 = xy ==> wat + erbottle
 * similarly s2 = yx ==> erbottle + wat
 * Therefore s1s1 = "waterbottlewaterbottle", clearly s2 is substring of s1s1
 * So if a string is formed by rotation of another string, it will always be substring of concatenated original string to itself.
 */



#include <bits/stdc++.h>
using namespace std;

//-----------------------------------------

/**
 * @brief      prints the vector
 *
 * @param      os      output stream
 * @param[in]  vector  The vector
 *
 * @tparam     T       template
 *
 * @return     prints vector
 */
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vector){
    for(auto element: vector) {
        os << element << " ";
    }
    return os;
}
//-----------------------------------------

/**
 * @brief      1st solution
 *
 * @param      str1  The string 1
 * @param      str2  The string 2
 *
 * @return     True if str1 is rotation of str2, False otherwise.
 */
bool isRotation1(string &str1, string &str2){
    
    if(str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if(str1==str2) return true;
    else return false;
}


/**
 * @brief      2nd solution
 *
 * @param      str1  The string 1
 * @param      str2  The string 2
 *
 * @return     True if str1 is rotation of str2, False otherwise.
 */
bool isRotation2(string &str1, string &str2){
    if(str1.length() != str2.length())
        return false;

    string result;
    result = str2 + str2;
    if(result.find(str1) != string::npos){
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief      3rd solution
 *
 * @param      str1  The string 1
 * @param      str2  The string 2
 *
 * @return     True if str1 is rotation of str2, False otherwise.
 */
bool isRotation3(string &str1, string &str2){

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    vector<int> hash_table1(128,0);
    vector<int> hash_table2(128,0);

    for(char c1: str1){
        hash_table1[(int)c1]++;
    }

    for(char c2: str2){
        hash_table2[(int)c2]++;
    }

    if(hash_table1==hash_table2){
        return true;
    } else {
        return false;
    }

}



int32_t main() {

    string a,b,c,d,e,f;
    a = "waterbottle";
    b = "erbottlewat";
    c = "abc";
    d = "def";
    e = "c++";
    f = "+c+";
    
    cout << boolalpha << isRotation1(a, b) << endl;
    cout << boolalpha << isRotation1(c, d) << endl;
    cout << boolalpha << isRotation1(e, f) << endl << endl;

    cout << boolalpha << isRotation2(a, b) << endl;
    cout << boolalpha << isRotation2(c, d) << endl;
    cout << boolalpha << isRotation2(e, f) << endl << endl;

    cout << boolalpha << isRotation3(a, b) << endl;
    cout << boolalpha << isRotation3(c, d) << endl;
    cout << boolalpha << isRotation3(e, f);
    
    return 0;
}