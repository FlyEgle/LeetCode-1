/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix
 *
 * algorithms
 * Medium (35.10%)
 * Total Accepted:    132K
 * Total Submissions: 377.3K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * 
 * 
 * For example,
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * 
 * 
 * Given target = 3, return true.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 1) return false;

        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (target == matrix[i][j]) return true;
                if (target > matrix[i][j]) break;
                if (target < matrix[i][j] && 0 == j) return false;
            }
        }

        return false;
    }
};
