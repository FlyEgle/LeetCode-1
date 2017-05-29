/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest
 *
 * Medium (30.85%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[0,0,0]\n1'
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * ⁠   For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * ⁠   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> v(nums.begin(), nums.end());
        int ans, sum;
        int size = v.size();

        sort(v.begin(), v.end());

        while (v.size() <= 3)
            return accumulate(v.begin(), v.end(), 0);

        ans = v[0] + v[1] + v[2];
        for (int i = 0; i < size -2 ; i++) {
            int left = i + 1;
            int right = size - 1;

            while (left < right) {
                sum = v[i] + v[left] + v[right];
                if (abs(target - ans) > abs(target - sum)) {
                    ans = sum;
                    if (ans == target) return ans;
                }

                sum > target ? right-- : left++;
            }
        }

        return ans;        
    }
};
