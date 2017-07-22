/*
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words
 *
 * Hard (21.83%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 * 
 * 
 * 
 * You should return the indices: [0,9].
 * (order does not matter).
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> index;
        unordered_map<string, int> counts;

        for (string word : words)
            ++counts[word];

        int ns = s.length();
        int nwords = words.size();
        int len = words[0].length();

        for (int i = 0; i < ns - nwords * len + 1; ++i) {
            unordered_map<string, int> appear;
            int j = 0;
            for (; j < nwords; ++j) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    ++appear[word];
                    if (appear[word] > counts[word])
                        break;
                } else {
                    break;
                }
            }
            if (j == nwords)
                index.push_back(i);
        }

        return index;
    }
};
