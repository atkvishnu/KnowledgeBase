class Solution:
    def twoSum(self, nums, target):
        dict = {}
        for i in range(len(nums)):
            sub = target - nums[i]
            if sub in dict:
                return dict[sub], i
            dict[nums[i]] = i

if __name__ == '__main__':
    s = Solution()
    print(s.twoSum([2, 7, 11, 15], 9))