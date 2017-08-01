/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii
 *
 * algorithms
 * Medium (33.49%)
 * Total Accepted:    118.2K
 * Total Submissions: 352.8K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 * 
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * 
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> ctx;

        combinationSum2(candidates, target, res, ctx, 0);
        return res;
    }

    void combinationSum2(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& ctx, int begin) {
        if (!target) {
            res.push_back(ctx);
            return ;
        }

        for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
            if (i > begin && candidates[i] == candidates[i-1]) continue;
            ctx.push_back(candidates[i]);
            combinationSum2(candidates, target-candidates[i], res, ctx, i+1);
            ctx.pop_back();
        }
    }
};
