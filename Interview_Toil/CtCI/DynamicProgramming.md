**Dynamic Programming**

1. Longest Common Subsequence
2. Longest Increasing Subsequence
3. Edit Distance
4. Minimum Partition
5. Ways to Cover a Distance
6. Longest Path In Matrix
7. Subset Sum Problem
8. Optimal Strategy for a Game
9. 0-1 Knapsack Problem
10. Boolean Parenthesization Problem


----
1. Longest Common Subsequence
_LCS Problem Statement:_ Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

In order to find out the complexity of brute force approach, we need to first know the number of possible different subsequences of a string with length n, i.e., find the number of subsequences with lengths ranging from 1,2,..n-1. Recall from theory of permutation and combination that number of combinations with 1 element are nC1. Number of combinations with 2 elements are nC2 and so forth and so on. We know that nC0 + nC1 + nC2 + … nCn = 2n. So a string of length n has 2n-1 different possible subsequences since we do not consider the subsequence with length 0. This implies that the time complexity of the brute force approach will be O(n * 2n). Note that it takes O(n) time to check if a subsequence is common to both the strings. This time complexity can be improved using dynamic programming.

It is a classic computer science problem, the basis of [diff](http://en.wikipedia.org/wiki/Diff) (a file comparison program that outputs the differences between two files), and has applications in bioinformatics.

**Examples:**   
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.   
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

The naive solution for this problem is to generate all subsequences of both given sequences and find the longest matching subsequence. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem. 

**1) Optimal Substructure:**   
Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively. And let L(X[0..m-1], Y[0..n-1]) be the length of LCS of the two sequences X and Y. Following is the recursive definition of L(X[0..m-1], Y[0..n-1]).

If last characters of both sequences match (or X[m-1] == Y[n-1]) then   
L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])

If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then   
L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2]) )

Examples:   
1) Consider the input strings “AGGTAB” and “GXTXAYB”. Last characters match for the strings. So length of LCS can be written as:   
L(“AGGTAB”, “GXTXAYB”) = 1 + L(“AGGTA”, “GXTXAY”) 

![longest-common-subsequence](https://www.geeksforgeeks.org/wp-content/uploads/Longest-Common-Subsequence.png)

2) Consider the input strings “ABCDGH” and “AEDFHR. Last characters do not match for the strings. So length of LCS can be written as:   
L(“ABCDGH”, “AEDFHR”) = MAX ( L(“ABCDG”, “AEDFH**R**”), L(“ABCDG**H**”, “AEDFH”) )  
So the LCS problem has optimal substructure property as the main problem can be solved using solutions to subproblems.

**2) Overlapping Subproblems:**   
Following is simple recursive implementation of the LCS problem. The implementation simply follows the recursive structure mentioned above.

```cpp
/* A Naive recursive implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;
 
int max(int a, int b);
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
 
/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Driver code */
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
     
    int m = strlen(X);
    int n = strlen(Y);
     
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
     
    return 0;
}
```

**Output:** 

Length of LCS is 4

Time complexity of the above naive recursive approach is O(2^n) in worst case and worst case happens when all characters of X and Y mismatch i.e., length of LCS is 0. 

Considering the above implementation, following is a partial recursion tree for input strings “AXYT” and “AYZX”

                         lcs("AXYT", "AYZX")
                       /                 
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                              /               
lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")

In the above partial recursion tree, lcs(“AXY”, “AYZ”) is being solved twice. If we draw the complete recursion tree, then we can see that there are many subproblems which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation. Following is a tabulated implementation for the LCS problem.

Time Complexity: O(mn)

----
2. Longest Increasing Subsequence
We have already discussed [Overlapping Subproblems](https://www.geeksforgeeks.org/dynamic-programming-set-1/) and [Optimal Substructure](https://www.geeksforgeeks.org/dynamic-programming-set-2-optimal-substructure-property/) properties.   
Now, let us discuss the Longest Increasing Subsequence (LIS) problem as an example problem that can be solved using Dynamic Programming. 

The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.

![longest-increasing-subsequence](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Longest-Increasing-Subsequence.png)

**Examples:**
**Input:** arr[] = {3, 10, 2, 1, 20}
**Output:** Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

**Input:** arr[] = {3, 2}
**Output:** Length of LIS = 1
The longest increasing subsequences are {3} and {2}

**Input:** arr[] = {50, 3, 10, 7, 40, 80}
**Output:** Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}


**Method 1:** Recursion.  
_**Optimal Substructure:**_ Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.

Then, L(i) can be recursively written as: 

L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
L(i) = 1, if no such j exists.

To find the LIS for a given array, we need to return max(L(i)) where 0 < i < n.  
Formally, the length of the longest increasing subsequence ending at index i, will be 1 greater than the maximum of lengths of all longest increasing subsequences ending at indices before i, where arr[j] < arr[i] (j < i).  
Thus, we see the LIS problem satisfies the optimal substructure property as the main problem can be solved using solutions to subproblems.

The recursive tree given below will make the approach clearer:  

Input  : arr[] = {3, 10, 2, 11}
**f(i): Denotes LIS of subarray ending at index 'i'**

(LIS(1)=1)

      f(4)  {f(4) = 1 + max(f(1), f(2), f(3))}
  /    |    \
f(1)  f(2)  f(3) {f(3) = 1, f(2) and f(1) are > f(3)}
       |      |  \
      f(1)  f(2)  f(1) {f(2) = 1 + max(f(1)}
              |
            f(1) {f(1) = 1}

Below is the implementation of the recursive approach:

```cpp
/* A Naive C++ recursive implementation
of LIS problem */
#include <iostream>
using namespace std;
 
/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
    We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
    an element before arr[n-1] max_ref is
    used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"Length of lis is "<< lis(arr, n);
    return 0;
}

```

**Output:** 

Length of lis is 5

**Complexity Analysis:** 

-   **Time Complexity:** The time complexity of this recursive approach is exponential as there is a case of overlapping subproblems as explained in the recursive tree diagram above.
-   **Auxiliary Space:** O(1). No external space used for storing values apart from the internal stack space.

**Method 2:** Dynamic Programming.  
We can see that there are many subproblems in the above recursive solution which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation.

The simulation of approach will make things clear:  

Input  : arr[] = {3, 10, 2, 11}
LIS[] = {1, 1, 1, 1} (initially)

**Iteration-wise simulation :** 

1.  arr[2] > arr[1] {LIS[2] = max(LIS [2], LIS[1]+1)=2}
2.  arr[3] < arr[1] {No change}
3.  arr[3] < arr[2] {No change}
4.  arr[4] > arr[1] {LIS[4] = max(LIS [4], LIS[1]+1)=2}
5.  arr[4] > arr[2] {LIS[4] = max(LIS [4], LIS[2]+1)=3}
6.  arr[4] > arr[3] {LIS[4] = max(LIS [4], LIS[3]+1)=3}

We can avoid recomputation of subproblems by using tabulation as shown in the below code: 

Below is the implementation of the above approach:

```cpp
/* Dynamic Programming C++ implementation
   of LIS problem */
#include <bits/stdc++.h>
using namespace std;
 
/* lis() returns the length of the longest
  increasing subsequence in arr[] of size n */
int lis(int arr[], int n)
{
    int lis[n];
 
    lis[0] = 1;
 
    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
 
    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));
 
    return 0;
}
```

**Output**

Length of lis is 5

**Complexity Analysis:** 

-   **Time Complexity:** O(n2).   
    As nested loop is used.
-   **Auxiliary Space:** O(n).   
    Use of any array to store LIS values at each index.

**Note:** The time complexity of the above Dynamic Programming (DP) solution is O(n^2) and there is a O(N log N) solution for the LIS problem. We have not discussed the O(N log N) solution here as the purpose of this post is to explain Dynamic Programming with a simple example. See below post for O(N log N) solution.   
[Longest Increasing Subsequence Size (N log N)](https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/)

**Method 3:** Dynamic Programming

If we closely observe the problem then we can convert this problem to longest Common Subsequence Problem. Firstly we will create another array of unique elements of original array and sort it. Now the longest increasing subsequence of our array must be present as a subsequence in our sorted array. That’s why our problem is now reduced to finding the common subsequence between the two arrays.

Eg. arr =[50,3,10,7,40,80]
    // Sorted array
    arr1 = [3,7,10,40,50,80]
    // LIS is longest common subsequence between the two arrays
    ans = 4
    The longest increasing subsequence is {3, 7, 40, 80}


```python

# Dynamic Programming Approach of Finding LIS by reducing the problem to longest common Subsequence
 
def lis(a):
    n=len(a)
    # Creating the sorted list
    b=sorted(list(set(a)))
    m=len(b)
     
     
    # Creating dp table for storing the answers of sub problems
    dp=[[-1 for i in range(m+1)] for j in range(n+1)]
     
    # Finding Longest common Subsequence of the two arrays
    for i in range(n+1):
             
        for j in range(m+1):
            if i==0 or j==0:
                dp[i][j]=0
            elif a[i-1]==b[j-1]:
                dp[i][j]=1+dp[i-1][j-1]
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    return dp[-1][-1]
     
# Driver program to test above function
arr = [10, 22, 9, 33, 21, 50, 41, 60]
print("Length of lis is ", lis(arr))
```

**Output**

Length of lis is  5

**Complexity Analysis** : O(n*n)

As nested loop is used

**Space Complexity** : O(n*n)

As a matrix is used for storing the values.


----
3. Edit Distance

Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

1.  Insert
2.  Remove
3.  Replace
All of the above operations are of equal cost.

**Examples:** 

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a

**What are the subproblems in this case?**   
The idea is to process all characters one by one starting from either from left or right sides of both strings.   
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.

**m:** Length of str1 (first string)
**n:** Length of str2 (second string)

1.  If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
2.  Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values. 
    1.  Insert: Recur for m and n-1
    2.  Remove: Recur for m-1 and n
    3.  Replace: Recur for m-1 and n-1

Below is implementation of above Naive recursive solution.

```cpp
// A Naive recursive C++ program to find minimum number
// operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;
  
// Utility function to find minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }
  
int editDist(string str1, string str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;
  
    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;
  
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
  
    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1
           + min(editDist(str1, str2, m, n - 1), // Insert
                 editDist(str1, str2, m - 1, n), // Remove
                 editDist(str1, str2, m - 1,
                          n - 1) // Replace
             );
}
  
// Driver code
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";
  
    cout << editDist(str1, str2, str1.length(),
                     str2.length());
  
    return 0;
}
```

**Output**

3

The time complexity of above solution is exponential. In worst case, we may end up doing O(3m) operations. The worst case happens when none of characters of two strings match. Below is a recursive call diagram for worst case. 

![EditDistance](https://media.geeksforgeeks.org/wp-content/cdn-uploads/EditDistance-1024x618.png)

We can see that many subproblems are solved, again and again, for example, eD(2, 2) is called three times. Since same subproblems are called again, this problem has Overlapping Subproblems property. So Edit Distance problem has both properties (see [this](https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/) and [this](https://www.geeksforgeeks.org/optimal-substructure-property-in-dynamic-programming-dp-2/)) of a dynamic programming problem. Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by constructing a temporary array that stores results of subproblems.

```cpp
// A Dynamic Programming based C++ program to find minimum
// number operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;
  
// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }
  
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];
  
    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
  
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
  
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
  
            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j]
                    = 1
                      + min(dp[i][j - 1], // Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1]); // Replace
        }
    }
  
    return dp[m][n];
}
  
// Driver code
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";
  
    cout << editDistDP(str1, str2, str1.length(),
                       str2.length());
  
    return 0;
}
```

**Output**

3

**Time Complexity:** O(m x n)   
**Auxiliary Space:** O(m x n)

**Space Complex Solution**: In the above-given method we require O(m x n) space. This will not be suitable if the length of strings is greater than 2000 as it can only create 2D array of 2000 x 2000. To fill a row in DP array we require only one row the upper row. For example, if we are filling the i = 10 rows in DP array we require only values of 9th row. So we simply create a DP array of 2 x str1 length. This approach reduces the space complexity. Here is the C++ implementation of the above-mentioned problem

```cpp
// A Space efficient Dynamic Programming
// based C++ program to find minimum
// number operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;
  
void EditDistDP(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
  
    // Create a DP array to memoize result
    // of previous computations
    int DP[2][len1 + 1];
  
    // To fill the DP array with 0
    memset(DP, 0, sizeof DP);
  
    // Base condition when second string
    // is empty then we remove all characters
    for (int i = 0; i <= len1; i++)
        DP[0][i] = i;
  
    // Start filling the DP
    // This loop run for every
    // character in second string
    for (int i = 1; i <= len2; i++) {
        // This loop compares the char from
        // second string with first string
        // characters
        for (int j = 0; j <= len1; j++) {
            // if first string is empty then
            // we have to perform add character
            // operation to get second string
            if (j == 0)
                DP[i % 2][j] = i;
  
            // if character from both string
            // is same then we do not perform any
            // operation . here i % 2 is for bound
            // the row number.
            else if (str1[j - 1] == str2[i - 1]) {
                DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
            }
  
            // if character from both string is
            // not same then we take the minimum
            // from three specified operation
            else {
                DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j],
                                       min(DP[i % 2][j - 1],
                                           DP[(i - 1) % 2][j - 1]));
            }
        }
    }
  
    // after complete fill the DP array
    // if the len2 is even then we end
    // up in the 0th row else we end up
    // in the 1th row so we take len2 % 2
    // to get row
    cout << DP[len2 % 2][len1] << endl;
}
  
// Driver program
int main()
{
    string str1 = "food";
    string str2 = "money";
    EditDistDP(str1, str2);
    return 0;
}
```

**Output**

4

**Time Complexity:** O(m x n)   
**Auxiliary Space:** O( m )

This is a memoized version of recursion i.e. Top-Down DP:


```cpp
#include <bits/stdc++.h>
using namespace std;
int minDis(string s1, string s2, int n, int m, vector<vector<int>> &dp){
          
  // If any string is empty,
  // return the remaining characters of other string
            
  if(n==0)    return m;
          
  if(m==0)    return n;
          
            
  // To check if the recursive tree
  // for given n & m has already been executed
          
  if(dp[n][m]!=-1)    return dp[n][m];
            
            
  // If characters are equal, execute 
  // recursive function for n-1, m-1
          
  if(s1[n-1]==s2[m-1]){           
    if(dp[n-1][m-1]==-1){               
      return dp[n][m] = minDis(s1, s2, n-1, m-1, dp);           
    }        
    else
      return dp[n][m] = dp[n-1][m-1];   
  }
    
          
  // If characters are nt equal, we need to
            
  // find the minimum cost out of all 3 operations.
          
  else{           
    int m1, m2, m3;        // temp variables   
      
    if(dp[n-1][m]!=-1){    
      m1 = dp[n-1][m];      
    }           
    else{   
      m1 = minDis(s1, s2, n-1, m, dp);      
    }            
              
    if(dp[n][m-1]!=-1){                
      m2 = dp[n][m-1];            
    }            
    else{    
      m2 = minDis(s1, s2, n, m-1, dp);      
    }                                   
     
    if(dp[n-1][m-1]!=-1){    
      m3 = dp[n-1][m-1];      
    }   
    else{   
      m3 = minDis(s1, s2, n-1, m-1, dp);       
    }     
    return dp[n][m] = 1+min(m1, min(m2, m3));        
  }
    
}
  
  
// Driver program 
int main() {
      
  string str1 = "voldemort"; 
  string str2 = "dumbledore"; 
        
  int n= str1.length(), m = str2.length();    
  vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
                  
  cout<<minDis(str1, str2, n, m, dp); 
  return 0; 
      
  
}
```

**Output**

7

**Applications**: There are many practical applications of edit distance algorithm, refer [Lucene](http://en.wikipedia.org/wiki/Lucene) API for sample. Another example, display all the words in a dictionary that are near proximity to a given wordincorrectly spelled word.









----
4. Minimum Partition

Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.   
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
**Example:**
Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11


This problem is mainly an extension to the [Dynamic Programming| Set 18 (Partition Problem).](https://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/)   
**Recursive Solution**   
The recursive approach is to generate all possible sums from all the values of the array and to check which solution is the most optimal one.   
To generate sums we either include the i’th item in set 1 or don’t include, i.e., include in set 2.

```cpp
// A Recursive C++ program to solve minimum sum partition
// problem.
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the minimum sum
int findMinRec(int arr[], int i, int sumCalculated,
               int sumTotal)
{
    // If we have reached last element.  Sum of one
    // subset is sumCalculated, sum of other subset is
    // sumTotal-sumCalculated.  Return absolute difference
    // of two sums.
    if (i == 0)
        return abs((sumTotal - sumCalculated)
                   - sumCalculated);
 
    // For every item arr[i], we have two choices
    // (1) We do not include it first set
    // (2) We include it in first set
    // We return minimum of two choices
    return min(
        findMinRec(arr, i - 1, sumCalculated + arr[i - 1],
                   sumTotal),
        findMinRec(arr, i - 1, sumCalculated, sumTotal));
}
 
// Returns minimum possible difference between sums
// of two subsets
int findMin(int arr[], int n)
{
    // Compute total sum of elements
    int sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += arr[i];
 
    // Compute result using recursive function
    return findMinRec(arr, n, 0, sumTotal);
}
 
// Driver program to test above function
int main()
{
    int arr[] = { 3, 1, 4, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between two sets is "
         << findMin(arr, n);
    return 0;
}
```

**Output:** 

  

  

The minimum difference between two sets is 1

**Time Complexity:** 

All the sums can be generated by either 
(1) including that element in set 1.
(2) without including that element in set 1.
So possible combinations are :-  
arr[0]      (1 or 2)  -> 2 values
arr[1]    (1 or 2)  -> 2 values
.
.
.
arr[n]     (2 or 2)  -> 2 values
So time complexity will be 2*2*..... *2 (For n times),
that is O(2^n).

**Dynamic Programming**   
The problem can be solved using dynamic programming when the sum of the elements is not too big. We can create a 2D array dp[n+1][sum+1] where n is the number of elements in a given set and sum is the sum of all elements. We can construct the solution in a bottom-up manner.

The task is to divide the set into two parts. 
We will consider the following factors for dividing it. 
Let 
  dp[n+1][sum+1] = {1 if some subset from 1st to i'th has a sum 
                      equal to j
                   0 otherwise}
    
    i ranges from {1..n}
    j ranges from {0..(sum of all elements)}  

So      
    dp[n+1][sum+1]  will be 1 if 
    1) The sum j is achieved including i'th item
    2) The sum j is achieved excluding i'th item.

Let sum of all the elements be S.  

To find Minimum sum difference, w have to find j such 
that Min{sum - j*2  : dp[n][j]  == 1 } 
    where j varies from 0 to sum/2

The idea is, sum of S1 is j and it should be closest
to sum/2, i.e., 2*j should be closest to sum.

Below is the implementation of the above code

```cpp
// A Recursive C program to solve minimum sum partition
// problem.
#include <bits/stdc++.h>
using namespace std;
 
// Returns the minimum value of the difference of the two
// sets.
int findMin(int arr[], int n)
{
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    // Create an array to store results of subproblems
    bool dp[n + 1][sum + 1];
 
    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];
 
            // If i'th element is included
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
 
    // Initialize difference of two sums.
    int diff = INT_MAX;
 
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}
 
// Driver program to test above function
int main()
{
    int arr[] = { 3, 1, 4, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is "
         << findMin(arr, n);
    return 0;
}
```

**Output:** 

The minimum difference between 2 sets is 1

**Time Complexity** = O(n*sum) where n is the number of elements and sum is the sum of all elements.

**Dynamic Programming with less Space Complexity:**

Instead of using 2D array we can solve this problem using 1D array dp[sum/2+1] .


lets say sum of elements of set 1 is x than sum of elements of set 2 will be sm-x (sm is sum of all elements of arr).

So we have to minimise abs(sm-2*x). 

So for minimizing difference between two sets, we need to know a number that is just less than sum/2 (sum is sum of all elements in array) and can be generated by addition of elements from array.

```cpp
#include <iostream>
using namespace std;
 
int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int y = sum / 2 + 1;
    // dp[i] gives whether is it possible to get i as sum of
    // elements dd is helper variable
    // we use dd to ignoring duplicates
    bool dp[y], dd[y];
 
    // Initialising dp and dd
    for (int i = 0; i < y; i++) {
        dp[i] = dd[i] = false;
    }
 
    // sum = 0 is possible
    dd[0] = true;
    for (int i = 0; i < n; i++) {
        // updating dd[k] as true if k can be formed using
        // elements from 1 to i+1
        for (int j = 0; j + arr[i] < y; j++) {
            if (dp[j])
                dd[j + arr[i]] = true;
        }
        // updating dd
        for (int j = 0; j < y; j++) {
            if (dd[j])
                dp[j] = true;
            dd[j] = false; // reset dd
        }
    }
    // checking the number from sum/2 to 1 which is possible
    // to get as sum
 
    for (int i = y - 1; i >= 0; i--) {
        if (dp[i])
            return (sum - 2 * i);
        // since i is possible to form then another number
        // is sum-i
        // so mindifference is sum-i-i
    }
}
int main()
{
 
    int arr[] = { 1, 6, 11, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The Minimum difference of 2 sets is "
         << minDifference(arr, n) << '\n';
    return 0;
}
```
**Output**

The Minimum difference of 2 sets is 1

**Time Complexity:** O(n*sum)  
**Auxiliary Space:** O(sum)

Note that the above solution is in Pseudo Polynomial Time (time complexity is dependent on the numeric value of input).

----
5. Ways to Cover a Distance

Given a distance ‘dist’, count total number of ways to cover the distance with 1, 2 and 3 steps.
**Examples:**
**Input:** n = 3
**Output:** 4
**Explanation:**
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step

**Input:** n = 4
**Output:** 7
**Explanation:**
Below are the four ways
 1 step + 1 step + 1 step + 1 step
 1 step + 2 step + 1 step
 2 step + 1 step + 1 step 
 1 step + 1 step + 2 step
 2 step + 2 step
 3 step + 1 step
 1 step + 3 step
**Recursive solution**  

-   **Approach:** There are n stairs, and a person is allowed to next step, skip one position or skip two positions. So there are n positions. The idea is standing at the ith position the person can move by i+1, i+2, i+3 position. So a recursive function can be formed where at current index i the function is recursively called for i+1, i+2 and i+3 positions.   
    There is another way of forming the recursive function. To reach position i, a person has to jump either from i-1, i-2 or i-3 position where i is the starting position.   
     
-   **Algorithm:** 
    1.  Create a recursive function (_count(int n)_) which takes only one parameter.
    2.  Check the base cases. If the value of n is less than 0 then return 0, and if value of n is equal to zero then return 1 as it is the starting position.
    3.  Call the function recursively with values n-1, n-2 and n-3 and sum up the values that are returned, i.e. _sum = count(n-1) + count(n-2) + count(n-3)_.
    4.  Return the value of _sum_.
-   **Implementation:**

```cpp
// A naive recursive C++ program to count number of ways to cover
// a distance with 1, 2 and 3 steps
#include<iostream>
using namespace std;
 
// Returns count of ways to cover 'dist'
int printCountRec(int dist)
{
    // Base cases
    if (dist<0)      return 0;
    if (dist==0)  return 1;
 
    // Recur for all previous 3 and add the results
    return printCountRec(dist-1) +
           printCountRec(dist-2) +
           printCountRec(dist-3);
}
 
// driver program
int main()
{
    int dist = 4;
    cout << printCountRec(dist);
    return 0;
}

```
**Output:**

  

  

7

-   **Complexity Analysis:** 
    -   **Time Complexity:** O(3n).   
        The time complexity of the above solution is exponential, a close upper bound is O(3n). From each state 3, a recursive function is called. So the upper bound for n states is O(3n).
    -   **Space complexity:** O(1).   
        No extra space is required.

**Efficient solution**  

-   **Approach:** The idea is similar, but it can be observed that there are n states but the recursive function is called 3 ^ n times. That means that some states are called repeatedly. So the idea is to store the value of states. This can be done in two ways. 
    -   The first way is to keep the recursive structure intact and just store the value in a HashMap and whenever the function is called, return the value store without computing (Top-Down Approach).
    -   The second way is to take an extra space of size n and start computing values of states from 1, 2 .. to n, i.e. compute values of i, i+1, i+2 and then use them to calculate the value of i+3 (Bottom-Up Approach).
    -   [Overlapping Subproblems in Dynamic Programming.](https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/)
    -   [Optimal substructure property in Dynamic Programming.](https://www.geeksforgeeks.org/optimal-substructure-property-in-dynamic-programming-dp-2/)
    -   [Dynamic Programming(DP) problems](https://www.geeksforgeeks.org/archives/tag/dynamic-programming)
-   **Algorithm:** 
    1.  Create an array of size n + 1 and initialize the first 3 variables with 1, 1, 2. The base cases.
    2.  Run a loop from 3 to n.
    3.  For each index i, compute value of ith position as _dp[i] = dp[i-1] + dp[i-2] + dp[i-3]_.
    4.  Print the value of dp[n], as the Count of number of ways to cover a distance.
-   **Implementation:**


```cpp
// A Dynamic Programming based C++ program to count number of ways
// to cover a distance with 1, 2 and 3 steps
#include<iostream>
using namespace std;
 
int printCountDP(int dist)
{
    int count[dist+1];
 
    // Initialize base values. There is one way to cover 0 and 1
    // distances and two ways to cover 2 distance
     count[0] = 1;
     if(dist >= 1)
            count[1] = 1;
     if(dist >= 2)
              count[2] = 2;
 
    // Fill the count array in bottom up manner
    for (int i=3; i<=dist; i++)
       count[i] = count[i-1] + count[i-2] + count[i-3];
 
    return count[dist];
}
 
// driver program
int main()
{
    int dist = 4;
    cout << printCountDP(dist);
    return 0;
}
```

**Output :**

7

-   **Complexity Analysis:** 
    -   **Time Complexity:** O(n).   
        Only one traversal of the array is needed. So Time Complexity is O(n)
    -   **Space complexity:** O(n).   
        To store the values in a DP O(n) extra space is needed.

**More Optimal Solution**

    **Approach:** Instead of using array of size n+1 we can use array of size 3 because for calculating no of ways for a particular step we need only last     3 steps no of ways.

 **Algorithm:**

1.  Create an array of size 3 and initialize the values for step 0,1,2 as 1,1,2 (Base cases).
2.  Run a loop from 3 to n(dist).
3.  For each index compute the value as ways[i%3] = ways[(i-1)%3] + ways[(i-2)%3] + ways[(i-3)%3] and store its value at i%3 index of array ways. If we are computing value for index 3 then the computed value will go at index 0 because for larger indices(4 ,5,6…..) we don’t need the value of index 0.
4.  Return the value of ways[n%3].

```cpp
// A Dynamic Programming based C++ program to count number of ways
#include<iostream>
using namespace std;
  
int printCountDP(int dist)
{
        //Create the array of size 3.
        int  ways[3] , n = dist;
         
        //Initialize the bases cases
        ways[0] = 1;
        ways[1] = 1;
        ways[2] = 2;
         
        //Run a loop from 3 to n
        //Bottom up approach to fill the array
        for(int i=3 ;i<=n ;i++)
            ways[i%3] = ways[(i-1)%3] + ways[(i-2)%3] + ways[(i-3)%3];
         
        return ways[n%3];
}
  
// driver program
int main()
{
    int dist = 4;
    cout << printCountDP(dist);
    return 0;
}
```

**Output :** 

7

**Time Complexity : O(n)**

**Space Complexity : O(1)**




----
6. Longest Path In Matrix





















----
7. Subset Sum Problem





















----
8. Optimal Strategy for a Game





















----
9. 0-1 Knapsack Problem





















----
10. Boolean Parenthesization Problem























----