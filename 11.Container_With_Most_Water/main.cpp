#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        int h;

        while (i < j) {
            h = min(height[i], height[j]);
            water = max(water, (j - i) * h);

            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }

        return water;
    }
};

class Test {
public:
    vector<int> input;
    int key;
    int result;

public:
    Test() {
        input.push_back(1);
        input.push_back(1);

        key = 1;
    }

    bool check() {
        bool flag;

        if (this->result == this->key)
            flag = true;
        else
            flag = false;
    }
};

int main()
{
    Test test;
    Solution solution;

    test.result = solution.maxArea(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
