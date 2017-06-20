/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses
 *
 * Medium (43.92%)
 * Total Accepted:    145976
 * Total Submissions: 331469
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generatePar(res, "", n, 0);
        return res;
    }

    void generatePar(vector<string> &res, string str, int n, int m) {
        if (n == 0 && m == 0) {
            res.push_back(str);
            return ;
        }

        if (n > 0)
            generatePar(res, str+'(', n-1, m+1);
        if (m > 0)
            generatePar(res, str+')', n, m-1);
    }
};
