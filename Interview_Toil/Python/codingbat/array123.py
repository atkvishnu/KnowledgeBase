# Given an array of ints, return True if the sequence of
# numbers 1, 2, 3 appears in the array somewhere.
#
#
# array123([1, 1, 2, 3, 1]) → True
# array123([1, 1, 2, 4, 1]) → False
# array123([1, 1, 2, 1, 2, 3]) → True

# def array123(nums):
#
#     string_123 = [1, 2, 3]
#     three_nos = []
#
#     if len(nums) < 3:
#         return False
#     else:
#         for i in range(0, len(nums)-2):
#             three_nos = [nums[i], nums[i + 1], nums[i + 2]]
#             print(three_nos)
#             if three_nos == string_123:
#                 print('True')
#                 # return True
#             else:
#                 print('False')
#                 # return False
#     # print(three_nos)
#
#
# # array123([1, 1, 2, 1, 2, 3])
# array123([1, 1, 2, 3, 1])
#_____________________________________________________OR| 1st not working
# Working solution

def array123(nums):
    for i in range(len(nums) - 2):
        if nums[i] == 1 and nums[i + 1] == 2 and nums[i + 2] == 3:
            return True
    return False