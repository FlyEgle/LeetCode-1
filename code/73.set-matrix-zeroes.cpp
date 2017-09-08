/*
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes
 *
 * algorithms
 * Medium (35.87%)
 * Total Accepted:    110.7K
 * Total Submissions: 307.7K
 * Testcase Example:  '[[0]]'
 *
 * 
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in place.
 * 
 * 
 * click to show follow up.
 * 
 * Follow up:
 * 
 * 
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = false;
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            if (0 == matrix[i][0]) col0 = true;
            for (int j = 1; j < n; ++j) {
                if (0 == matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = 1; j < n; ++j) {
                if (0 == matrix[i][0] || 0 == matrix[0][j])
                    matrix[i][j] = 0;
            }
            if (true == col0) matrix[i][0] = 0;
        }
    }
};
