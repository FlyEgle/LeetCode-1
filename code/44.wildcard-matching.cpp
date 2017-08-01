/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching
 *
 * algorithms
 * Hard (19.95%)
 * Total Accepted:    96K
 * Total Submissions: 480.9K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") ? false
 * isMatch("aa","aa") ? true
 * isMatch("aaa","aa") ? false
 * isMatch("aa", "*") ? true
 * isMatch("aa", "a*") ? true
 * isMatch("ab", "?*") ? true
 * isMatch("aab", "c*a*b") ? false
 * 
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<bool> dp(m + 1, false);

        dp[0] = true;
        for (int j = 1; j <= n; ++j) {
            bool pre = dp[0];
            dp[0] = dp[0] && p[j - 1] == '*';
            for (int i = 1; i <= m; ++i) {
                bool tmp = dp[i];
                if ('*' == p[j - 1])
                    dp[i] = dp[i - 1] || dp[i];
                else
                    dp[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                pre = tmp;
            }
        }

        return dp[m];
    }
};
