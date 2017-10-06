/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways
 *
 * algorithms
 * Medium (19.55%)
 * Total Accepted:    137.9K
 * Total Submissions: 695.5K
 * Testcase Example:  '""'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 * 
 * 
 * 
 * For example,
 * Given encoded message "12",
 * it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * 
 * The number of ways decoding "12" is 2.
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s.front() == '0') return 0;
        int r1 = 1, r2 = 1;
        for (int i = 1; i <= s.length(); ++i) {
            int t = 0;
            if (s[i-1] != '0') t += r1;
            if (i > 1 && (s[i-2] == '1' ||
                (s[i-2] == '2' && '0' <= s[i-1] && s[i-1] <= '6')))
                t += r2;
            r2 = r1;
            r1 = t;
        }
        return r1;
    }
};
