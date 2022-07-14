count = int(input("Enter the number of elements: "))

for n in range(0, count):
    mins = 0
    nums = input().split()

    if int(nums[0]) > int(nums[1]):
        mins = int(nums[1])
    else:
        mins = int(nums[0])

    print(mins)




# n = int(input())
# for i in range(n):
#     lis = map(int, input().split())
#     print(min(lis), end=" " )



# for _ in range (int(input())) :
#     print(min(int(y) for y in input().split()) , end = ' ')

# import sys
#
# l = []
#
# for line in sys.stdin:
#     if line == '30\n':
#         pass
#     else:
#         nums = line.split()
#         if int(nums[0]) > int(nums[1]):
#             l.append(nums[1])
#         else:
#             l.append(nums[0])
#
# for item in l:
#     print
#     item + ' '


#
# a = int(input())
# for i in range(a):
#     b = input().split(' ')
#     b[0] = int(b[0])
#     b[1] = int(b[1])
#     print(min(b), end='\n')