#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string M[] = {"", "M", "MM", "MMM"};

        string roman = M[num / 1000] +
                       C[(num % 1000) / 100] +
                       X[(num % 100) / 10] +
                       I[num % 10];

        return roman;
    }
};

class Test {
public:
    int input;
    string key;
    string result;

public:
    Test(int input, string key) : input(input), key(key) {}

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
    Test test(1, "I");
    Solution solution;

    test.result = solution.intToRoman(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
