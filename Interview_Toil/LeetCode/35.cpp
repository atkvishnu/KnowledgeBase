// https://leetcode.com/problems/search-insert-position/

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int l = 0;
//         int h = nums.size();
//         int probableTarget;
//         while(l<h) {
//             int mid = (l+h)/2;
//             if(nums[mid] == target) return mid;
//             else if(nums[mid]<target){
//                 l = mid+1;
//                 probableTarget = mid+1;
//             }
//             else{
//                 h = mid;
//                 probableTarget = mid;
//             }
//         }
//         return probableTarget;
//     }
// };

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         if (nums.back() < target) return nums.size();
//         int left = 0, right = nums.size();
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] < target) left = mid + 1;
//             else right = mid;
//         }
//         return right;
//     }
// };

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= target)
                return i;
        }
        return nums.size();
    }
};