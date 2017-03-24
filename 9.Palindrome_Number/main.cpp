#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;

        int sum = 0;
        while (x > sum) {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }

        return (x == sum) || (x == sum / 10);
    }
};

class Test {
public:
    int input;
    bool key;
    bool result;

public:
    Test(int input, bool key) : input(input), key(key) {}

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
    Test test(121, true);
    Solution solution;

    test.result = solution.isPalindrome(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
