/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range
 *
 * algorithms
 * Medium (31.33%)
 * Total Accepted:    142K
 * Total Submissions: 453.4K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        if (nums.size() < 1) return ret;

        int left = 0, right = nums.size() - 1, mid = 0;

        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (target != nums[left]) return ret;
        else ret[0] = left;

        right = nums.size() - 1;
        while (left < right) {
            mid = (left + right) / 2 + 1;
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        ret[1] = right;

        return ret;
    }
};
