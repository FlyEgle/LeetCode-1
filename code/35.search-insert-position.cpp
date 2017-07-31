/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position
 *
 * algorithms
 * Easy (39.67%)
 * Total Accepted:    183.9K
 * Total Submissions: 463.5K
 * Testcase Example:  '[1]\n0'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() < 1) return 0;

        int left = 0, right = nums.size() - 1, mid = 0;

        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }
};
