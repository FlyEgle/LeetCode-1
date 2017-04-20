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
