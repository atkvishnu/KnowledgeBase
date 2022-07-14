// https://leetcode.com/problems/reverse-string/

class Solution
{
public:
    void swap(char &a, char &b)
    {
        char temp = a; // O(1) extra space.
        a = b;
        b = temp;
    }
    void reverseString(vector<char> &s)
    {
        int i = 0;
        int j = s.size() - 1;
        for (i, j; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};