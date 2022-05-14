// https://leetcode.com/problems/move-zeroes/

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int pos=0;
//         int sz=nums.size();
//         for(int i=0;i<sz;i++){
//             if(nums[i]!=0){
//                 swap(nums[pos],nums[i]);
//                 pos++;
//             }
//         }
//     }
// };

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int pos = 0;
        int sz = nums.size();
        for (auto &i : nums)
        {
            if (i)
            {
                swap(nums[pos++], i);
            }
        }
    }
};