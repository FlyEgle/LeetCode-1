/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets
 *
 * algorithms
 * Medium (40.17%)
 * Total Accepted:    180.6K
 * Total Submissions: 439.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a set of distinct integers, nums, return all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [1],
 * ⁠ [2],
 * ⁠ [1,2,3],
 * ⁠ [1,3],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num = pow(2, nums.size());
        vector<vector<int>> res(num, vector<int>());

        for (int i = 0; i < nums.size(); ++i)
            for (int j = 0; j < num; ++j) if ((j >> i) & 1)
                    res[j].push_back(nums[i]);

        return res;
    }
};
