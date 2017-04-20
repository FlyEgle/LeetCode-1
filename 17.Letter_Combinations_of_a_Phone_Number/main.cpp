#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();

        vector<string> res;
        res.push_back("");
        static const vector<string> map = {"", "", "abc", "def",
                                           "ghi", "jkl", "mno",
                                           "pqrs", "tuv", "wxyz"};

        for (int i = 0; i < digits.length(); i++) {
            int x = digits[i] - '0';

            string t = res.front();
            while (t.length() == i) {
                for (int j = 0; j < map[x].length(); j++) {
                    char s = map[x][j];
                    res.push_back(t + s);
                }

                res.erase(res.begin());
                t = res.front();
            }
        }

        return res;
    }
};

class Test {
public:
    string input;
    vector<string> result;
    vector<string> key;

public:
    Test() {
        input = "23";

        key.push_back("ad");
        key.push_back("ae");
        key.push_back("af");
        key.push_back("bd");
        key.push_back("be");
        key.push_back("bf");
        key.push_back("cd");
        key.push_back("ce");
        key.push_back("cf");
    }

    bool check() {
        for (int i = 0; i < this->result.size(); i++) {
                if (this->result[i] != this->key[i]) {
                    return false;
                }
        }

        return true;
    }
};

int main()
{
    Test test;
    Solution solution;

    test.result = solution.letterCombinations(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
