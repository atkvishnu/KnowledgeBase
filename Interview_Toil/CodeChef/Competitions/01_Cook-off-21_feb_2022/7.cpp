// https://www.codechef.com/COOK138D/problems/PERMEX
#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    string s;
    cin >> n >> s;
    if (s[0] == '0' || s[1] == '0' || s[n] == '0') {
        cout << "No" << endl;
        return;
    }
    vector < int > vec;
    vec.push_back(0);
    int hold = 1;
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == '0') vec.push_back(i);
        else {
            vec.push_back(hold);
            hold = i;
        }
    }
    vec.push_back(hold);
    cout << "Yes" << endl;
    for (auto it: vec)
        cout << it << " ";
    cout << endl;
}

int main() {
    int ht;
    cin >> ht;

    for (int i = 0; i < ht; i++) {
        solve();
    }

    return 0;
}