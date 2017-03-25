#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * f[i][j] : if s[0..i-1] matches p[0..j-1]
 *
 * if p[j-1] != '*'
 *      f[i][j] = f[i-1][j-1] && (s[i-1]==p[j-1] || '.'==p[j-1])
 * else
 *      f[i][j] = f[i][j-2] || (s[i-1]==p[j-2] || '.'==p[j-2]) && f[i-1][j]
 * */

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<vector<bool> > f(sLen + 1, vector<bool>(pLen + 1, false));

        // 预处理
        f[0][0] = true;
        for (int i = 1; i <= sLen; i++)
            f[i][0] = false;
        for (int j = 1; j <= pLen; j++)
            f[0][j] = j > 1 && ('*' == p[j - 1]) && f[0][j - 2];

        // 填表
        for (int i = 1; i <= sLen; i++)
            for (int j = 1; j <= pLen; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] &&
                              (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    f[i][j] = f[i][j - 2] ||
                              (s[i - 1] == p[j - 2] || '.' == p[j - 2]) &&
                              f[i - 1][j];

        // Test
        for (int i = 0; i <= sLen; i++) {
            for (int j = 0; j <= pLen; j++) {
                cout << f[i][j] << " ";
            }
            cout << endl;
        }
        // End

        return f[sLen][pLen];
    }
};

class Test {
public:
    string s;
    string p;
    bool key;
    bool result;

public:
    Test(string s, string p, bool key) : s(s), p(p), key(key) {}

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
    //Test test("aa", ".*", true);
    //Test test("abcd", "d*", false);
    Test test("aa", "a*", true);
    Solution solution;

    test.result = solution.isMatch(test.s, test.p);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
