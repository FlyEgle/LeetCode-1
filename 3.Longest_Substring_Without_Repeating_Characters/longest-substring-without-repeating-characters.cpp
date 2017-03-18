/* 构建ASCii字符字典，保存对应字符最后一次出现的下标 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int len = 0, start = -1;

        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            len = max(len, i - start);
        }

        return len;
    }
};
