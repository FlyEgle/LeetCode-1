/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens
 *
 * algorithms
 * Hard (30.84%)
 * Total Accepted:    81.5K
 * Total Submissions: 264.1K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * 
 * [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ctx(n, string(n, '.'));
        solveNQueens(res, ctx, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string>>& res, vector<string>& ctx, int row, int n) {
        if (row == n) {
            res.push_back(ctx);
            return ;
        }

        for (int col = 0; col != n; ++col) {
            if (check(ctx, row, col, n)) {
                ctx[row][col] = 'Q';
                solveNQueens(res, ctx, row + 1, n);
                ctx[row][col] = '.';
            }
        }
    }

    bool check(vector<string>& ctx, int row, int col, int n) {
        for (int i = 0; i != row; ++i)
            if ('Q' == ctx[i][col])
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if ('Q' == ctx[i][j])
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if ('Q' == ctx[i][j])
                return false;
        return true;
    }
};
