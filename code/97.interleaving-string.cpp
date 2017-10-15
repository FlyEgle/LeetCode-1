/*
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string
 *
 * algorithms
 * Hard (24.54%)
 * Total Accepted:    75.1K
 * Total Submissions: 302.9K
 * Testcase Example:  '""\n""\n""'
 *
 * 
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * 
 * 
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 * 
 * 
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 * 
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;

        vector<vector<bool>> dp(s1.length()+1, vector<bool>(s2.length()+1, false));
        for (int i = 0; i <= s1.length(); ++i) {
            for (int j = 0; j <= s2.length(); ++j) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                else if (j == 0)
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                else
                    dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1])
                            || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }

        return dp[s1.length()][s2.length()];
    }
};
