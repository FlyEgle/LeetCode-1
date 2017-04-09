class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> v(nums.begin(), nums.end());
        int ans, sum;
        int size = v.size();

        sort(v.begin(), v.end());

        while (v.size() <= 3)
            return accumulate(v.begin(), v.end(), 0);

        ans = v[0] + v[1] + v[2];
        for (int i = 0; i < size -2 ; i++) {
            int left = i + 1;
            int right = size - 1;

            while (left < right) {
                sum = v[i] + v[left] + v[right];
                if (abs(target - ans) > abs(target - sum)) {
                    ans = sum;
                    if (ans == target) return ans;
                }

                sum > target ? right-- : left++;
            }
        }

        return ans;
    }
};
