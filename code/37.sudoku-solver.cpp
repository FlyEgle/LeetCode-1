/*
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver
 *
 * algorithms
 * Hard (29.96%)
 * Total Accepted:    76.1K
 * Total Submissions: 254K
 * Testcase Example:  '["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * You may assume that there will be only one unique solution.
 * 
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }

    bool solveSudoku(vector<vector<char>>& board, int i, int j) {
        if (9 == i) return true;
        if (9 == j) return solveSudoku(board, i+1, 0);
        if ('.' != board[i][j]) return solveSudoku(board, i, j+1);

        for (char c = '1'; c <= '9'; ++c) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solveSudoku(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }

        return false;
    }

    bool check(vector<vector<char>>&board, int i, int j, char c) {
        int row = i - i % 3, col = j - j % 3;

        for (int x = 0; x < 9; ++x)
            if (c == board[x][j]) return false;
        for (int y = 0; y < 9; ++y)
            if (c == board[i][y]) return false;
        for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
                if (c == board[row + x][col + y])
                    return false;

        return true;
    }
};
