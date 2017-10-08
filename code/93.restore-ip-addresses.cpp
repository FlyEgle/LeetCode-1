/*
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses
 *
 * algorithms
 * Medium (27.18%)
 * Total Accepted:    91.2K
 * Total Submissions: 330.1K
 * Testcase Example:  '"0000"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * 
 * For example:
 * Given "25525511135",
 * 
 * 
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 * 
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restore(s, 4, "", res);
        return res;
    }

private:
    void restore(string s, int k, string ctx, vector<string>& res) {
        if (k == 0) {
            if (s.empty()) res.push_back(ctx);
        } else {
            for (int i = 1; i <= 3; ++i) {
                if (s.length() >= i && isValid(s.substr(0, i))) {
                    if (k == 1)
                        restore(s.substr(i), k-1, ctx+s.substr(0, i), res);
                    else
                        restore(s.substr(i), k-1, ctx+s.substr(0, i)+'.', res);
                }
            }
        }
    }

    bool isValid(string s) {
        if (s.empty() || s.length() > 3 || (s.length() > 1 && s[0] == '0'))
            return false;
        int res = atoi(s.c_str());
        return 0 <= res && res <= 255;
    }
};
