/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary
 *
 * algorithms
 * Easy (32.23%)
 * Total Accepted:    156K
 * Total Submissions: 479K
 * Testcase Example:  '"0"\n"0"'
 *
 * 
 * Given two binary strings, return their sum (also a binary string).
 * 
 * 
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int carry = 0, i = a.length() - 1, j = b.length() - 1;

        while (i >= 0 || j >= 0 || 1 == carry) {
            carry += (i >= 0 ? a[i--] - '0' : 0);
            carry += (j >= 0 ? b[j--] - '0' : 0);
            s = char(carry % 2 + '0') + s;
            carry /= 2;
        }

        return s;
    }
};
