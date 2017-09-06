/*
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number
 *
 * algorithms
 * Hard (12.72%)
 * Total Accepted:    70.9K
 * Total Submissions: 556.7K
 * Testcase Example:  '"3"'
 *
 * Validate if a given string is numeric.
 * 
 * 
 * Some examples:
 * "0" => true
 * "   0.1  " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * 
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one.
 * 
 * 
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button  to reset your code definition.
 * 
 */
class Solution {
public:
    /*
     * DFA:
     *
     * [ ]q1--blank-->q1, q1--sign-->q2, q1--digit-->q3, q1--dot-->q4,
     * [ ]q2--digit-->q3, q2--dot-->q4,
     * [x]q3--digit-->q3, q3--dot-->q5, q3--e-->q6, q3--blank-->q9,
     * [ ]q4--digit-->q5,
     * [x]q5--digit-->q5, q5--e-->q6, q5--blank-->q9,
     * [ ]q6--sign-->q7, q6--digit-->q8,
     * [ ]q7--digit-->q8,
     * [x]q8--digit-->q8, q8--blank-->q9,
     * [x]q9--blank-->q9
     *
     */
    bool isNumber(string s) {
        int n = s.length();
        if (n < 1) return false;

        int state = 1;

        for (int i = 0; i < n; ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                if (1 <= state && state <= 3) state = 3;
                else if (4 <= state && state <= 5) state = 5;
                else if (6 <= state && state <= 8) state = 8;
                else return false;
            } else if (' ' == s[i]) {
                if (1 == state) state = 1;
                else if (3 == state || 5 == state || 8 == state || 9 == state) state = 9;
                else return false;
            } else if ('.' == s[i]) {
                if (1 <= state && state <= 2) state = 4;
                else if (3 == state) state = 5;
                else return false;
            } else if ('+' == s[i] || '-' == s[i]){
                if (1 == state) state = 2;
                else if (6 == state) state = 7;
                else return false;
            } else if ('e' == s[i]) {
                if (3 == state || 5 == state) state = 6;
                else return false;
            } else {
                return false;
            }
        }

        if (3 == state || 5 == state || 8 == state || 9 == state)
            return true;
        else
            return false;
    }
};
