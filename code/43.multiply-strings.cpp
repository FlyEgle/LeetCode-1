/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings
 *
 * algorithms
 * Medium (26.98%)
 * Total Accepted:    105.6K
 * Total Submissions: 391.4K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size()+num2.size(), '0');

        for (int i = num1.size()-1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size()-1; j >= 0; --j) {
                int tmp = (sum[i+j+1] - '0') +
                          (num1[i] - '0') * (num2[j] - '0') +
                          carry;
                sum[i+j+1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }

        size_t pos = sum.find_first_not_of("0");
        if (string::npos != pos)
            return sum.substr(pos);
        else
            return "0";
    }
};
