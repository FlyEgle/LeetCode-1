/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water
 *
 * algorithms
 * Hard (36.61%)
 * Total Accepted:    118.4K
 * Total Submissions: 323.4K
 * Testcase Example:  '[]'
 *
 * 
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after
 * raining. 
 * 
 * 
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * 
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 */
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 1) return 0;

        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int res = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) maxLeft = height[left];
                else res += maxLeft - height[left];
                ++left;
            } else {
                if (height[right] >= maxRight) maxRight = height[right];
                else res += maxRight - height[right];
                --right;
            }
        }

        return res;
    }
};
