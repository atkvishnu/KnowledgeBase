# Given an array of ints, return the number of 9's in the array.
#
#
# array_count9([1, 2, 9]) → 1
# array_count9([1, 9, 9]) → 2
# array_count9([1, 9, 9, 3, 9]) → 3

def array_count9(nums):
    num = 9
    count = 0
    if len(nums) == 0:
        return 0
    else:
        for i in range(0, len(nums)):
            x = nums[i]
            # print(x)
            if x == num:
                count = count + 1
        print(count)

# print(count)
# print(x)
# print(nums[i])

array_count9([1, 2, 9, 9, 9,9,1,2,3,4,'',5,9])


#_______________________________________________OR

# def array_count9(nums):
#     num = 9
#     count = 0
#
#     if len(nums) == 0:
#         return 0
#
#     else:
#         for i in range(0, len(nums)):
#             x = nums[i]
#             if x == num:
#                 count = count + 1
#         return count
