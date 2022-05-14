// https://leetcode.com/problems/rotate-array/

class Solution
{
public:
    //     void rotate(vector<int>& nums, int k) {
    //         int sz = nums.size();
    //         k = k%sz;
    //         vector<int> temp;
    //         for(int i = sz-1; i>=0; i--)
    //         {
    //             int n = temp.size();
    //             if(i-k<0) {
    //                 nums[i] = temp[k-i-1];
    //             }
    //             else if(i-k>=0) {
    //                 temp.push_back(nums[i]);
    //                 nums[i] = nums[i-k];
    //             }
    //         }

    //     }
    void rotate(vector<int> &nums, int k)
    { // ingenious solution
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};