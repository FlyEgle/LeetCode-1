/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game
 *
 * algorithms
 * Medium (29.51%)
 * Total Accepted:    126.8K
 * Total Submissions: 429.7K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Determine if you are able to reach the last index.
 * 
 * 
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 * 
 * 
 * A = [3,2,1,0,4], return false.
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0, maxi = 0, n = nums.size();
        for (; index < n && index <= maxi && maxi < n - 1; ++index)
            maxi = max(maxi, index + nums[index]);
        return maxi >= n - 1;
    }
};
