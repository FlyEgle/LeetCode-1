/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations
 *
 * algorithms
 * Medium (39.48%)
 * Total Accepted:    123.2K
 * Total Submissions: 309K
 * Testcase Example:  '4\n2'
 *
 * 
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ctx;

        combine(res, ctx, 1, n, k);

        return res;
    }

private:
    void combine(vector<vector<int>>& res, vector<int>& ctx, int begin, int n, int k) {
        if (0 == k) {
            res.push_back(ctx);
            return ;
        }

        for (int i = begin; i <= n; ++i) {
            ctx.push_back(i);
            combine(res, ctx, i + 1, n, k - 1);
            ctx.pop_back();
        }
    }
};
