// https://leetcode.com/problems/search-a-2d-matrix/

/*
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
*/

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

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};
