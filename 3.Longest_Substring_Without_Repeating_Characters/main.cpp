#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int len = 0, start = -1;

        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            len = max(len, i - start);
        }

        return len;
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
    //Test test("abcabcbb", 3);
    Test test("pwwkew", 3);
    Solution solution;

    test.result = solution.lengthOfLongestSubstring(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
