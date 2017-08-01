/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum
 *
 * algorithms
 * Medium (38.36%)
 * Total Accepted:    164.3K
 * Total Submissions: 428.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T. 
 * 
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * 
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ctx;

        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, res, ctx, 0);

        return res;
    }

    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& ctx, int begin) {
        if (!target) {
            res.push_back(ctx);
            return ;
        }

        for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
            ctx.push_back(candidates[i]);
            combinationSum(candidates, target-candidates[i], res, ctx, i);
            ctx.pop_back();
        }
    }
};
