/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        __uint128_t result = 0;
        for (auto d : digits)
        {
            result = result * 10 + d;
        }
        result += 1;
        vector<int> res;
        for (auto c : to_string(result))
        {
            res.push_back(c - '0');
        }
        return res;
    }
};
// @lc code=end
