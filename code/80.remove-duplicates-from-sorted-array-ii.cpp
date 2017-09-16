/*
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
 *
 * algorithms
 * Medium (35.87%)
 * Total Accepted:    126.3K
 * Total Submissions: 349.5K
 * Testcase Example:  '[]'
 *
 * 
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * 
 * 
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * 
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new
 * length.
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 2, n = nums.size();

        if (n < 3) return n;

        for (int i = 2; i < n; ++i)
            if (nums[i] != nums[res - 2])
                nums[res++] = nums[i];

        return res;
    }
};
