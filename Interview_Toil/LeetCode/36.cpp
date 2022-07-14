// https://leetcode.com/problems/valid-sudoku/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int r = 9, c = 9;
        vector<vector<bool>> rows(r, vector<bool>(c));
        vector<vector<bool>> cols(r, vector<bool>(c));
        vector<vector<bool>> cells(r, vector<bool>(c));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int c = board[i][j] - '1';
                if (rows[i][c] || cols[c][j] || cells[3 * (i / 3) + j / 3][c])
                    return false;
                rows[i][c] = true;
                cols[c][j] = true;
                cells[3 * (i / 3) + j / 3][c] = true;
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