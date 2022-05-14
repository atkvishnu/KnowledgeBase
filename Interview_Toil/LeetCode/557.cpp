// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0, end = 0, n = s.size();
        while (start < n && end < n)
        {
            while (end < n && s[end] != ' ')
                ++end;
            for (int i = start, j = end - 1; i < j; ++i, --j)
            {
                swap(s[i], s[j]);
            }
            start = ++end;
        }
        return s;
    }
};