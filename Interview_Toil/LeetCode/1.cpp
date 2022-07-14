// https://leetcode.com/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int req = target - nums[i];
            if (m.count(req) && m[req] != i)
            {
                res.push_back(i);
                res.push_back(m[req]);
                break;
            }
        }
        return res;
    }
};