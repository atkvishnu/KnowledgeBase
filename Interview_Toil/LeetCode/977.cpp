// https://leetcode.com/problems/squares-of-a-sorted-array/

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for(int i = 0; i < nums.size(); i++) {
//             nums[i] = nums[i]*nums[i];
//         }
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        std::transform(nums.begin(), nums.end(), nums.begin(), [](int i)
                       { return i * i; });
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};
