#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = {{'I', 1},
                                      {'V', 5},
                                      {'X', 10},
                                      {'L', 50},
                                      {'C', 100},
                                      {'D', 500},
                                      {'M', 1000} };

        int num = T[s.back()];
        for (int i = s.length() - 2; i >= 0; i--) {
            if (T[s[i]] < T[s[i + 1]])
                num -= T[s[i]];
            else
                num += T[s[i]];
        }

        return num;
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
    Test test("I", 1);
    Solution solution;

    test.result = solution.romanToInt(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
