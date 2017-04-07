class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    vector<int> tmp(3, 0);
                    tmp[0] = nums[i];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    result.push_back(tmp);

                    while (left < right && nums[left] == tmp[1]) left++;
                    while (left < right && nums[right] == tmp[2]) right--;
                }
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }

        return result;
    }
};
