// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> answer;

        int len1 = nums1.size();
        int len2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        // for(i = 0, j = 0 ; i<nums1.size(), j<nums2.size() ;) {
        while (i < len1 && j < len2)
        {
            if (nums1[i] == nums2[j])
            {
                answer.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return answer;
    }
};