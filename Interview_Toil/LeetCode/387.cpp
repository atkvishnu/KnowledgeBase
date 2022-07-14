// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution
{
public:
    int firstUniqChar(string s)
    {

        unordered_map<char, int> u_m;
        // for(int i = 0; i < s.length(); i++) {
        //     u_m[s[i]-97]++;
        // }
        for (char i : s)
            u_m[i]++;
        for (int i = 0; i < s.size(); i++)
        {
            if (u_m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};