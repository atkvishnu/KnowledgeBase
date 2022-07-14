# [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

> Method 1: Hash table
> Method 2: using a flag, and, iterating through the vector
> Method 3: unordered_set<int> m; (return (m.size() != nums.size())
> Method 4: Sorting

---

# [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) \*\*\*\*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

> Try Kadanes Algorithm later ??

```cpp
int maxSubArray(vector<int>& nums) {
        int cs = nums[0], ms = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            cs = max(nums[i], cs+nums[i]);
            ms = max(cs,ms);
        }
        return ms;
    }
```

```cpp
int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int temp = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            temp += nums[i];
            ans = max(ans, temp);
            if(temp < 0) temp = 0;
        }
        return ans;
    }
```

# [1. Two Sum](https://leetcode.com/problems/two-sum/)

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

> -   Map the elements into a unordered_map `m`.
> -   Declare a extra vector for answer.
> -   Add all the elements into the unordered_map by using a loop (m[nums[i]] = i;)
> -   Parse through the vector and maintain a variable(req = target - nums[i]) inside the loop .
> -   If this element is present in the unordered_map(m.count(req) && m[req] != i) then add that particular index(which is present in the unordered map) and the index of the variable(target - nums[i]) into the answer vector.
> -   Return the vector.

---

# [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

> -   Use 3 pointers. i,j,k @ end of nums1's elements, nums2, nums1
> -   i = m-1, j = n-1, k = m+n-1;
> -   Start a while loop, while(i>=0 && j>=0)
> -   if(nums1[i]>=nums2[j]){nums1[k--]=nums1[i--];}
> -   else{nums1[k--]=nums2[j--];}
> -   At last outside the while loop, some elements may be left in nums2, copy them using another while loop.
> -   while(j>=0){nums[k--]==nums[j--];}

---

# [350. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

> -   Sorted both the vectors.
> -   Declare a `answer` vector
> -   intitialize i = 0, j = 0
> -   sort nums1 and nums2
> -   `while(i<nums1.size() && j<nums2.size()) {`
> -   `if(nums1[i]==nums2[j]){ answer.push_back(i);i++;j++;}`
> -   `else if(nums1[i]<nums2[j]){i++;} else {j++;}`
> -   `return answer`

### OR

using unordered_map

```cpp
vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
  unordered_map<int, int> m;
  vector<int> answer;
  for(int i: nums1) m[i]++;
  for(int i: nums2) {
      if(--m[i] > 0) answer.push_back(i);
  }
  return answer;
}
```

---

# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

```cpp
/*
// xxxxxxxxxxxxxxxxxxxxxxxxxx TLE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int sz = prices.size();
        vector<int> prof;
        // for(i,k; i < sz, k < sz-1; i++, k++) {
        //     int diff = prices[i]-prices[k];
        //     if(diff>=0) prof.push_back(diff);
        // }
        for(int i = 0; i < sz; i++) {
            for(int j = i+1; j < sz; j++) {
                int diff = prices[j] - prices[i];
                if(diff>=0) prof.push_back(diff);
            }
        }
        sort(prof.begin(),prof.end());
        if(prof.empty()) {
            return 0;
        }
        return prof.back();
    }
};
// xxxxxxxxxxxxxxxxxxxxxxxxxxx TLE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 1e4;
        int res = 0;
        for(int price: prices) {
            buy = min(buy, price);
            res = max(res, price-buy);
        }
        return res;
    }
};

```

---

# [566. Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/)

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m*n!=r*c) return mat;

        vector<vector<int>> mat1( r , vector<int> (c, 0));
        // for(int i = 0; i < r; i++) {
        //     for(int j = 0; j < c; j++) {
        //         int k = i * c + j;
        //         mat1[i][j] = mat[k/n][k%n];
        //     }
        // }
        // return mat1;
        // --------------------------------
        for (int i = 0; i < r * c; ++i) {
            mat1[i / c][i % c] = mat[i / n][i % n];
        }
        return mat1;
    }
};
```

---

# [118. Pascals Triangle](https://leetcode.com/problems/pascals-triangle/)

Given an integer numRows, return the first numRows of Pascals triangle. In Pascals triangle, each number is the sum of the two numbers directly above it as shown:

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows, vector<int>());
        for(int i = 0; i < numRows; i++) {
            pascal[i].resize(i+1, 1);
            for(int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};
```

---

# [36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/submissions/)

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = 9, c = 9;
        vector<vector<bool>> rows(r, vector<bool>(c));
        vector<vector<bool>> cols(r, vector<bool>(c));
        vector<vector<bool>> cells(r, vector<bool>(c));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j]=='.') continue;
                int c = board[i][j] - '1';
                if(rows[i][c] || cols[c][j] || cells[3*(i/3)+j/3][c]) return false;
                rows[i][c] = true;
                cols[c][j] = true;
                cells[3*(i/3)+j/3][c] = true;
            }
        }
        return true;

    }
};

// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                string t = "(" + to_string(board[i][j]) + ")";
                string row = to_string(i) + t, col = t + to_string(j), cell = to_string(i / 3) + t + to_string(j / 3);
                if (st.count(row) || st.count(col) || st.count(cell)) return false;
                st.insert(row);
                st.insert(col);
                st.insert(cell);
            }
        }
        return true;
    }
};
*/
```

---

# [74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int left = 0, right = matrix.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] <= target) left = mid + 1;
            else right = mid;
        }
        int tmp = (right > 0) ? (right - 1) : right;
        left = 0;
        right = matrix[tmp].size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[tmp][mid] == target) return true;
            if (matrix[tmp][mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
*/

/**/

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if (matrix.empty() || matrix[0].empty()) return false;
//         int m = matrix.size(), n = matrix[0].size();
//         int left = 0, right = m * n;
//         while (left < right) {
//             int mid = (left + right) / 2;
//             if (matrix[mid / n][mid % n] == target) return true;
//             if (matrix[mid / n][mid % n] < target) left = mid + 1;
//             else right = mid;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) --j;
            else ++i;
        }
        return false;
    }
};

```

---
