// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int sz = numbers.size();
//         for(int i = 0; i < sz; i++) {
//             int l = i+1;
//             int h = sz;
//             int req = target - numbers[i];
//             while(l<h) {
//                 int mid = l + (h-l) / 2;
//                 if(req == numbers[mid]) return {i+1, mid+1};
//                 else if (req < numbers[mid]) h = mid;
//                 else l = mid+1;
//             }
//         }
//         return {};
//     }
// };

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r)
        {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
                return {l + 1, r + 1};
            else if (sum < target)
                l++;
            else
                r--;
        }
        return {};
    }
};