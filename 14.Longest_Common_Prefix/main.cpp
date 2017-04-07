#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        for (int index = 0; strs.size() > 0; prefix += strs[0][index], index++)
            for (int i = 0; i < strs.size(); i++)
                if (index >= strs[i].length() ||
                    (i > 0 && strs[i][index] != strs[i - 1][index]))
                    return prefix;

        return prefix;
    }
};

class Test {
public:
    vector<string> input;
    string key;
    string result;

public:
    Test() {
        input.push_back("abc");
        input.push_back("abcd");
        input.push_back("abcde");
        input.push_back("abcdef");

        key = "abc";
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

    test.result = solution.longestCommonPrefix(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
