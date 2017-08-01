/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii
 *
 * algorithms
 * Hard (26.19%)
 * Total Accepted:    95K
 * Total Submissions: 362.7K
 * Testcase Example:  '[0]'
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
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * 
 * 
 * For example:
 * Given array A = [2,3,1,1,4]
 * 
 * 
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)
 * 
 * 
 * 
 * Note:
 * You can assume that you can always reach the last index.
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0;
        int begin = 0, end = 0;

        if (n < 1) return 0;

        while (end < n - 1) {
            ++step;
            int maxend = 0;

            for (int i = begin; i <= end; ++i) {
                if (i + nums[i] >= n - 1) return step;

                maxend = max(maxend, i + nums[i]);
            }

            begin = end + 1;
            end = maxend;
        }

        return step;
    }
};
