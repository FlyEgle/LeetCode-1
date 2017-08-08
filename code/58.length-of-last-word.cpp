/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word
 *
 * algorithms
 * Easy (31.79%)
 * Total Accepted:    151.6K
 * Total Submissions: 476.7K
 * Testcase Example:  '""'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * 
 * For example, 
 * Given s = "Hello World",
 * return 5.
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (' ' == s[i]) {
                if (i + 1 < s.length() && ' ' != s[i + 1]) res = 0;
            } else {
                ++res;
            }
        }

        return res;
    }
};
