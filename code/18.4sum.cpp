class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;

        if (nums.size() < 4)
            return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            int res = target - nums[i];

            for (int j = i+1; j < nums.size(); j++) {
                int ans = res - nums[j];
                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int sum = nums[left] + nums[right];

                    if (sum < ans) {
                        left++;
                    } else if (sum > ans) {
                        right--;
                    } else {
                        vector<int> tmp(4, 0);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[left];
                        tmp[3] = nums[right];
                        result.push_back(tmp);

                        while (left < right && nums[left] == tmp[2]) left++;
                        while (left < right && nums[right] == tmp[3]) right--;
                    }
                }

                while (j + 1 < nums.size() && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }

        return result;
    }
};
