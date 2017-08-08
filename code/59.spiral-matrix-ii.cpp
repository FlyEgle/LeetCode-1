/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii
 *
 * algorithms
 * Medium (39.48%)
 * Total Accepted:    83.4K
 * Total Submissions: 210.8K
 * Testcase Example:  '0'
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n2 in spiral order.
 * 
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0, down = n - 1, left = 0, right = n - 1;

        int num = 1;
        while (true) {
            for (int col = left; col <= right; ++col)
                res[up][col] = num++;
            if (++up > down) break;

            for (int row = up; row <= down; ++row)
                res[row][right] = num++;
            if (--right < left) break;

            for (int col = right; col >= left; --col)
                res[down][col] = num++;
            if (--down < up) break;

            for (int row = down; row >= up; --row)
                res[row][left] = num++;
            if (++left > right) break;
        }

        return res;
    }
};
