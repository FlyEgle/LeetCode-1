/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses
 *
 * Hard (23.00%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * For "(()", the longest valid parentheses substring is "()", which has length
 * = 2.
 * 
 * 
 * Another example is ")()())", where the longest valid parentheses substring
 * is "()()", which has length = 4.
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0, n = s.length();

        for (int i = 0; i < n; ++i) {
            if ('(' == s[i]) st.push(i);
            else {
                if (!st.empty()) {
                    if ('(' == s[st.top()]) st.pop();
                    else st.push(i);
                } else
                    st.push(i);
            }
        }

        if (st.empty()) ans = n;
        else {
            int a = n, b = 0;
            while (!st.empty()) {
                b = st.top();
                st.pop();
                ans = max(ans, a - b - 1);
                a = b;
            }
            ans = max(ans, a);
        }

        return ans;
    }
};
