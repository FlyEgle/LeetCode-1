/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n
 *
 * algorithms
 * Medium (26.38%)
 * Total Accepted:    158.3K
 * Total Submissions: 600.5K
 * Testcase Example:  '8.88023\n3'
 *
 * Implement pow(x, n).
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (0 == x)
            return 0;
        if (0 == n)
            return 1;
        if (INT_MIN == n)
            return 1 / (myPow(x, INT_MAX) * x);
        if (n < 1) {
            n = -n;
            x = 1 / x;
        }

        return n & 1 ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};
