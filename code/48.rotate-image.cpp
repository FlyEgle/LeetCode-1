/*
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image
 *
 * algorithms
 * Medium (38.40%)
 * Total Accepted:    118.4K
 * Total Submissions: 308.2K
 * Testcase Example:  '[[1]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int x = 0, y = n - 1;

        while (x < y) {
            for (int i = 0; i < y - x; ++i) {
                swap(matrix[x][x + i], matrix[x + i][y]);
                swap(matrix[x][x + i], matrix[y][y - i]);
                swap(matrix[x][x + i], matrix[y - i][x]);
            }
            ++x;
            --y;
        }
    }
};
