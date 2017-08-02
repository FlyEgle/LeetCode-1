/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations
 *
 * algorithms
 * Medium (43.40%)
 * Total Accepted:    172.8K
 * Total Submissions: 397.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a collection of distinct numbers, return all possible permutations.
 * 
 * 
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * 
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        do {
            vector<int> tmp(nums);
            res.push_back(tmp);
        } while (next_permutation(nums.begin(), nums.end()));

        return res;
    }
};
