/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix
 *
 * algorithms
 * Medium (25.85%)
 * Total Accepted:    104.3K
 * Total Submissions: 403.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * 
 * 
 * For example,
 * Given the following matrix:
 * 
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 
 * You should return [1,2,3,6,9,8,7,4,5].
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int up = 0, down = m - 1, left = 0, right = n - 1;

        while (true) {
            for (int col = left; col <= right; ++col)
                res.push_back(matrix[up][col]);
            if (++up > down) break;

            for (int row = up; row <= down; ++row)
                res.push_back(matrix[row][right]);
            if (--right < left) break;

            for (int col = right; col >= left; --col)
                res.push_back(matrix[down][col]);
            if (--down < up) break;

            for (int row = down; row >= up; --row)
                res.push_back(matrix[row][left]);
            if (++left > right) break;
        }

        return res;
    }
};
