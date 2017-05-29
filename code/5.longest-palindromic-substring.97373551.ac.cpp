/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring
 *
 * Medium (25.10%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * Example:
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string str = "$#";
        for (int i = 0; i < s.length(); i++) {
            str += s[i];
            str += '#';
        }

        vector<int> p(2005, 0);
        int mx = 0, id = 0;

        for (int i = 1; i <= str.length(); i++) {
            p[i] = (mx > i) ? min(p[2 * id - i], mx - i) : 1;

            while (str[i + p[i]] == str[i - p[i]]) p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }

        int max = 0, index;
        for (int i = 1; i < str.length(); i++) {
            if (p[i] > max) {
                index = i;
                max = p[i];
            }
        }
        max--;

        int start = index - max;
        int end = index + max;
        string result = "";
        for (int i = start; i <= end; i++) {
            if (str[i] != '#') {
                result += str[i];
            }
        }

        vector<int>(p).swap(p);

        return result;       
    }
};
