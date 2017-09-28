/*
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle
 *
 * algorithms
 * Hard (27.71%)
 * Total Accepted:    72.4K
 * Total Submissions: 255.7K
 * Testcase Example:  '["10100","10111","11111","10010"]'
 *
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 6.
 * 
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        int res = 0;

        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                    height[j] = height[j] + 1;
                } else {
                    left[j] = 0, cur_left = j + 1;
                    height[j] = 0;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else
                    right[j] = n, cur_right = j;
            }

            for (int j = 0; j < n; ++j)
                res = max(res, (right[j] - left[j]) * height[j]);
        }

        return res;
    }
};
