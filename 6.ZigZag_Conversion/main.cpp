#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> zigzag(numRows);
        int index = 0, length = s.length();

        while (index < length) {
            for (int i = 0; i < numRows; i++) {
                if (index >= length) break;
                zigzag[i] += s[index++];
            }
            for (int i = numRows - 2; i > 0; i--) {
                if (index >= length) break;
                zigzag[i] += s[index++];
            }
        }

        string result;
        for (int i = 0; i < zigzag.size(); i++) {
            result += zigzag[i];
        }

        return result;
    }
};

class Test {
public:
    string input;
    int nRows;
    string key;
    string result;

public:
    Test(string text, int nRows, string key) :
                input(text), nRows(nRows), key(key) {}

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
    Test test("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    Solution solution;

    test.result = solution.convert(test.input, test.nRows);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
