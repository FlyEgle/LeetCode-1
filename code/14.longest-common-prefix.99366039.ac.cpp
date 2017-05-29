/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix
 *
 * Easy (31.26%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
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
