/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching
 *
 * Hard (23.96%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * 
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<vector<bool> > f(sLen + 1, vector<bool>(pLen + 1, false));

        // 预处理
        f[0][0] = true;
        for (int i = 1; i <= sLen; i++)
            f[i][0] = false;
        for (int j = 1; j <= pLen; j++)
            f[0][j] = j > 1 && ('*' == p[j - 1]) && f[0][j - 2];

        // 填表
        for (int i = 1; i <= sLen; i++)
            for (int j = 1; j <= pLen; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] &&
                              (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    f[i][j] = f[i][j - 2] ||
                              (s[i - 1] == p[j - 2] || '.' == p[j - 2]) &&
                              f[i - 1][j];

                return f[sLen][pLen]; 
    }
};
