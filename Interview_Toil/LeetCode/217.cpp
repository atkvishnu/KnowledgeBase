// https://leetcode.com/problems/contains-duplicate/

// Method 1: using a flag
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         bool flag = false;
//         for(int i = 0; i < nums.size()-1; i++) {
//             if(nums[i] == nums[i+1]) {
//                 flag = true;
//             }
//         }
//         return flag;
//     }
// };

// Method 2: using set, unordered_set
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        // set<int> s(nums.begin(), nums.end());
        // if(s.size() != nums.size()) return true;
        // return false;
        return (s.size() != nums.size());
    }
};