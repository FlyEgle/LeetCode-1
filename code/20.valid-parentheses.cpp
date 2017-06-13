/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses
 *
 * Easy (33.12%)
 * Total Accepted:    201408
 * Total Submissions: 608141
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                Stack.push(')');
            else if (s[i] == '{')
                Stack.push('}');
            else if (s[i] == '[')
                Stack.push(']');
            else {
                if (Stack.empty() || Stack.top() != s[i])
                    return false;
                else
                    Stack.pop();
            }
        }

        if (Stack.empty())
            return true;
        else
            return false;
    }
};
