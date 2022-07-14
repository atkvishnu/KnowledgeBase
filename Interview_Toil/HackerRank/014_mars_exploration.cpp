#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    // if(s.length()%3!=0) return -1;
    int count = 0;
    // for(char c: s) {
    //     if(c!='S' and c!='O') count++;
    // }
    for (int i = 0; i < s.length(); i = i + 3) {
        if(s[i] != 'S') count++;
        if(s[i+1] != 'O') count++;
        if(s[i+2] != 'S') count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
