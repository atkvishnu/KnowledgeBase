# When program deals with numbers which have fraction part we sometimes want to
# round such values to whole integer. We'll need this for programming some later
# problems (to make answers simpler, for example), so let us have the following
# dedicated exercise to learn this trick.
#
# There are several pairs of numbers. For each pair you are to divide first by
# second and return the result, rounded to the nearest integer.
#
# In cases, when result contains exactly 0.5 as a fraction part, value should
# be rounded up (i.e. by adding another 0.5). Note that for negative values
# "greater" means "closer to zero". Refer to the Wikipedia page on Rounding
# for more thorough explanations.
#
# In any further problems, when rounding is mentioned - just the same
# rounding algorithm is supposed (unless other is explicitly specified).
#
# Input data will give a number of test-cases in the first line.
# Next lines will contain one test-case (i.e. the pair of numbers) each.
# Answer should contain division-and-rounding results for each pair, separated with spaces
#
# Example:
#
# input data:
# 3
# 12 8
# 11 -3
# 400 5
#
# answer:
# 2 -4 80
# def rounding():
#
#     num = int(input("Enter the number of test-cases: "))
#     lst = []
#
#     for n in range(0, num):
#         nums = input().split()
#         lst.append(round(int(nums[0])/int(nums[1])))
#     print(lst)
#
#
# rounding()
# rounding(11, -3)





result = ''
for _ in range(int(input())):
    lst = list(map(int, input().split()))
    result += str(round(lst[0] / lst[1])) + ' '
    lst.clear()

print(result)






