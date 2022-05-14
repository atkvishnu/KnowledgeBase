// https://leetcode.com/problems/maximum-subarray/

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//             int max_so_far = INT_MIN, max_ending_here = 0;

//             for (int i = 0; i < nums.size(); i++)
//             {
//                 max_ending_here = max_ending_here + nums[i];
//                 if (max_so_far < max_ending_here)
//                     max_so_far = max_ending_here;

//                 if (max_ending_here < 0)
//                     max_ending_here = 0;
//             }
//             return max_so_far;
//     }
// };

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int cs = nums[0], ms = nums[0];
//         for(int i=1; i<nums.size(); i++)
//         {
//             cs = max(nums[i], cs+nums[i]);
//             ms = max(cs,ms);
//         }
//         return ms;
//     }
// };

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0];
        int temp = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            temp += nums[i];
            ans = max(ans, temp);
            if (temp < 0)
                temp = 0;
        }
        return ans;
    }
};
