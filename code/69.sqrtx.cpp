/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx
 *
 * algorithms
 * Easy (27.76%)
 * Total Accepted:    171.6K
 * Total Submissions: 615.3K
 * Testcase Example:  '0'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 */
class Solution {
public:
    int mySqrt(int x) {
        long ans = 0;
        long bit = 1l << (sizeof(int) * 4 - 1);

        while (bit > 0) {
            ans |= bit;
            if (ans * ans > x) {
                ans ^= bit;
            }
            bit >>= 1;
        }

        return (int)ans;
    }
};
