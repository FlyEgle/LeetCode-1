// 加法单调性

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
