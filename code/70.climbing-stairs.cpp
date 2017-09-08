/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs
 *
 * algorithms
 * Easy (39.87%)
 * Total Accepted:    191.1K
 * Total Submissions: 476.3K
 * Testcase Example:  '1'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * 
 * Note: Given n will be a positive integer.
 * 
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (1 == n) return 1;
        if (2 == n) return 2;

        int ans = 0, f1 = 1, f2 = 2;

        for (int i = 2; i < n; ++i) {
            ans = f1 + f2;
            f1 = f2;
            f2 = ans;
        }

        return ans;
    }
};
