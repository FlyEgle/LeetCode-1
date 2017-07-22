/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation
 *
 * Medium (28.65%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return ;

        int index = nums.size() - 1;
        while (index > 0) {
            if (nums[index - 1] < nums[index]) {
                break;
            }
            --index;
        }

        if (0 == index) {
            sort(nums.begin(), nums.end());
        } else {
            int i = nums.size() - 1;
            while (i >= index) {
                if (nums[i] > nums[index - 1])
                    break;
                --i;
            }
            swap(nums[index - 1], nums[i]);
            sort(nums.begin() + index, nums.end());
        }

        return ;
    }
};
