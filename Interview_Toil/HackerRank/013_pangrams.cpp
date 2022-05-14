#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s)
{
    string res;
    vector<int> hash(26, 0);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
    int sz = s.length();
    for (int i = 0; i < sz; i++)
    {
        if (s[i] != ' ')
        {
            hash[s[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (hash[i] < 1)
        {
            res = "not pangram";
        }
    }
    if (res != "not pangram")
        res = "pangram";
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
