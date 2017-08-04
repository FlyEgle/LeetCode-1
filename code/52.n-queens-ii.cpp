/*
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii
 *
 * algorithms
 * Hard (44.65%)
 * Total Accepted:    64.1K
 * Total Submissions: 143.3K
 * Testcase Example:  '1'
 *
 * Follow up for N-Queens problem.
 * 
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 * 
 * 
 */
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> ctx(n, vector<bool>(n, false));
        int res = 0;
        solveNQueens(res, ctx, 0, n);
        return res;
    }
private:
    void solveNQueens(int& res, vector<vector<bool>>& ctx, int row, int n) {
        if (row == n) {
            ++res;
            return ;
        }

        for (int col = 0; col != n; ++col) {
            if (check(ctx, row, col, n)) {
                ctx[row][col] = true;
                solveNQueens(res, ctx, row + 1, n);
                ctx[row][col] = false;
            }
        }
    }

    bool check(vector<vector<bool>>& ctx, int row, int col, int n) {
        for (int i = 0; i != row; ++i)
            if (ctx[i][col])
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (ctx[i][j])
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (ctx[i][j])
                return false;
        return true;
    }
};
