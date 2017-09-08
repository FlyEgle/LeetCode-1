/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path
 *
 * algorithms
 * Medium (25.13%)
 * Total Accepted:    93.1K
 * Total Submissions: 366.6K
 * Testcase Example:  '"/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * 
 * 
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 * 
 * 
 */
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string str;
        stringstream ss(path);

        while (getline(ss, str, '/')) {
            if ("" == str || "." == str) continue;
            if (".." == str && !st.empty()) st.pop_back();
            else if (".." != str) st.push_back(str);
        }

        string res;
        for (auto str : st)
            res += "/" + str;

        return res.empty() ? "/" : res;
    }
};
