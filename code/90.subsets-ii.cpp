/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii
 *
 * algorithms
 * Medium (35.95%)
 * Total Accepted:    123K
 * Total Submissions: 334.8K
 * Testcase Example:  '[1,2,2]'
 *
 * 
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,2], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        int start = 0, size = 0;
        for (int i = 0; i < nums.size(); ++i) {
            start = (i > 0 && nums[i] == nums[i-1]) ? size : 0;
            size = res.size();
            for (int j = start; j < size; ++j) {
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
