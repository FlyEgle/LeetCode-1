/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray
 *
 * algorithms
 * Easy (39.52%)
 * Total Accepted:    211K
 * Total Submissions: 533.8K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 * 
 * 
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int sum = dp[0];

        for (int i = 1; i != nums.size(); ++i) {
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            sum = max(sum, dp[i]);
        }

        return sum;
    }
};
