
# # Python program to find largest number in a list

# # creating a empty list
# list1 = []

# # asking number of elements to put in the list
# num = int(input("Enter thr number of elements in list: "))

# # iterating till num to append elements in a list
# for i in range (1, num+1):
# 	ele = int(input("Enter elements: "))
# 	list1.append(ele)

# # print the list
# print(list1)
# # then print the maximum element
# print("Largest element is: ", max(list1))
#|
#|_________________________
						 #|
						 #|
					     #\/
# #
# # print the list
# print(list1)
# list1.sort()
# # then print the maximum element
# print("Largest element is: ", list1[-1])
#___________________________________________________

# # Python program to find the largest number in a list

# # list of numbers
# list1 = [10, 20, 4, 45, 99]

# # sorting the list
# list1.sort()

# #printing the last element
# print("Largest element is: ", list1[-1])
#___________________________________________________
# # Using the max method
# # taking input from the user
# # list1 = [ 10, 20, 4, 45, 99]
# list1 = []
# num = int(input("Enter the number of elements: "))
# for i in range(1, num+1):
# 	ele = int(input("Enter the elements: "))
# 	list1.append(ele)

# print(list1)

# print("Largest number is: ",max(list1))