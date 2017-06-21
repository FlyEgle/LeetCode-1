/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers
 *
 * Medium (15.97%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '0\n1'
 *
 * 
 * Divide two integers without using multiplication, division and mod
 * operator.
 * 
 * 
 * If it is overflow, return MAX_INT.
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        if (divisor == 1) return dividend;
        if (!dividend) return 0;

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long divd = labs(dividend), divs = labs(divisor);
        int res = 0;

        while (divd >= divs) {
            long temp = divs, mul = 1;
            while (divd >= (temp << 1)) {
                temp <<= 1;
                mul <<= 1;
            }
            divd -= temp;
            res += mul;
        }

        return sign == 1 ? res : -res;
    }
};
