#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0, sign = 1;
        int i = str.find_first_not_of(' ');
        int base = INT_MAX / 10;

        if (str[i] == '+' || str[i] == '-')
            sign = (str[i++] == '+') ? 1 : -1;

        while (isdigit(str[i])) {
            if (result > base || (result == base && str[i] - '0' > 7))
                return sign > 0 ? INT_MAX : INT_MIN;
            result = result * 10 + (str[i++] - '0');
        }

        return sign * result;
    }
};

class Test {
public:
    string input;
    int key;
    int result;

public:
    Test(string input, int key) : input(input), key(key) {}

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
    Test test("1", 1);
    Solution solution;

    test.result = solution.myAtoi(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
