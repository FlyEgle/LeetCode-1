#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

class Test {
public:
    vector<int> nums1;
    vector<int> nums2;
    double key;
    double result;

public:
    Test() {
        /*
        this->nums1.push_back(1);
        this->nums1.push_back(3);

        this->nums2.push_back(2);

        this->key = 2.0;
        */

        this->nums1.push_back(1);
        this->nums1.push_back(2);

        this->nums2.push_back(3);
        this->nums2.push_back(4);

        this->key = 2.5;
    }

    bool check() {
        bool flag;

        if (this->result == this->key)
            flag = true;
        else
            flag = false;

        return flag;
    }
};

int main()
{
    Test test;
    Solution solution;

    test.result = solution.findMedianSortedArrays(test.nums1, test.nums2);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
