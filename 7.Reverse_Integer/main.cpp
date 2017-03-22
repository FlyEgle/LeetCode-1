#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;

        while (x) {
            res = res * 10 + x % 10;
            x = x / 10;
        }

        return (res < INT_MIN || res > INT_MAX) ? 0 : res;
    }
};

class Test {
public:
    int input;
    int key;
    int result;

public:
    Test(int input, int key) : input(input) , key(key) {}

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
    Test test(123, 321);
    Solution solution;

    test.result = solution.reverse(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
