/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring
 *
 * algorithms
 * Hard (25.17%)
 * Total Accepted:    112.5K
 * Total Submissions: 440.6K
 * Testcase Example:  '"a"\n"a"'
 *
 * 
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * 
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * 
 * 
 * Minimum window is "BANC".
 * 
 * 
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * 
 * 
 * If there are multiple such windows, you are guaranteed that there will
 * always be only one unique minimum window in S.
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (auto c : t) map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) counter--;
            while (0 == counter) {
                if (end - begin < d) d = end - (head = begin);
                if (map[s[begin++]]++ == 0) counter++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
