/* Discuss 里一个 O(log(min(m, n))) 算法还没理解 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        nums.resize(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());

        int size = nums.size();
        int index;
        double result;
        if (size & 1) {
            index = (size - 1) / 2;
            result = nums[index];
        } else {
            index = size / 2;
            result = (double)(nums[index - 1] + nums[index]) / 2;
        }

        return result;
    }
};
