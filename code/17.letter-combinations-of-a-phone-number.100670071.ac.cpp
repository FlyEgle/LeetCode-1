/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number
 *
 * Medium (33.80%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 * 
 * 
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 * 
 * 
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
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
