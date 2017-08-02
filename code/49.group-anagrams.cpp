/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams
 *
 * algorithms
 * Medium (34.40%)
 * Total Accepted:    140.9K
 * Total Submissions: 409.3K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note: All inputs will be in lower-case.
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> table;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            table[t].insert(s);
        }

        vector<vector<string>> res;
        for (auto t : table) {
            vector<string> temp(t.second.begin(), t.second.end());
            res.push_back(temp);
        }

        return res;
    }
};
