/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii
 *
 * algorithms
 * Medium (32.60%)
 * Total Accepted:    123.7K
 * Total Submissions: 379.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * 
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * 
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        do {
            vector<int> tmp(nums);
            res.push_back(tmp);
        } while (next_permutation(nums.begin(), nums.end()));

        return res;
    }
};
