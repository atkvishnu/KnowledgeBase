// https://leetcode.com/problems/binary-search/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int h = nums.size();
        while (l < h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }
        return -1;
    }
};