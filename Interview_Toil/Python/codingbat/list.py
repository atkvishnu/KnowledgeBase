# #1
# #creating an empty list
lst = []

#number of elements as input 
n = int(input("Enter the number of elements : "))

#iterating till the range
for i in range(0, n):
	ele = int(input())

	lst.append(ele)		#adding the elements

print(lst)

#_____________________________________________________

# #2
# #With handle exception
# #try block to handle the exception
# try:
# 	my_list = []

# 	while True:
# 		my_list.append(int(input()))

# #if input is non-integer, just print the list
# except:
# 	print(my_list)

#_____________________________________________________

# #3
# #using map()

# #number of elements
# n=int(input("Enter the number of elements: "))

# #Below line read input from the user using map() function
# a = list(map(int,input("\nEnter the numbers : ").strip().split()))[:n]

# print("\nList is = ", a)

#_____________________________________________________

#4
#List of lists as input

# lst = []
# n = int(input("Enter the number of elements: "))

# for i in range(0, n):
# 	ele = [input(), int(input())]
# 	lst.append(ele)

# print(lst)

# Output
# C:\Users\lipsp\Python>python list.py
# Enter the number of elements: 3
# Geeks
# 8
# For
# 7
# Geeks
# 6
# [['Geeks', 8], ['For', 7], ['Geeks', 6]]