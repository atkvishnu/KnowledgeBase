List of all the patterns:
1.  **Sliding Window**
2.  **Two Pointers**
3.  **Fast & Slow Pointers**
4.  **Merge Intervals**
5.  **Cyclic Sort**
6.  **In-place Reversal of a LinkedList**
7.  **Tree Breadth-First Search**
8.  **Tree Depth First Search**
9.  **Two Heaps**
10.  **Subsets**
11.  **Modified Binary Search**
12.  **Bitwise XOR**
13.  **Top ‘K’ Elements**
14.  **K-way Merge**
15.  **0/1 Knapsack**
16.  **Unbounded Knapsack**
17.  **Fibonacci Numbers**
18.  **Palindromic Subsequence**
19.  **Longest Common Substring**
20.  **Topological Sort**
21.  **Trie Traversal**
22.  **Number of Island**
23.  **Trial & Error**
24.  **Union Find**
25.  **Unique Paths**



**1. Sliding Window**

The Sliding Window pattern is used to perform a required operation on a specific window size of a given array or linked list, such as finding the longest subarray containing all 1s. Sliding Windows start from the 1st element and keep shifting right by one element and adjust the length of the window according to the problem that you are solving. In some cases, the window size remains constant and in other cases the sizes grows or shrinks.

![image](https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-8i6d3wi0.jpg&w=3840&q=75)

**Following are some ways you can identify that the given problem might require a sliding window**:

-   The problem input is a linear data structure such as a linked list, array, or string
-   You’re asked to find the longest/shortest substring, subarray, or a desired value

Common problems you use the sliding window pattern with:

-   Maximum sum subarray of size ‘K’ (easy)
-   Longest substring with ‘K’ distinct characters (medium)
-   String anagrams (hard)
-   
**Sample Problems**:

-   [Longest Substring with K Distinct Characters](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628541009794_1Unit)
-   [Fruits into Baskets](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628541018393_2Unit)
-   [Permutation in a String](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628541055153_6Unit)

# 2. Two Pointers or Iterators

**Usage:** In this technique, we use two pointers to iterate the input data. Generally, both pointers move in the opposite direction at a constant interval.

Two Pointers is a pattern where two pointers iterate through the data structure in tandem until one or both of the pointers hit a certain condition.Two Pointers is often useful when searching pairs in a sorted array or linked list; for example, when you have to compare each element of an array to its other elements.


Two pointers are needed because with just pointer, you would have to continually loop back through the array to find the answer. This back and forth with a single iterator is inefficient for time and space complexity — a concept referred to as asymptotic analysis. While the brute force or naive solution with 1 pointer would work, it will produce something along the lines of O(n²). In many cases, two pointers can help you find a solution with better space or runtime complexity.


![](https://miro.medium.com/max/231/1*o2NPCDdYusE_3U6L7yBNXw.png)

![[https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-x4da3w5y.jpg&w=1920&q=75]]

**Sample Problems:**

-   [Squaring a Sorted Array](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743435284_3Unit)
-   [Dutch National Flag Problem](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743488620_8Unit)
-   [Minimum Window Sort](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743511885_11Unit)

# 3. Fast & Slow Pointers

**Usage:** Also known as Hare & Tortoise algorithm. In this technique, we use two pointers that traverse the input data at a different speed.

The Fast and Slow pointer approach, also known as the **Hare & Tortoise algorithm**, is a pointer algorithm that uses two pointers which move through the array (or sequence/linked list) at different speeds. **This approach is quite useful when dealing with cyclic linked lists or arrays.**

By moving at different speeds (say, in a cyclic linked list), the algorithm proves that the two pointers are bound to meet. The fast pointer should catch the slow pointer once both the pointers are in a cyclic loop.



![[https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-suft3wtu.jpg&w=1920&q=75]]

![](https://miro.medium.com/max/607/1*SGQ6-CZmyv59K47G-Wlhbg.png)

Fast & Slow Pointers Pattern

Ways to identify when to use the Two Pointer method:
-   It will feature problems where you deal with sorted arrays (or Linked Lists) and need to find a set of elements that fulfill certain constraints
-   The set of elements in the array is a pair, a triplet, or even a subarray


How do you identify when to use the Fast and Slow pattern?

-   The problem will deal with a loop in a linked list or array
-   When you need to know the position of a certain element or the overall length of the linked list.

When should I use it over the Two Pointer method mentioned above?
-   There are some cases where you shouldn’t use the Two Pointer approach such as in a singly linked list where you can’t move in a backwards direction. An example of when to use the Fast and Slow pattern is when you’re trying to determine if a linked list is a palindrome.

Problems featuring the fast and slow pointers pattern:
-   Linked List Cycle (easy)
-   Palindrome Linked List (medium)
-   Cycle in a Circular Array (hard



Here are some problems that feature the Two Pointer pattern:
-   Squaring a sorted array (easy)
-   Triplets that sum to zero (medium)
-   Comparing strings that contain backspaces (medium)



**Sample Problems:**

-   [Middle of the LinkedList](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743569684_16Unit)
-   [Happy Number](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743560700_15Unit)
-   [Cycle in a Circular Array](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743595805_19Unit)

# 4. Merge Intervals

**Usage:** This technique is used to deal with overlapping intervals. Given two intervals (‘a’ and ‘b’), there will be six different ways the two intervals can relate to each other:


The Merge Intervals pattern is an efficient technique to deal with overlapping intervals. In a lot of problems involving intervals, you either need to find overlapping intervals or merge intervals if they overlap. The pattern works like this:

Given two intervals (‘a’ and ‘b’), there will be six different ways the two intervals can relate to each other:

![[https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-8mh13wm9.jpg&w=1920&q=75]]
Understanding and recognizing these six cases will help you help you solve a wide range of problems from inserting intervals to optimizing interval merges.


How do you identify when to use the Merge Intervals pattern?

-   If you’re asked to produce a list with only mutually exclusive intervals
-   If you hear the term “overlapping intervals”.

Merge interval problem patterns:

-   Intervals Intersection (medium)
-   Maximum CPU Load (hard)



![](https://miro.medium.com/max/427/1*A9NbuTCuSiRfof4Lo5Coew.png)

Intervals Overlapping

**Sample Problems:**

-   [Intervals Intersection](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743634893_23Unit)
-   [Conflicting Appointments](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743642980_24Unit)
-   [Minimum Meeting Rooms](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743654901_25Unit)

# 5. Cyclic Sort

This pattern describes an interesting approach to deal with problems involving arrays containing numbers in a given range. The Cyclic Sort pattern iterates over the array one number at a time, and if the current number you are iterating is not at the correct index, you swap it with the number at its correct index. You could try placing the number in its correct index, but this will produce a complexity of O(n^2) which is not optimal, hence the Cyclic Sort pattern.

![[https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-t8i13wdp.jpg&w=1920&q=75]]




How do I identify this pattern?

-   They will be problems involving a sorted array with numbers in a given range
-   If the problem asks you to find the missing/duplicate/smallest number in an sorted/rotated array

Problems featuring cyclic sort pattern:

-   Find the Missing Number (easy)
-   Find the Smallest Missing Positive Number (medium)



**Usage:** Use this technique to solve array problems where the input data lies within a fixed range.



**Sample Problems:**

-   [Find all Missing Numbers](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743711992_31Unit)
-   [Find all Duplicate Numbers](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743734011_33Unit)
-   [Find the First K Missing Positive Numbers](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743754602_36Unit)

# 6. In-place Reversal of a LinkedList

In a lot of problems, you may be asked to reverse the links between a set of nodes of a linked list. Often, the constraint is that you need to do this in-place, i.e., using the existing node objects and without using extra memory. This is where the above mentioned pattern is useful.

This pattern reverses one node at a time starting with one variable (current) pointing to the head of the linked list, and one variable (previous) will point to the previous node that you have processed. In a lock-step manner, you will reverse the current node by pointing it to the previous before moving on to the next node. Also, you will update the variable “previous” to always point to the previous node that you have processed.


**Usage:** This technique describes an efficient way to reverse the links between a set of nodes of a LinkedList. Often, the constraint is that we need to do this in-place, i.e., using the existing node objects and without using extra memory.



![[https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-gekl3wfd.jpg&w=1920&q=75]]

How do I identify when to use this pattern:

-   If you’re asked to reverse a linked list without using extra memory

Problems featuring in-place reversal of linked list pattern:

-   Reverse a Sub-list (medium)
-   Reverse every K-element Sub-list (medium)






![](https://miro.medium.com/max/674/1*8bcCCiYy0-jPw9fqozxS_A.png)



![](https://miro.medium.com/max/659/1*hxAhYHZBSXtzfUJde_mybw.png)

![](https://miro.medium.com/max/60/1*hxAhYHZBSXtzfUJde_mybw.png?q=20)

![](https://miro.medium.com/max/659/1*hxAhYHZBSXtzfUJde_mybw.png)

**Sample Problems:**

-   [Reverse every K-element Sub-list](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743796880_40Unit)
-   [Rotate a LinkedList](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743812259_42Unit)

# 7. Tree Breadth-First Search

This pattern is based on the Breadth First Search (BFS) technique to traverse a tree and uses a queue to keep track of all the nodes of a level before jumping onto the next level. Any problem involving the traversal of a tree in a level-by-level order can be efficiently solved using this approach.

The Tree BFS pattern works by pushing the root node to the queue and then continually iterating until the queue is empty. For each iteration, we remove the node at the head of the queue and “visit” that node. After removing each node from the queue, we also insert all of its children into the queue.

How to identify the Tree BFS pattern:

-   If you’re asked to traverse a tree in a level-by-level fashion (or level order traversal)

Problems featuring Tree BFS pattern:

-   Binary Tree Level Order Traversal (easy)

-   Zigzag Traversal (medium)

**Usage:** As the name suggests, this technique is used to solve problems involving traversing trees in a breadth-first search manner.

![](https://miro.medium.com/max/60/1*prMD0S9_Psv9mkvqNMEtnw.png?q=20)

![](https://miro.medium.com/max/529/1*prMD0S9_Psv9mkvqNMEtnw.png)

Binary Tree Breadth-First Search

**Sample Problems:**

-   [Binary Tree Level Order Traversal](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743844952_44Unit)
-   [Minimum Depth of a Binary Tree](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743873257_48Unit)
-   [Connect Level Order Siblings](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743890075_50Unit)

# 8. Tree Depth First Search




Tree DFS is based on the Depth First Search (DFS) technique to traverse a tree.


You can use recursion (or a stack for the iterative approach) to keep track of all the previous (parent) nodes while traversing.

The Tree DFS pattern works by starting at the root of the tree, if the node is not a leaf you need to do three things:

1.  Decide whether to process the current node now (pre-order), or between processing two children (in-order) or after processing both children (post-order).
2.  Make two recursive calls for both the children of the current node to process them.

How to identify the Tree DFS pattern:

-   If you’re asked to traverse a tree with in-order, preorder, or postorder DFS
-   If the problem requires searching for something where the node is closer to a leaf

Problems featuring Tree DFS pattern:

-   Sum of Path Numbers (medium)
-   All Paths for a Sum (medium)




**Usage:** As the name suggests, this technique is used to solve problems involving traversing trees in depth-first search manner.

**Sample Problems:**

-   [Path With Given Sequence](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743947562_57Unit)
-   [Count Paths for a Sum](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743955693_58Unit)

# 9. Two Heaps

In many problems, we are given a set of elements such that we can divide them into two parts. To solve the problem, we are interested in knowing the smallest element in one part and the biggest element in the other part. This pattern is an efficient approach to solve such problems.

This pattern uses two heaps; A Min Heap to find the smallest element and a Max Heap to find the biggest element. The pattern works by storing the first half of numbers in a Max Heap, this is because you want to find the largest number in the first half. You then store the second half of numbers in a Min Heap, as you want to find the smallest number in the second half. At any time, the median of the current list of numbers can be calculated from the top element of the two heaps.


Ways to identify the Two Heaps pattern:

-   Useful in situations like Priority Queue, Scheduling
-   If the problem states that you need to find the smallest/largest/median elements of a set
-   Sometimes, useful in problems featuring a binary tree data structure

Problems featuring


-   Find the Median of a Number Stream (medium)


**Usage:** In many problems, where we are given a set of elements such that we can divide them into two parts. We are interested in knowing the smallest element in one part and the biggest element in the other part. As the name suggests, this technique uses a **Min-Heap** to find the smallest element and a **Max-Heap** to find the biggest element.

**Sample Problems:**

-   [Find the Median of a Number Stream](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628743994867_62Unit)
-   [Next Interval](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744015026_65Unit)

# 10. Subsets

A huge number of coding interview problems involve dealing with Permutations and Combinations of a given set of elements. The pattern Subsets describes an efficient Breadth First Search (BFS) approach to handle all these problems.

The pattern looks like this:

Given a set of [1, 5, 3]

1.  Start with an empty set: [[]]
2.  Add the first number (1) to all the existing subsets to create new subsets: [[], [1]];
3.  Add the second number (5) to all the existing subsets: [[], [1], [5], [1,5]];
4.  Add the third number (3) to all the existing subsets: [[], [1], [5], [1,5], [3], [1,3], [5,3], [1,5,3]].

Here is a visual representation of the Subsets pattern:

![[https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-hemg3w8d.jpg&w=1920&q=75]]

**Usage:** Use this technique when the problem asks to deal with permutations or combinations of a set of elements.

**Sample Problems:**

-   [String Permutations by changing case](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744066603_70Unit)
-   [Unique Generalized Abbreviations](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744084164_72Unit)

# 11. Modified Binary Search

Whenever you are given a sorted array, linked list, or matrix, and are asked to find a certain element, the best algorithm you can use is the Binary Search. This pattern describes an efficient way to handle all problems involving Binary Search.

The patterns looks like this for an ascending order set:

1.  First, find the middle of start and end. An easy way to find the middle would be: middle = (start + end) / 2. But this has a good chance of producing an integer overflow so it’s recommended that you represent the middle as: middle = start + (end — start) / 2
2.  If the key is equal to the number at index middle then return middle
3.  If ‘key’ isn’t equal to the index middle:
4.  Check if key < arr[middle]. If it is reduce your search to end = middle — 1
5.  Check if key > arr[middle]. If it is reduce your search to end = middle + 1

Here is a visual representation of the Modified Binary Search pattern:

![[https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-kxno3wrs.jpg&w=1920&q=75]]

**Usage:** Use this technique to search a sorted set of elements efficiently.

**Sample Problems:**
- Order-agnostic Binary Search (easy)
- Search in a Sorted Infinite Array (medium)
-   [Ceiling of a Number](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744141988_78Unit)
-   [Bitonic Array Maximum](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744182053_83Unit)

# 12. Bitwise XOR

**Usage:** This technique uses the XOR operator to manipulate bits to solve problems.

**Sample Problems:**

-   [Two Single Numbers](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744240302_89Unit)
-   [Flip and Invert an Image](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744253956_91Unit)

# 13. Top ‘K’ Elements

Any problem that asks us to find the top/smallest/frequent ‘K’ elements among a given set falls under this pattern.

The best data structure to keep track of ‘K’ elements is Heap. This pattern will make use of the Heap to solve multiple problems dealing with ‘K’ elements at a time from a set of given elements. The pattern looks like this:

1.  Insert ‘K’ elements into the min-heap or max-heap based on the problem.
2.  Iterate through the remaining numbers and if you find one that is larger than what you have in the heap, then remove that number and insert the larger one.

![[https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-uuow3wb1.jpg&w=1920&q=75]]



There is no need for a sorting algorithm because the heap will keep track of the elements for you.

How to identify the Top ‘K’ Elements pattern:

-   If you’re asked to find the top/smallest/frequent ‘K’ elements of a given set
-   If you’re asked to sort an array to find an exact element

Problems featuring Top ‘K’ Elements pattern:

-   Top ‘K’ Numbers (easy)
-   Top ‘K’ Frequent Numbers (medium)


**Usage:** This technique is used to find top/smallest/frequently occurring ‘K’ elements in a set.

**Sample Problems:**

-   [‘K’ Closest Points to the Origin](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744290707_95Unit)
-   [Maximum Distinct Elements](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744333663_101Unit)

# 14. K-way Merge
K-way Merge helps you solve problems that involve a set of sorted arrays.

Whenever you’re given ‘K’ sorted arrays, you can use a Heap to efficiently perform a sorted traversal of all the elements of all arrays. You can push the smallest element of each array in a Min Heap to get the overall minimum. After getting the overall minimum, push the next element from the same array to the heap. Then, repeat this process to make a sorted traversal of all elements.
**Usage:** This technique helps us solve problems that involve a list of sorted arrays.

![[https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fimages%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-4hwy3w8x.jpg&w=1920&q=75]]




The pattern looks like this:

1.  Insert the first element of each array in a Min Heap.
2.  After this, take out the smallest (top) element from the heap and add it to the merged list.
3.  After removing the smallest element from the heap, insert the next element of the same list into the heap.
4.  Repeat steps 2 and 3 to populate the merged list in sorted order.

How to identify the K-way Merge pattern:

-   The problem will feature sorted arrays, lists, or a matrix
-   If the problem asks you to merge sorted lists, find the smallest element in a sorted list.

Problems featuring the K-way Merge pattern:

-   Merge K Sorted Lists (medium)
-   K Pairs with Largest Sums (Hard)










**Sample Problems:**

-   [Kth Smallest Number in M Sorted Lists](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744417564_109Unit)
-   [Kth Smallest Number in a Sorted Matrix](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744424045_110Unit)

# 15. 0/1 Knapsack

**Usage:** This technique is used to solve optimization problems. Use this technique to select elements that give maximum profit from a given set with a limitation on capacity and that each element can only be picked once.

**Sample Problems:**

-   [Equal Subset Sum Partition](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744468342_115Unit)
-   [Minimum Subset Sum Difference](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744485888_117Unit)

# **16. Unbounded Knapsack**

**Usage:** Use this technique to select elements that give maximum profit from a given set with a limitation on capacity and that each element can be picked multiple times.

**Sample Problems:**

-   [Rod Cutting](https://designgurus.org/path-player?courseid=grokking-dynamic-programming&unit=grokking-dynamic-programming_1629940224549_1Unit)
-   [Coin Change](https://designgurus.org/path-player?courseid=grokking-dynamic-programming&unit=grokking-dynamic-programming_1629940234373_2Unit)

# 17. Fibonacci Numbers

**Usage:** Use this technique to solve problems that follow the Fibonacci numbers sequence, i.e., every subsequent number is calculated from the last few numbers.

**Sample Problems:**

-   [Staircase](https://designgurus.org/path-player?courseid=grokking-dynamic-programming&unit=grokking-dynamic-programming_1629940375183_1Unit)
-   [House Thief](https://designgurus.org/path-player?courseid=grokking-dynamic-programming&unit=grokking-dynamic-programming_1629940440291_0Unit)

# 18. Palindromic Subsequence

**Usage:** This technique is used to solve optimization problems related to palindromic sequences or strings.

**Sample Problems:**

-   [Longest Palindromic Subsequence](https://designgurus.org/path-player?courseid=grokking-dynamic-programming&unit=grokking-dynamic-programming_1629940453874_1Unit)
-   [Minimum Deletions in a String to make it a Palindrome](https://designgurus.org/path-player?courseid=grokking-dynamic-programming&unit=grokking-dynamic-programming_1629940499419_0Unit)

# 19. Longest Common Substring

**Usage:** Use this technique to find the optimal part of a string/sequence or set of strings/sequences.

**Sample Problems:**

-   [Maximum Sum Increasing Subsequence](https://designgurus.org/path-player?courseid=grokking-dynamic-programming&unit=grokking-dynamic-programming_1629940565491_6Unit)
-   [Edit Distance](https://designgurus.org/path-player?courseid=grokking-dynamic-programming&unit=grokking-dynamic-programming_1629940637763_13Unit)

# 20. Topological Sort

Usage: Use this technique to find a linear ordering of elements that have dependencies on each other.

**Sample Problems:**

-   [Tasks Scheduling](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744536717_122Unit)
-   [Alien Dictionary](https://designgurus.org/path-player?courseid=grokking-the-coding-interview&unit=grokking-the-coding-interview_1628744560693_125Unit)

# 21. Trie Traversal

**Usage:** Use this technique that involves creating or traversing of Trie data structure.

**Sample Problems:**

-   Longest Word in Dictionary
-   Palindrome Pairs

# 22. Number of Island

**Usage:** Use this technique to traverse a two-dimensional array and find a set of connected elements.

**Sample Problems:**

-   Number of Distinct Islands
-   Maximum Area of Island

# 23. Trial & Error

**Usage:** Use this technique to traverse an array to find a required optimal element. The traversal process runs in a trial & error manner.

**Sample Problems:**

-   Find Kth Smallest Pair Distance
-   Minimize Max Distance to Gas Station

# 24. Union Find

**Usage:** Use this technique to solve problems that require maintaining a given set of elements partitioned into multiple non-overlapping subsets.

**Sample Problems:**

-   Number of Provinces
-   Bipartite Graph

# 25. Unique Paths

**Usage:** Use this technique to find different/optimal ways to traverse a multi-dimensional array.

**Sample Problems:**

-   Find Unique Paths
-   Dungeon Game





# 26. Topological sort

Topological Sort is used to find a linear ordering of elements that have dependencies on each other. For example, if event ‘B’ is dependent on event ‘A’, ‘A’ comes before ‘B’ in topological ordering.


This pattern defines an easy way to understand the technique for performing topological sorting of a set of elements.


The pattern works like this:

1.  Initialization  
    a) Store the graph in adjacency lists by using a HashMap  
    b) To find all sources, use a HashMap to keep the count of in-degreesBuild the graph and find in-degrees of all vertices
2.  Build the graph from the input and populate the in-degrees HashMap.
3.  Find all sources  
    a) All vertices with ‘0’ in-degrees will be sources and are stored in a Queue.
4.  Sort  
    a) For each source, do the following things:  
    —i) Add it to the sorted list.  
    — ii)Get all of its children from the graph.  
    — iii)Decrement the in-degree of each child by 1.  
    — iv)If a child’s in-degree becomes ‘0’, add it to the sources Queue.  
    b) Repeat (a), until the source Queue is empty.

![image](https://hackernoon.com/_next/image?url=https%3A%2F%2Fcdn.hackernoon.com%2Fphotos%2FG9YRlqC9joZNTWsi1ul7tRkO6tv1-ve1473wvg&w=3840&q=75)


How to identify the Topological Sort pattern:


-   The problem will deal with graphs that have no directed cycles
-   If you’re asked to update all objects in a sorted order
-   If you have a class of objects that follow a particular order

Problems featuring the Topological Sort pattern:

-   Task scheduling (medium)
-   Minimum height of a tree (hard)




















# **Conclusion**

Like it or not, LeetCode-type questions are a part of almost every programming interview, so every software developer should practice them before an interview. Their only option is to prepare smartly and learn problem-solving by focusing on the underlying problem patterns. Learn more about these patterns and sample problems in [**Grokking the Coding Interview**](https://www.designgurus.org/course/grokking-the-coding-interview) and [**Grokking Dynamic Programming for Coding Interviews**](https://designgurus.org/course/grokking-dynamic-programming) .

Check [**Design Gurus**](http://www.designgurus.org/) for some interesting courses on Coding and System Design interviews.




I created a LeetCode list for each of the patterns. I found it pretty useful, feel free to make a copy of the list and use it.

-   [2 Heaps](https://leetcode.com/list/xlemvyvd)
-   [Arrays](https://leetcode.com/list/xleo1moc)
-   [Backtracking](https://leetcode.com/list/xlere2g3)
-   [Dynamic Programming](https://leetcode.com/list/xlern30i)
-   [Fast & Slow pointers](https://leetcode.com/list/xlerlepr)
-   [Graph Traversal](https://leetcode.com/list/xler60c5)
-   [In-place traversal of LL](https://leetcode.com/list/xler4hke)
-   [K-way merge](https://leetcode.com/list/xlepm8xi)
-   [Merge Intervals](https://leetcode.com/list/xlepvmyj)
-   [Modified Binary Search](https://leetcode.com/list/xleplgq3)
-   [Sliding window](https://leetcode.com/list/xlep8di5)
-   [Top K elements](https://leetcode.com/list/xlepz4mv)
-   [Topological Sorting](https://leetcode.com/list/xlepbnhh)
-   [Tree BFS](https://leetcode.com/list/xlepfebm)
-   [Tree DFS](https://leetcode.com/list/xlemouqi)
-   [Two Pointers](https://leetcode.com/list/xlem03mm)

Good Luck & Happy Coding!!


<https://www.freecodecamp.org/news/coding-interview-preparation/>








































