/*
Question: String Compression
 Implement a method to perform basic string compression using the counts of repeated characters.
 For example, the string `aabcccccaaa` would become `a2b1c5a3`.
 If the "compressed" string would not become smaller than the original string, your method should return the original string.
 You can assume the string has only uppercase and lowercase (a-z).  
*/

/*
Hints:
- Do the easy thing first. Compress the string, then compare the lengths.
- Be careful that you aren't repeatedly concatenating strings together. This can be very inefficient.
*/

/*
Stratagies:
- hash table. increment hash_table[i] if a[i] == a[i+1]. 
- pointer. if str[i]==str[i+1], then count++.... If str[i]!=str[i+1], reset counter and concatenate the str[i] and counter.    
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

string compress1(string &str){

    if(str.length() < 2) {
        return str;
    }

    string output = "";

    vector<int> hash_table(128, 0);
    for(char c: str){
        hash_table[(int)c]++;
    }

    for (int i = 0; i < hash_table.size(); ++i)
    {
        if(hash_table[i]!=0){
            char chars = (char)i;
            output += chars;
            output += to_string(hash_table[i]);
        }
    }
    return output;
}


// ??? WTF was this??  REFLECT:
// string compress2(string &str){
//     // - pointer. if str[i]==str[i+1], then count++.... If str[i]!=str[i+1], reset counter and concatenate the str[i] and counter.    
//     int counter1 = 0;
//     string output1 = "";
//     // for (int i = 0; i < str.length(); ++i)
//     // {
//     //     if(str[i]==str[i+1]){
//     //         counter++;
//     //     }

//     // }
//     int n = str.length(); 
//     int i = 0;
//     do {        
//         if(str[i]==str[i+1]){
//             counter1++;
//             n--;
//             i++;
//             cout << str[i] << endl;
//         } else {
//             output1 += str[i];
//             output1 += to_string(counter1);
//             counter1 = 0;
//         }
//     } while(i < n);
//     cout << output1 << endl;
//     return output1;
// }



int main()
{
    std::string str, out;
    std::cout << "Enter a string:\n";
    std::cin >> str;
    out = compress1(str);
    if (str.compare(out)) {
        std::cout << str << " can be compressed to " << out << std::endl;
    } else {
        std::cout << str << " can not be compressed\n";
    }

    // cout << compress2(str);


    return 0;
}






