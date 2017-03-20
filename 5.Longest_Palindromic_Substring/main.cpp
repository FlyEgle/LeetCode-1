#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Manacher's ALGORITHM */
class Solution {
public:
    string longestPalindrome(string s) {
        string str = "$#";
        for (int i = 0; i < s.length(); i++) {
            str += s[i];
            str += '#';
        }

        // Test
        cout << "str = " << str << endl;
        // End

        vector<int> p(2005, 0);
        int mx = 0, id = 0;

        for (int i = 1; i <= str.length(); i++) {
            p[i] = (mx > i) ? min(p[2 * id - i], mx - i) : 1;

            while (str[i + p[i]] == str[i - p[i]]) p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }

        // Test
        cout << "p[] = ";
        for (int i = 0; i < str.length(); i++)
            cout << p[i] << " ";
        cout << endl;
        // End

        int max = 0, index;
        for (int i = 1; i < str.length(); i++) {
            if (p[i] > max) {
                index = i;
                max = p[i];
            }
        }
        max--;

        int start = index - max;
        int end = index + max;
        string result = "";
        for (int i = start; i <= end; i++) {
            if (str[i] != '#') {
                result += str[i];
            }
        }

        vector<int>(p).swap(p);

        // Test
        cout << "max = " << max << ", index = " << index << endl;
        cout << "result = " << result << endl;
        // End

        return result;
    }
};

class Test {
public:
    string input;
    string key;
    string result;

public:
    Test(string input, string key) : input(input), key(key) {}

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
    Test test("cbbd", "bb");
    Solution solution;

    test.result = solution.longestPalindrome(test.input);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
