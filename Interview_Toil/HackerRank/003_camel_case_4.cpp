// GOD DAYUMN
/*
- I had to refer the discussion page because 1/2 test case was failing.
- The testcase which was not passing had extra return characters which had to be removed before executing our function.
- Understand this type of edge cases.
- It was Very hard to debug because the test case was hidden.

- Code added from discussion page:
```cpp
int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT
    // for (string line; getline(cin, line);) {
    //       analyzeString(line);
    // }
    string str;
    vector<string> vec;
    while(getline(cin, str)) {
        str.erase(remove(str.begin(), str.end(), '\r'), str.end() );
        str.erase(remove(str.begin(), str.end(), '\t'), str.end() );
        str.erase(remove(str.begin(), str.end(), '\n'), str.end() );
        vec.push_back(str);
    }
    for (const auto & e : vec) analyzeString(e);

    return 0;
}
```
*/

#include <bits/stdc++.h>
using namespace std;

// trim from start (in place)
static inline void ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                    { return !std::isspace(ch); }));
}

// trim from end (in place)
static inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}

void splitMethod(string str)
{
    string res = "";
    for (int i = 4; i < (int)str.length() - 2; i++)
    {
        if (!isupper(str[i]))
        {
            res += str[i];
        }
        else if (isupper(str[i]))
        {
            res += ' ';
            res += (str[i] + 32); // converts str[i] to lowercase     'A'-'a' = 32
        }
    }
    trim(res);
    cout << res << endl;
}

void splitClass(string str)
{
    string res = "";
    res += (str[4] + 32);
    for (int i = 5; i < (int)str.length(); i++)
    {
        if (!isupper(str[i]))
        {
            res += str[i];
        }
        else if (isupper(str[i]))
        {
            res += ' ';
            res += (str[i] + 32); // converts str[i] to lowercase
        }
    }
    trim(res);
    cout << res << endl;
}

void splitVariable(string str)
{ // iPad
    string res = "";
    for (int i = 4; i < (int)str.length(); i++)
    {
        if (!isupper(str[i]))
        {
            res += str[i];
        }
        else if (isupper(str[i]))
        {
            res += ' ';
            res += (str[i] + 32);
        }
    }
    trim(res);
    cout << res << endl;
} // i pad

void combineMethod(string str)
{
    string res = "";
    for (int i = 4; i < (int)str.length(); i++)
    {
        if (str[i] != ' ')
        {
            res += str[i];
        }
        else
        {
            i++;
            res += toupper(str[i]);
        }
    }
    trim(res);
    cout << res << "()" << endl;
}

void combineClass(string str)
{
    string res = "";
    res += toupper(str[4]);
    for (int i = 5; i < (int)str.length(); i++)
    {
        if (str[i] != ' ')
        {
            res += str[i];
        }
        else
        {
            i++;
            res += toupper(str[i]);
        }
    }
    trim(res);
    cout << res << endl;
}

void combineVariable(string str)
{
    string res = "";
    for (int i = 4; i < (int)str.length(); i++)
    {
        if (str[i] != ' ')
        {
            res += str[i];
        }
        else
        {
            i++;
            res += toupper(str[i]);
        }
    }
    trim(res);
    cout << res << endl;
}

void analyzeString(string str)
{
    if (str[0] == 'S' && str[2] == 'M')
    {
        splitMethod(str);
    }
    else if (str[0] == 'S' && str[2] == 'C')
    {
        splitClass(str);
    }
    else if (str[0] == 'S' && str[2] == 'V')
    {
        splitVariable(str);
    }
    else if (str[0] == 'C' && str[2] == 'M')
    {
        combineMethod(str);
    }
    else if (str[0] == 'C' && str[2] == 'C')
    {
        combineClass(str);
    }
    else if (str[0] == 'C' && str[2] == 'V')
    {
        combineVariable(str);
    }
}

// int main()
// {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     // for (string line; getline(cin, line);) {
//     //       analyzeString(line);
//     // }
//     string str = "S;V;pictureFrame";
//     analyzeString(str);

//     return 0;
// }

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // for (string str; getline(cin, str);) {
    //       analyzeString(str);
    // }
    string str;
    vector<string> vec;
    while (getline(cin, str))
    {
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), '\t'), str.end());
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        vec.push_back(str);
    }
    for (const auto &e : vec)
        analyzeString(e);

    return 0;
}
