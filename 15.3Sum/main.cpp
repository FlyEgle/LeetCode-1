#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

class Test {
public:
    vector<int> input;
    vector<vector<int> > key;
    vector<vector<int> > result;

public:
    Test() {
        input.push_back(-1);
        input.push_back(0);
        input.push_back(1);
        input.push_back(2);
        input.push_back(-1);
        input.push_back(-4);

        vector<int> tmp;
        tmp.push_back(-1);
        tmp.push_back(-1);
        tmp.push_back(2);
        key.push_back(tmp);

        tmp.clear();
        tmp.push_back(-1);
        tmp.push_back(0);
        tmp.push_back(1);
        key.push_back(tmp);
    }

    bool check() {
        for (int i = 0; i < this->result.size(); i++)
            for (int j = 0; j < this->result[i].size(); j++)
                if (this->result[i][j] != this->key[i][j]) {
                    return false;
                }

        return true;
    }
};

int main()
{
    Test test;
    Solution solution;

    test.result = solution.threeSum(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
