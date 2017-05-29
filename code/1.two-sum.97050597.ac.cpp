/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum
 *
 * Easy (33.10%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> r(nums.size());

        for (int i = 0; i < r.size(); i++) r[i] = i;

        sort(r.begin(), r.end(), [&](int x, int y) { return nums[x] < nums[y]; });

        for (int i = 0, j = nums.size() - 1; i < j; i++) {
            while (j > i + 1 && nums[r[i]] + nums[r[j]] > target) j--;

            if (nums[r[i]] + nums[r[j]] == target) {
                int x = r[i], y = r[j];
                r.clear();

                if (x > j) swap(x, y);
                r.push_back(x);
                r.push_back(y);
                break;
            }
        }

        return r;
    }
};
