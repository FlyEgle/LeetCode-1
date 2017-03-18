#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* O(n^2) */
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }

        return result;
    }
};
*/

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

class Test {
public:
    vector<int> nums;
    int target;
    vector<int> key;
    vector<int> result;

public:
    Test() {
        this->nums.push_back(-3);
        this->nums.push_back(4);
        this->nums.push_back(3);
        this->nums.push_back(90);

        this->target = 0;

        this->key.push_back(0);
        this->key.push_back(2);
    }

    bool check() {
        bool flag = true;

        for (int i = 0; i < this->result.size(); i++) {
            if (this->result[i] != this->key[i]) {
                flag = false;
                break;
            }
        }

        return flag;
    }

    /*
    static void printer(const int& val)
    {
        cout << val << endl;
    }

    void printResult() {
        for_each(this->result.begin(), this->result.end(), printer);
    }
    */
};

int main()
{
    Test test;
    Solution solution;

    test.result = solution.twoSum(test.nums, test.target);

    //test.printResult();

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
