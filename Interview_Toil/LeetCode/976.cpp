// https://leetcode.com/problems/largest-perimeter-triangle/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // if(nums[0] == nums[1] == nums[2]) {
        //     return 3*nums[0];
        // }
        // else if (nums[0] == nums[1] || nums[1] == nums[2]) {
        //     if(nums[0]==nums[1]) return 2*nums[0] + nums[2];
        //     if(nums[1] == nums[2]) return 2*nums[1] + nums[0];
        // } else {
        //     return nums[0]+nums[1]+nums[2];
        // }
        // above method cannot be implemented as we are given a array of numbers which can have 3 to 10000 elements.
        // Read the questions properly.
        for (int i = nums.size() - 1; i >= 2; i--)
        { // start @ end and take out 3 numbers at a time
            if (nums[i] < nums[i - 1] + nums[i - 2])
            { // property of triangle: sum of 2 sides is greater than the third side.
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};
