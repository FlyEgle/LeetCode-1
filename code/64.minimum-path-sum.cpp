/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum
 *
 * algorithms
 * Medium (38.37%)
 * Total Accepted:    119.9K
 * Total Submissions: 310.4K
 * Testcase Example:  '[[0]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() < 1) return 0;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));

        dp[0][1] = 0;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];

        return dp[m][n];
    }
};
